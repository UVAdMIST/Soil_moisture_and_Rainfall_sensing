
const int buttonPin = 6;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
float rain = 0;  // To add rainfall inches to
int timeout = 0; // Should be an hour for light rain intensity (.098 inches per hour)
int dlay = 25;

#include <SPI.h>  // Radio Stuff
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";


void setup() {

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {   // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    rain += .1; 
    timeout = 0;
    radio.write(&rain, sizeof(rain));   //send this on radio
  } else {
    timeout += 1;
  }
  if (timeout >= 60*60*1000/dlay){  // Formula for hour timeout = 60*60*1000/dlay
    rain = 0;
    radio.write(&rain, sizeof(rain));
    timeout = 0;
    } 
  
  delay(dlay);
}
