/*

  Machine State Monitor - 
  Used to monitor the state of Machine Motor Contactor
  *******************************************************
  *  
  *  This project designed to monitor an input (pin 7);  *
  * If pin 7 goes high, set a bit (RelayOn) to true      *
  * Also included with the code is a power indicator bit *
  * which is being used to alert the system that the     *
  * machine is powered, so that it alerts the monitoring *
  * software to begin watching for (relayOn) to become   *
  * True (on), at which point the monitoring software    *
  * will start the clock for this machine hour tally     *
  *                                                      *
  * ******************************************************

  Use this site for monitoring switch state
  https://www.homemade-circuits.com/monitoring-state-of-switch-digital-read/
  
   Flex Inc. 
   Test Lab Machine Hours Monitor
   When Circulation Pump Contactor is pulled in (on) we send 
   a signal to drive an input high. We mirror that input to an output 
   which will be monitored by the Labview software written for this
   purpose.
   By Mark Kelley / Ritchie Baje

   **************************************************************************************
   *            Version History                                                         *  
   *  1.0 - Initial writing of basic concept                                            *
   *  1.1 - Developed if else statement to monitor machine contactor and set bit HIGH   *             
   *        Once bit is set high, continue to monitor for state change in machine power *
   *        1/19/2021                                                                   *
   *  1.2 - Added Serial Print command to monitor bit through Serial Port               *
   *                                                                                    *
   *                                                                                    *
   *  ***********************************************************************************      
*/

// ******************** This is the place to call your libraries ************************
// *                                                                                    *
// **************************************************************************************


// ****************This is the place to setup your variables ****************************
// **************************************************************************************

int dt1=500;
int led=13;                                   //Power On indicator
int relayOn=10;                               //Motor On bit
int contactOn=7;                               // Contact Closed Bit

// **************** Setup Pin States Here **********************************************
// * Also setup things like serial communication, etc.                                 *
// *************************************************************************************
void setup() {

      Serial.begin(9600);                     //initialize Serial Monitor
          pinMode(contactOn, INPUT);          //pin to monitor
          pinMode(relayOn, OUTPUT);           // Motor On Bit
          pinMode(led, OUTPUT);               // Power On Bit
}

// ***************************** Main Program Go Here ************************************
// *  These code pieces get executed over and over again as long as board is powered  ****
// ***************************************************************************************

void loop() {

if(contactOn==HIGH) {                         // Is pin 10 HIGH?
   digitalWrite(relayOn, HIGH);               // Set pin 10 to HIGH
   Serial.println(" Motor Running");          // Print message to Serial Port "Motor Running"
}
    else{digitalWrite(relayOn, LOW);          // Set pin 10 to LOW
    Serial.println(" Motor Off");             // Print Message that the "Motor is Off"
    delay(dt1);                               // Time Delay for Serial Display
}
   poweron();                                 // Turns on LED on Pin 13 when board is powered up.

 }


// *************************** Subroutines go here ****************************************
// *   The Code listed below only gets executed when called from the main loop         ****
// ****************************************************************************************
  void poweron(){
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
