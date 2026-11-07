#include <NewPing.h>

#define trig 11
#define echo 12
#define MAX_distance 400
NewPing sonic(trig , echo, MAX_distance);
int distance;
void setup() {
  // put your setup code here, to run once:
pinMode(13,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
distance = sonic.ping_cm();
if(distance <= 15 && distance > 10){
  digitalWrite(13, HIGH);
  delay(1000); 
}
if(distance <= 10 && distance > 5){
  digitalWrite(13, HIGH);
  delay(1000); 
}
if(distance <= 2)
 digitalWrite(13, HIGH);
 else
  digitalWrite(13, LOW);
}
