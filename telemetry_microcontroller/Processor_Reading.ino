#include <Printers.h>
#include <XBee.h>
#include <SoftwareSerial.h>
#include <String.h>

int rx=4;
int tx=5;
String a = " ";
SoftwareSerial Xbee (rx,tx);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  XBee xbee = XBee();
  XBeeResponse response = XBeeResponse();
  xbee.begin(XBee);
}

void loop() {
  // put your main code here, to run repeatedly:
    a = xbee.read();
    Serial.println(a);
    delay(1000);
}
