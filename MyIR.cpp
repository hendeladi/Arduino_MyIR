

#include "MyIR.h"



void pulseIR(long microsecs, int ledPin){
	cli(); // this turns off any background interrupts
	while (microsecs > 0) {
	digitalWrite(ledPin, HIGH); // this takes about 3 microseconds to happen
	delayMicroseconds(10); // hang out for 10 microseconds
	digitalWrite(ledPin, LOW); // this also takes about 3 microseconds
	delayMicroseconds(10); // hang out for 10 microseconds
	microsecs -= 26;
	}
	sei(); // this turns them back on
}


void IR_transmit(int ledPin, String data, long start_on, long start_off, long bit1_on, long bit1_off, long bit0_on, long bit0_off, long stop_on){
	pulseIR(start_on, ledPin); 
	delayMicroseconds(start_off);
	for(int i = 0; i < data.length(); i++){
		if(String(data[i]) ==  String("1")){
			
			pulseIR(bit1_on, ledPin);
			delayMicroseconds(bit1_off);
		}
		else{
			pulseIR(bit0_on, ledPin);
			delayMicroseconds(bit0_off);
		}
	}
	pulseIR(stop_on, ledPin); 
}

/*
int tokenize(String* output_array, String str){
  char charArray[str.length()+1];
  str.toCharArray(charArray, str.length()+1);
  output_array[0] = String(strtok(charArray, " ")); 
  int i=0;
  while (output_array[i] != NULL) {
    i++;
    output_array[i] = String(strtok(NULL, " "));
  }
  return i;
}
*/





