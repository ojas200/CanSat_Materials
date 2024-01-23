#include <SoftwareSerial.h>
#include <String.h>
int rx=4;
int tx=5;
SoftwareSerial xbee (rx,tx);
int tt=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xbee.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int t = 1095;
  int pac = random(40,100);
  char md[5] = "N";
  char st[15] = "ASCENDING";

  char packet[150] = {};
  char TEAMID[10] = {};
  char COUNT[5] = {};
  char TIME[5] = {};
  
  dtostrf(t,4,0,TEAMID);

  strcat(packet,TEAMID);
  strcat(packet,", ");
  dtostrf(tt,2,0,TIME);
  strcat(packet,TIME);
  strcat(packet,", ");
  dtostrf(pac,2,0,COUNT);
  strcat(packet,COUNT);
  strcat(packet,", ");
  strcat(packet,md);
  strcat(packet,", ");
  strcat(packet,st);
  strcat(packet,", ");
  strcat(packet,"$"); //This sign is added to find the end of packet in case of packet collisions.

  Serial.println(packet);
  xbee.write(packet);
  tt++;
  delay(1000);
  
}
