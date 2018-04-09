

// Radio stuff
#include <SPI.h>  //Useful libraries
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN 
const byte address[6] = "00001";  // Common to all radio nodes 
/* --------------------------- */
//Blynk stuff
#include <SoftwareSerial.h>
#include <BlynkSimpleStream.h>
char auth[] = "0da1e194ddff4d6aa9ca80a478a50fdb";
int blynk_val;

//C:\Users\evanl\Documents\Arduino\libraries\Blynk\scripts blynk-ser.bat -c COM9

BlynkTimer timer;
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.

int val = 0;
void myTimerEvent()

{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, blynk_val);
}

void setup() {
  // put your setup code here, to run once:
  radio.begin();
  radio.openReadingPipe(0, address);  // Start listening on channel
  radio.setPALevel(RF24_PA_MAX);  // Options: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
  radio.setChannel(108); // 2.508 Ghz above wifi channels
  radio.startListening();   // Begin listening
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  timer.setInterval(1000L, myTimerEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (radio.available()) {
      // Define value for data to be received (soil moisture for ex.)
    radio.read(&val, sizeof(val));  // Read it
    blynk_val = val;
   
    
}
timer.run(); // Initiates BlynkTimer
Blynk.run();
}


