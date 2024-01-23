#include <SoftwareSerial.h>
#include <String.h>
int rx=4;
int tx=5;
SoftwareSerial xbee (rx,tx);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xbee.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
//  for (int i=0;i<100;i++){
//    xbee.write(i);
//    Serial.println(i);
//    delay(1000);
//  }
  xbee.write(10);
    Serial.println(10);
    delay(1000);
  
}
