

#include "Arduino.h"


int tokenize(String* output_array, String str);
void pulseIR(long microsecs, int ledPin);
void IR_transmit(int ledPin, String data, long start_on, long start_off, long bit1_on, long bit1_off, long bit0_on, long bit0_off, long stop_on);

// AC functions
//void AC_transmit(int ledPin, bool ON, int temp, int fan, ModeType mode, bool swing);
void AC_op(int ledPin, String* tokens, int len);

//TV functions
void TV_op(int ledPin, String* tokens, int len);