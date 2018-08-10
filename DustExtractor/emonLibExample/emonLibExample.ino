#include "EmonLib.h"
EnergyMonitor emon1;
void setup()
{
  Serial.begin(9600);

  emon1.current(1, 11.1);             // Current: input pin, calibration.
}

void loop()
{
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  Serial.println(Irms);             // Irms
}

