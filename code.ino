#include <alpha.h>

const int dataPin = 2;
const int clockPin = 4;
const int latchPin = 3;
const int arraySize=8;
int hold,temp[8]={};
char **container[] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, _}; //this is from where we can easily index every character

int getindex(char val){
    return val == ' '?26:tolower(val) - 'a';
}

void getmatrixleds(char **data){
    for(size_t i=0; i<8; i++){
       temp[i]=atoi(data[i]);
    }
    DISP(temp);
}

char *str = {"LED MATRIX "}; 

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   size_t string_length = strlen(str);
    for(int i=0; i<string_length; i++){
//        printf("\n\n%c's index is : %d\n\n",str[i], getindex(str[i]));
//        //hence now printing the assigned array to it(in LED MATRIX);;
//        printf("The assigned LED Matrx leds are: \n");
          getmatrixleds(container[getindex(str[i])]);
    }
    //     if(Serial.available()){                  //to give input from serial moniter and display in LED_MATRIX, uncomment this portion and comment out the above portion
    //     char val=Serial.read();       
    //     getmatrixleds(container[getindex(val)]);
    // }

}
void updateShiftRegister(byte data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, data);
}

void DISP(int alpha[]){
    long int instant=millis();
  while(millis()-instant<500){
  for (int i = 0; i < 8; i++) {
    updateShiftRegister(128>>i);
    updateShiftRegister(~(alpha[i]));
    digitalWrite(latchPin, HIGH); 
    }
   }
    instant=millis();
   while(millis()-instant<50){
    updateShiftRegister(0);
    updateShiftRegister(0);
    digitalWrite(latchPin, HIGH); 
    }
   }
