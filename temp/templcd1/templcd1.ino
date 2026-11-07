// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int temp_lcd = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(A0, INPUT);
  lcd_1.begin(16, 2);
}

void loop()
{
  temp_lcd = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -10, 120);
  lcd_1.setCursor(0, 0);
  lcd_1.print("temperature=");
  lcd_1.setCursor(12, 0);
  lcd_1.print(temp_lcd);
  delay(200); // Wait for 200 millisecond(s)
  lcd_1.clear();
}