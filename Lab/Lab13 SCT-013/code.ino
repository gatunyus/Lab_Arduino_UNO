#include "EmonLib.h"
EnergyMonitor emon1; // สร้าง Object สำหรับวัดไฟ

void setup() {  
  Serial.begin(9600);
  // (ขา Analog A2, ค่า Calibration ปกติสำหรับ SCT-013-000 คือ 111.1)
  emon1.current(A2, 111.1); 
}

void loop() {
  double Irms = emon1.calcIrms(1480); // คำนวณค่ากระแส (Irms)
  Serial.print("Current: ");
  Serial.print(Irms); // แสดงกระแสที่วัดได้
  Serial.println(" A");
  delay(1000);
}