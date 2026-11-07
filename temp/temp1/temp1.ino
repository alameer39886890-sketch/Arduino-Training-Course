// C++ code
//
int tem = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
   pinMode(8, OUTPUT);
}

void loop()
{
  tem = map((analogRead(A0) - (20 + 3.043)), 0, 1023, -20, 180);
  Serial.println(tem);
  if (tem > 20) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
  if (tem > 30) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }
  if (tem > 40) {
    digitalWrite(12, HIGH);
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}