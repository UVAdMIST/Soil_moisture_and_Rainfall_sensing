# UVAHydroInformatics
The goal of this project was to make a cheap device that could aggregate and post stormwater data (soil moisture and rainfall) online. This data could then be used for analysis of a catchment area or to automatically open up active draining systems.

There were three hardware tools used: Arduino Uno, soil moisture probe, and radio transmitters.

# Arduino Uno 
Arduinos are cheap, programmable circuits that are the backbone of projects like these (https://www.arduino.cc/)
# Soil Moisture probe
The soil moisture probes we used were Wingoneer YL-69 Sensor and HC-38 Module: (https://www.amazon.com/gp/product/B01H6WK51I/ref=oh_aui_detailpage_o04_s00?ie=UTF8&psc=1). These are cheap and not durable however a good starting point. The module is the rectangle and connects to the Arduino with three wires: one for voltage, one for ground, and one for either analog or digital data sending.
# Radio Transmitter 
Paires of NRF24L01 transmitters were used to send and receive data (primarily collected soil-moisture data). This required importing importing a library into the Arduino IDE for programming the Arduino Uno. The library is 
# For posting data on a server, calls were made using the Blynk Library (made by a team at MIT) which requires importing their library as well.
