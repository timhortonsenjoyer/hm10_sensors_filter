# Object Location Using BLE Modules and Arduino
The goal of this project was to use a Bayesian Filter to get the location of an object (the Arduino) as it pings different Bluetooth modules. The time of response of each ping is measured, and from this the distance is calculated per module. The 4 modules' outputs are then fused in a Bayesian Filter to output a probabilistic heat map of the object's location in a given space, with the hottest region representing the highest probability. 

Important to Note: The HM10 modules may not work directly out of the box, if so then they need to be configured first by sending it a Serial Terminal command to change its Mode. 
