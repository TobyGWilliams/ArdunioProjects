#include <TimedAction.h>
#include <EmonLib.h>

EnergyMonitor emon1;
const int currentSensingPin = 1;
const int relayPin = 2;
const float currentThreshold = 1;

int timeOut = 10;
boolean extractionOn = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Dust Extractor v0.1");
  emon1.current(currentSensingPin, 11.1);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(2, HIGH); 
  digitalWrite(3, HIGH); 
}

void checkCurrent() {
  double Irms = emon1.calcIrms(1480);
  if (Irms > currentThreshold) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    timeOut = 10;
    return;
  } else {
    if (timeOut == 0) {
      digitalWrite(2, HIGH); 
    } else if (timeOut > 0 ) {
      digitalWrite(3, HIGH);
      timeOut--;
    }
  }
}

TimedAction timedAction = TimedAction(1000, checkCurrent);

void loop() {
  timedAction.check();
}




