#include <Stepper.h>

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void loop()
{
  int reading = analogRead(A0); // Hall Effect sensor reading
  int sensor = analogRead(A1); // Potentiometer reading
  float setting = sensor/1023.0; // Scale output to 0 - 1
  int threshold = 100 + (setting*400); 
  if (reading < (threshold-2)) { // Outside threshold range enable electromagnet
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else if (reading > (threshold+2)) { // Outside threshold range enable electromagnet
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  } else { // Within threshold range disable electromagnet
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
}
