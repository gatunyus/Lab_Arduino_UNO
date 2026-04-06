#include "DHT.h"
#define DHTPIN 2       // ต่อขา Data เข้า Pin 2
#define DHTTYPE DHT21  // กำหนดรุ่นเป็น DHT21

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidity: "); Serial.print(h);
  Serial.print(" % \t Temp: "); Serial.print(t); Serial.println(" C");
  delay(2000); // ควรอ่านช้าๆ ทุก 2 วินาที
}