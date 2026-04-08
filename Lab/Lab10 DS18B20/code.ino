// Download Library OneWire, DallasTemperature From Library Manager
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 // ต่อขา Data สีเหลือง เข้า Pin 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); 
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Water Temp: ");
  Serial.println(tempC);
  delay(1000);
}