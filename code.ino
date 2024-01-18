#include <alpha.h>
const int dataPin = 2;
const int clockPin = 4;
const int latchPin = 3;

void setup() {
}

void loop() {
  DISP(S);
  DISP(A);
  DISP(N);
  DISP(J);
  DISP(O);
  DISP(G);
}
void updateShiftRegister(byte data){
digitalWrite(latchPin,LOW);
shiftWrite(dataPin,clockPin,LSBFIRST,data);
}

void DISP(int alpha[]){
    long int instant=millis();
  while(millis()-instant<=500){//display each character for 500ms
  for (int i = 0; i < 8; i++) {//display one out of 8 rows at a time. Doing it sufficiently fast gives a picture of character in the matrix.
    updateShiftRegister(128>>i);
    updateShiftRegister(~(alpha[i]));
    digitalWrite(latchPin, HIGH); 
    }
   }
}
