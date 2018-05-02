# UVAHydroInformatics
The goal of this project was to make a cheap device that could aggregate and post stormwater data (soil moisture and rainfall) online. This data could then be used for analysis of a catchment area or to automatically open up active draining systems. Open the "UVAHydroinformatics.pdf" to see a more visual presentation for the course of the project.

There were three hardware tools used: Arduino Unos, soil moisture probe, and radio transmitters.

# Arduino Uno 
Arduinos are cheap, programmable circuits that are the backbone of projects like these (https://www.arduino.cc/)

# Soil Moisture probe
The soil moisture probes we used were Wingoneer YL-69 Sensor and HC-38 Module: (https://www.amazon.com/gp/product/B01H6WK51I/ref=oh_aui_detailpage_o04_s00?ie=UTF8&psc=1). These are cheap and not durable however a good starting point. The module is the rectangle and connects to the Arduino with three wires: one for voltage, one for ground, and one for either analog or digital data sending.

# Radio Transmitter 
Paires of NRF24L01 transmitters (https://www.amazon.com/Makerfire-Arduino-NRF24L01-Wireless-Transceiver/dp/B00O9O868G/ref=sr_1_3?s=electronics&ie=UTF8&qid=1524843556&sr=1-3&keywords=nrf24l01) were used to send and receive data (primarily collected soil-moisture data). This required importing importing a library into the Arduino IDE for programming the Arduino Uno. The library is located here: https://github.com/nRF24/RF24 . 

# Setup
A soil moisture probe, transmitter, and Arduino Uno were stored in a plastic container and placed in a garden. The soil moisture probe was placed in the soil. This portion of the setup was battery powered. 

Another arduino uno and a receiver were located nearby connected to a computer. This is where the data was received in defined intervals of time and posted to a cloud server. 

# Other libaries needed
For posting data on a server, calls were made using the Blynk Library (made by a team at MIT: https://www.blynk.cc/) which required importing their library as well. Blynk has an app which hosts a bunch of "widgets" for users to integrate into their projects. The main widget we used was the history graph which plots sent number data over time and can be exported to CSV format (for Excel). To use the Blynk API, you must create a project and generate an authentication token which is put into the code programmed on the Arduino.

# Tipping Bucket Rainfall Measurement
The tipping bucket project used a similar setup to the moisture probe arduino system, with a tipping bucket replacing the probe itself.  Each "tip" of the bucket is 0.1 inch of rainfall, which can be added up to measure the volume and intensity of a rainfall event.  The code was intended to measure every 30 milliseconds to capture each tip without measuring it twice, adding the number of tips until the timer reset (1 hour without tipping).  We ran into a few issues with the logic of the programming, mainly that the delay function fired much faster than we intended.  This caused the system to time out very rapidly, and the rainfall amounts would reset within a fraction of a second.  With minor debugging, this program could effectively be paired with the soil moisture sensors to correlate rainfall with trends in soil moisture.  

# Conclusions
The project was overall successfull. Soil moisture data was collected and posted on the Blynk-server. This was demoed at the UVA SEAS openhouse. The three main problems were: 
1. The batteries died within two weeks. This is likely due to the amount of radio transmissions which were occuring every 30 seconds. This was mainly because we were testing the setup worked as sometimes the radios lost communication and the blynk-server timed out of its connection. 
2. The accuracy of the data collected is questionable. We calibrated the device oursevles using the arduino .map() function (puts integer data into percentage based on two sets of defined ranges). However, these probes were very cheap and not built for exact data measurement. Overall though, the probes still prove useful for getting trends of stormwater overtime, just the accuracy of each point on the graph might be slighty above or below the actual moisture.
3. Radio transmission range was short (50 feet or lower if brick walls in the way). This range was boosted by soldering antennas onto the NRFs.


This is a doable and useful project that only cost around $20. This project could be expanded & improved in many ways to better monitor stormwater patterns.

If you are working on this project or a related one and have questions about wiring, feel free to ask me evan.lesmez@gmail.com
