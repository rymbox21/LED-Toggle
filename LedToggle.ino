#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int num = 0;
int state = 0;
int state0 = 0;
int state1 = 0;
int state2 = 0;

void setup() {
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    Serial.begin(9600);             // start serial for output
    Wire.begin(SLAVE_ADDRESS);      // join i2c bus with address
    Wire.onReceive(receiveEvent);   // register event
    Serial.println("Ready!");
}

void loop() {
    delay(100);
}

//Change LED state 
int toggle (int state, int LED){
  if (state == 0){
    digitalWrite(LED, HIGH);
    state = 1;
    return state;
  }
  else {
    digitalWrite(LED, LOW);
    state =  0;
    return state;
  }
}

void receiveEvent(int byteCount) {
  
  while (Wire.available()) {          
    num = Wire.read();                // receive byte 
    Serial.print("data received: ");  // print the received
    Serial.println(num);
  //Receives which LED to toogle from user
  if (num == 1) {
    int LED1 = A0;
    state0 = toggle (state0, LED1) ;
  }
  if (num == 2) {
    int LED2 = A1;
    state1 = toggle (state1, LED2) ;
  }
  if (num == 3) {
    int LED3 = A2;
    state2 = toggle (state2, LED3) ;
  }
  }
}
