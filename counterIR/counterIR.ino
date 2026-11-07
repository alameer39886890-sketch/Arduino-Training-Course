#include <Wire.h>
 #include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27, 16, 2);
 int turnCounter = 0;      
int sensorPin = A0;       
int buzzerPin = 8;        
int sensorValue = 0;      
int threshold = 800;      
 bool isTurnDetected = false;  
void setup() {
lcd.init();
 lcd.backlight();
 pinMode(buzzerPin, OUTPUT);
 lcd.setCursor(0, 0);
lcd.print("Counter Ready");
 lcd.setCursor(0, 1); 
lcd.print("Turns: 0");
 } 
void loop() {
 sensorValue = analogRead(sensorPin);
  if (sensorValue > threshold && isTurnDetected == false) {
    
    turnCounter = turnCounter + 1;
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW); 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Counting...");
    lcd.setCursor(0, 1);
    lcd.print("Turns: " + String(turnCounter));
    if (turnCounter % 15 == 0) {
      digitalWrite(buzzerPin, HIGH); 
      delay(1000);                   
      digitalWrite(buzzerPin, LOW);  
    }
    if (turnCounter >= 30) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Task Complete!");
      delay(2000);
      turnCounter = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Counter Ready");
      lcd.setCursor(0, 1);
      lcd.print("Turns: 0");
    }
    isTurnDetected = true;
  }
if (sensorValue < threshold) {
 isTurnDetected = false;
 }
 }