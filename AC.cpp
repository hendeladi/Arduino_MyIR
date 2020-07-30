#include "MyIR.h"

typedef enum ModeType{
	cold = 1,
	hot = 2,
	fanning = 3,
	wet = 4,
	A = 5
}ModeType;


// global default parameters for AC
//bool global_ON = false;
int global_temp = 26;
int global_fan = 1;
ModeType global_mode = cold;
bool global_swing = false;


String toBinary(uint8_t n){
	String r;
	for (int i = 0; i < 8; i++) {
		r = (n % 2 == 0 ? "0" : "1") + r; 
		n /= 2; 
	}
	return r;
}

int compute_checksum(int sum){
	int running_sum = sum;
	int mod15 = sum%15;
	int div16 = sum/16;
	int thresh = 23 + div16 - 7;
	while(running_sum > thresh){
		running_sum -= 15;
	}
	return running_sum;
}

uint8_t reverse_byte(uint8_t byte) {
	uint8_t reversed = 0;
	reversed += (byte & 1) << 7;
	reversed += (byte & 2) << 5;
	reversed += (byte & 4) << 3;
	reversed += (byte & 8) << 1;
	reversed += (byte & 16) >> 1;
	reversed += (byte & 32) >> 3;
	reversed += (byte & 64) >> 5;
	reversed += (byte & 128) >> 7;
	return reversed;
}

void AC_transmit(int ledPin, bool ON, int temp, int fan, ModeType mode, bool swing) {
	Serial.println("pulse");
	uint8_t byte1 = 1;
	uint8_t byte2 = int(mode) + (fan << 4);
	uint8_t byte3 = temp << 1;
	uint8_t byte4 = 0;
	uint8_t byte5 = 0;
	uint8_t byte6 = (ON) ? 48 : 192;
	uint8_t byte7 = (swing) ? 192 : 0;
	int sum = int(byte1 + byte2 + byte3 + byte4 + byte5 + byte6 + byte7);
	int checksum = compute_checksum(sum);
	uint8_t byte8 = uint8_t(checksum);
	
	
	String sequence = toBinary(reverse_byte(byte1));
	sequence += toBinary(reverse_byte(byte2));
	sequence += toBinary(reverse_byte(byte3));
	sequence += toBinary(reverse_byte(byte4));
	sequence += toBinary(reverse_byte(byte5));
	sequence += toBinary(reverse_byte(byte6));
	sequence += toBinary(reverse_byte(byte7));
	sequence += toBinary(reverse_byte(byte8));
	IR_transmit(ledPin, sequence, 8000, 4250, 1700, 600, 600, 1700, 1650);
}

void AC_op(int ledPin, String* tokens, int len){
	bool ON = true;
	int temp = global_temp ;
	int fan = global_fan;
	ModeType mode = global_mode;
	bool swing = global_swing;
	
	
	int i = 0;
	while(i<len){
		Serial.println(tokens[i]);
		if(tokens[i] == "on"){
			ON = true;
			i+=1;
		}
		else if(tokens[i]=="off"){
			ON = false;
			i+=1;
		}
		else if(tokens[i] == "temperature"){
			temp = int(tokens[i+1].toInt());
			global_temp = temp;
			i+=2;
		}
		else if(tokens[i]=="fan"){
			fan = int(tokens[i+1].toInt());
			global_fan = fan;
			i+=2;
		}
		else if(tokens[i]=="mode"){
			if(tokens[i+1]=="cold"){
				mode = cold;
			}
			else if(tokens[i+1]=="hot"){
				mode = hot;
			}
			else if(tokens[i+1]=="fanning"){
				mode = fanning;
			}
			else if(tokens[i+1]=="wet"){
				mode = wet;
			}
			else if(tokens[i+1]=="A"){
				mode = A;
			}
			global_mode = mode;
			i+=2;
		}
		else if(tokens[i]=="swing"){
			if(tokens[i+1]=="true"){
				swing = true;
			}
			else if(tokens[i+1] == false){
				swing = false;
			}
			global_swing = swing;
			i+=2;
		}
		else{
			i+=1;
		}
	}
	Serial.println("==== in AC_transmit =====");
	Serial.print("ON = ");
	Serial.println(ON);
	Serial.print("temp = ");
	Serial.println(temp);
	Serial.print("fan = ");
	Serial.println(fan);
	Serial.print("mode = ");
	Serial.println(mode);
	Serial.print("swing = ");
	Serial.println(swing);
	
	AC_transmit(ledPin, ON, temp, fan, mode, swing);
}

