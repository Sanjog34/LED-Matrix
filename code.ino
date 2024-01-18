#include <alpha.h>

const int dataPin = 2;
const int clockPin = 4;
const int latchPin = 3;
const int arraySize=8;
const int numArrays=50;
int hold,temp[8]={};
void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 const char** stringArrays[numArrays] = {S,A,N,J,O,G,_,S,A,P,K,O,T,A,_};
  convert(stringArrays);    
}  


void updateShiftRegister(byte data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, data); 
}

void DISP(int alpha[]){
    long int instant=millis();
  while(millis()-instant<=500){
  for (int i = 0; i < 8; i++) {
    updateShiftRegister(128>>i);
    updateShiftRegister(~(alpha[i]));
    digitalWrite(latchPin, HIGH); 
    }
   }
}
void convert(char** stringArrays[numArrays]){
  for (int i = 0; stringArrays[i]!=NULL; ++i) {
    for (int j = 0; j < arraySize; ++j) {
        hold=atoi(stringArrays[i][j]);
        temp[j]=hold;
//      Serial.println(stringArrays[i][j]);
    }
    DISP(temp);
  }
  }
