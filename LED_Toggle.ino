#include <Wire.h>
#include <MicroView.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
int state0 = 0;
int state1 = 0;
int state2 = 0;

void setup() {
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    Serial.begin(9600);         	// start serial for output
    Wire.begin(SLAVE_ADDRESS);		// initialize i2c as slave
    Wire.onReceive(receiveData);	// define callbacks for i2c communication

    Serial.println("Ready!");
}

void loop() {
    delay(100);
}

// callback for received data
void receiveData(int byteCount){

    while(Wire.available()) {
        number = Wire.read();
        Serial.print("data received: ");
        Serial.println(number);
       
        if (Wire.available() > 1)  // at least 2 bytes
        {
          number = Wire.read() * 256 + Wire.read();
        }
        if (number == 1) {
          if (state0 == 0){
            digitalWrite(A0, HIGH);
            state0 = 1;
          }
          else {
            digitalWrite(A0, LOW);
            state0 = 0;
          }
        }
        if (number == 2) {
            if (state1 == 0){
              digitalWrite(A1, HIGH);
              state1 = 1;
            }
            else {
              digitalWrite(A1, LOW);
              state1 = 0;
            }
        }        
        if (number == 3) {
            if (state2 == 0){
              digitalWrite(A2, HIGH);
              state2 = 1;
            }
            else {
              digitalWrite(A2, LOW);
              state2 = 0;
            }
        }        
        {
          uView.begin();        // start MicroView
          uView.clear(PAGE);    // clear page
          uView.print(number);
          uView.display();
        }
        
    }
}
