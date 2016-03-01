#include <elm.h>

ELM myELM;

void setup() {
  // initialize ELM's connection
  int serialRX = 9; // RX pin
  int serialTX = 10; // TX pin
  myELM.begin(serialRX, serialTX);
  // initialize serial and wait for port to open
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
}

void loop() {
  // define a pid
  byte pid = 0x05;
  // read pid data, unit and description
  String myValue = myELM.get_pid_data(pid);
  String myDescription = myELM.get_pid_desc(pid);
  String myUnit = myELM.get_pid_unit(pid);
  // print to serial monitor
  Serial.println("The value of " + myDesc + " is " + myValue + " "  + myUnit); 
}
