// C++ code
//
int gassensor = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  gassensor = analogRead(A0);
  Serial.println(gassensor);
  if (gassensor >= 600) {
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}