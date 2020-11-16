#include <Wire.h>
#include <LapINA219.h>

LapINA219 imonitor(0x40);

void setup() {
  Serial.begin(115200);
  Serial.println("Start....");
  imonitor.begin();
  delay(5000);
}

void loop() {
  Serial.print("Bus voltage: ");
  Serial.print(imonitor.busVoltage());
  Serial.println("V");
  Serial.print("Shunt voltage: ");
  Serial.print(imonitor.shuntVoltage());
  Serial.println("mV");
  Serial.print("Shunt current: ");
  Serial.print(imonitor.shuntCurrent());
  Serial.println("mA");
  Serial.print("Bus power: ");
  Serial.print(imonitor.busPower());
  Serial.println("mW"); 
  Serial.println();
  Serial.println();  
  delay(5000);
}
