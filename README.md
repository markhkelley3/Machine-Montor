# Machine-Montor
I am building a program to monitor via wifi the state of a machine.
 Specifically:
 Through a wifi connection via an Arduino UNO WIFI Rev. 2
 I want to setup a server on the arduino that will present the status of the machine:
 Condition 1 - Machine is powered on (Easy, if arduino is on, Machine is on)
 Condition 2 - Monitoring an input for state change, 
                if it goes "HIGH" set a status through WIFI that the motor is running.
                if it goes "LOW" set a staus through WIFI that the motor has stopped.
                  ** This particular input will be 5V routed through an auxilliary contact on a Motor Relay **

I need to be able to update the status real time on the arduino based server.

Thanks,
Mark
