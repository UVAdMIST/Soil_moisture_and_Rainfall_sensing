/* Evan Lesmez */ 

#include <nRF24L01.h> // Useful libraries 
#include <RF24.h>
#include <SPI.h>
int i = 0; //For counting during setup

RF24 radio(7, 8);   // CE, CSN These are the important pins for some reason
const byte address[6] = "00001";  //Common between nodes on system


void setup() {
  radio.begin();  
  radio.openWritingPipe(address);   // Start sending on channel
  radio.setPALevel(RF24_PA_MAX);  // Options: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
  radio.setChannel(108); //2.508 Ghz - above wifi channels
  radio.stopListening();  // Don't listen b/c sending
  //Serial.begin(9600);
}

void loop() {
  int soilMoist = analogRead(A0);   //Read soil moisture probe
  /*Serial.print("Raw ");
  Serial.print(soilMoist);*/
  soilMoist = map(soilMoist,1023,341,0,100);// Change it to percent
  radio.write(&soilMoist, sizeof(soilMoist));   //send this on radio
  /*Serial.print(" mapped ");
  Serial.println(soilMoist);*/
  delay(1000); //milis
}
