#include <SoftwareSerial.h>
#include <XBee.h>

SoftwareSerial soft(4,5);// RX, TX -> XBee Serial
XBee xbee = XBee();
XBeeResponse response = XBeeResponse();

// create reusable response objects for responses we expect to handle 
ZBRxResponse rx = ZBRxResponse();

void setup() {
 
  // start serial
  soft.begin(9600);   // Initialize serial port XBee
  Serial.begin(9600); // Initialize serial port PC
  xbee.setSerial(soft);
  Serial.println("Starting up!");
}

// continuously reads packets, looking for ZB Receive or Modem Status
void loop() {
    char byte;
    if(soft.available()>0){
      byte = soft.read();
    }
    Serial.println(byte,HEX);
}
