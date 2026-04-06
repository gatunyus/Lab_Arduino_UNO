#include <Wire.h>
const int MPU_addr = 0x68; // I2C address ของ MPU6050

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B); // Wake up MPU
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B); // เริ่มอ่านที่ค่า Accelerometer แกน X
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 2, true); 
  
  int16_t AcX = Wire.read()<<8 | Wire.read(); 
  Serial.print("Acc X: "); 
  Serial.println(AcX); // ขยับบอร์ด ค่าจะเปลี่ยน
  delay(300);
}