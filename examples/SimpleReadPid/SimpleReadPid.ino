#include <elm.h>

byte serialRX = 9;  // RX pin
byte serialTX = 10; // TX pin
ELM myELM(serialRX, serialTX);

void setup() {
  // initialize ELM's connection at 9600 baud
  int UARTbaud = 9600;
  myELM.begin(UARTbaud);
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
  Serial.println("The value of " + myDescription + " is " + myValue + " "  + myUnit); 
}
