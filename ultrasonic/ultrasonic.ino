// C++ code
//
#include "Adafruit_LEDBackpack.h"

#include <Adafruit_LiquidCrystal.h>

int ultrasonic = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Adafruit_7segment led_display1 = Adafruit_7segment();

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  Serial.begin(9600);
  led_display1.begin(112);
  lcd_1.begin(16, 2);
}

void loop()
{
  ultrasonic = 0.01723 * readUltrasonicDistance(5, 4);
  Serial.println(ultrasonic);
  lcd_1.print(ultrasonic);
  delay(1000); // Wait for 1000 millisecond(s)
  lcd_1.clear();
}