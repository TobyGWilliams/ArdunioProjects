#include <EmonLib.h>

const int analogInPin = A0;
void setup() {

  Serial.begin(9600);
  Serial.println("Dust Extractor v0.1");
}

void loop() {
  Serial.println(analogRead(analogInPin));

}
