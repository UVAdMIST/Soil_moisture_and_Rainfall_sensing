#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
float val = 0.00;

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW); // Options: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
  radio.startListening();
}
void loop() {
  if (radio.available()) {
      // Define value for data to be received (soil moisture for ex.)
    radio.read(&val, sizeof(val));  // Read it
    Serial.println(val);
  }
}

