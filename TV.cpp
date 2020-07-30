#include "MyIR.h"
#include <IRremoteESP8266.h>
#include <IRsend.h>
void TV_power(int ledPin);
void vol_down(int ledPin);
void vol_up(int ledPin);

void TV_op(int ledPin, String* tokens, int len){
	if(len != 1){
		Serial.println("invalid op");
		return;
	}
	
	IRsend irsend(ledPin);
	if(tokens[0] == "on" or tokens[0] == "off" or tokens[0] =="power"){
		TV_power(ledPin);
	}
	else if(tokens[0] =="0"){
		irsend.sendNEC(557632563, 32);
	}
	else if(tokens[0] =="1"){
		irsend.sendNEC(557583603, 32);
	}
	else if(tokens[0] =="2"){
		irsend.sendNEC(557618283, 32);
	}
	else if(tokens[0] =="3"){
		irsend.sendNEC(557620323, 32);
	}
	else if(tokens[0] =="4"){
		irsend.sendNEC(557585643, 32);
	}
	else if(tokens[0] =="5"){
		irsend.sendNEC(557581563, 32);
	}
	else if(tokens[0] =="6"){
		irsend.sendNEC(557587683, 32);
	}
	else if(tokens[0] =="7"){
		irsend.sendNEC(557599923, 32);
	}
	else if(tokens[0] =="8"){
		irsend.sendNEC(557601963, 32);
	}
	else if(tokens[0] =="9"){
		irsend.sendNEC(557597883, 32);
	}
	else if(tokens[0] == "question"){
		irsend.sendNEC(557593803, 32);
	}
	else if(tokens[0] =="ch+"){
		irsend.sendNEC(557624403, 32);
	}
	else if(tokens[0] =="ch-"){
		irsend.sendNEC(557640723, 32);
	}
	else if(tokens[0] =="vol+"){
		vol_up(ledPin);
	}
	else if(tokens[0] =="vol-"){
		vol_down(ledPin);
	}
	else if(tokens[0] =="yes"){
		irsend.sendNEC(557614203, 32);
	}
	else if(tokens[0] =="right"){
		irsend.sendNEC(557636643, 32);
	}
	else if(tokens[0] =="left"){
		irsend.sendNEC(557591763, 32);
	}
	else if(tokens[0] =="up"){
		irsend.sendNEC(557634603, 32);
	}
	else if(tokens[0] =="down"){
		irsend.sendNEC(557589723, 32);
	}
	else if(tokens[0] =="return"){
		irsend.sendNEC(557604003, 32);
	}
}


void TV_power(int ledPin){
	pulseIR(4500, ledPin);
	delayMicroseconds(4500);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(562);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	delayMicroseconds(1687);
	pulseIR(562, ledPin);
	
}

void vol_up(int ledPin){
	pulseIR(4400, ledPin);
	delayMicroseconds(4350);
	pulseIR(600, ledPin);
	delayMicroseconds(1600);
	pulseIR(600, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(1600);
	pulseIR(600, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1600);
	pulseIR(600, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
}

void vol_down(int ledPin){
	pulseIR(4400, ledPin);
	delayMicroseconds(4400);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(600, ledPin);
	delayMicroseconds(1600);
	pulseIR(600, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(500);
	pulseIR(600, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(550);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
	delayMicroseconds(1650);
	pulseIR(550, ledPin);
}

