#include <Arduino.h>

constexpr uint8_t LED_RED = PB0;
constexpr uint8_t LED_GREEN = PB1;

void setup()
{
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
    // read the analog input value from pin PA0 and print it to the serial monitor
  int analogValue = analogRead(PA0);
  Serial.print("Analog value: ");
  Serial.println(analogValue);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);
  delay(500);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, HIGH);
  delay(500);
}
