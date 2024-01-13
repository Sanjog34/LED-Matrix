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


void DISP(char alpha[]){
    long int instant=millis();
  while(millis()-instant<=500){
  for (int i = 0; i < 8; i++) {
    updateShiftRegister(128>>i);
    updateShiftRegister((alpha[i]));
    digitalWrite(latchPin, HIGH); 
    }
   }
}
