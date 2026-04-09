# Arduino Accelerometer & Gyroscope (MPU-6050)

## Overview (ภาพรวม)
แลปนี้เป็นการทดลองใช้งาน `**MPU-6050 (เซ็นเซอร์วัดความเร่งและไจโรสโคป)**` แบบ 6 แกน (6-Axis IMU) ซึ่งเป็นเซ็นเซอร์ที่ใช้ตรวจจับการเคลื่อนไหว การเอียง และทิศทาง โดยสื่อสารกับบอร์ด Arduino ผ่านโปรโตคอล I2C

ในแลปนี้ เราจะเขียนโค้ดระดับพื้นฐานเพื่อดึงค่าความเร่ง (Acceleration) ดิบจากรีจิสเตอร์ของเซ็นเซอร์โดยตรง (ไม่ต้องใช้ไลบรารีสำเร็จรูป) เพื่อดูการเปลี่ยนแปลงของค่าแรงโน้มถ่วงในแนวแกน X, Y และ Z เมื่อเราขยับหรือเอียงโมดูลไปในทิศทางต่างๆ ซึ่งเป็นพื้นฐานสำคัญก่อนนำไปต่อยอดทำระบบกันสั่น (Gimbal)หรือโดรน

## Hardware Wiring (การต่อวงจร)
การเชื่อมต่อสายสัญญาณ I2C ระหว่างโมดูล MPU-6050 และบอร์ด Arduino UNO สามารถทำได้ตามตารางนี้:

| MPU-6050 Module | Arduino UNO Board |
| :--- | :--- |
| **VCC** | 5V (โมดูลส่วนใหญ่มี Regulator รับ 5V ได้) |
| **GND** | GND |
| **SCL** (Clock) | **A5** (หรือขา SCL มุมขวาบนของบอร์ด) |
| **SDA** (Data) | **A4** (หรือขา SDA มุมขวาบนของบอร์ด) |

![Circuit](../Images/c11.png)

*(หมายเหตุ: ขา AD0 และ INT ในแลปนี้ปล่อยว่างไว้ได้เลย ไม่ต้องต่อ)*

## Code
อัปโหลดโค้ดด้านล่างนี้ลงในบอร์ด Arduino ของคุณ (ตั้งค่า Baud Rate ใน Serial Monitor เป็น `9600`):

```cpp
#include <Wire.h>
#include <math.h>

const int MPU_addr = 0x68;

// Set Offset (Calibration)
float roll_offset = 0.0;   

// Variables for Low-Pass Filter
float filtered_roll = 0;
const float alpha = 0.15; // Adjust smoothness (lower value = smoother)

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
  Wire.write(0x3B);
  Wire.endTransmission(false);
  
  // ขออ่านข้อมูล 6 ไบต์ต่อเนื่อง (X, Y, Z แกนละ 2 ไบต์)
  Wire.requestFrom(MPU_addr, 6, true); 
  
  // อ่านค่ามาทีละแกน (นำไบต์สูงมาต่อกับไบต์ต่ำ) แล้วหารด้วย 16384.0 เพื่อแปลงเป็นสเกล g
  float AcX = (Wire.read() << 8 | Wire.read()) / 16384.0; 
  float AcY = (Wire.read() << 8 | Wire.read()) / 16384.0; 
  float AcZ = (Wire.read() << 8 | Wire.read()) / 16384.0; 

  Serial.print("X: "); 
  Serial.print(AcX); 
  Serial.print(" | Y: "); 
  Serial.print(AcY); 
  Serial.print(" | Z: "); 
  Serial.println(AcZ); 

  delay(100); 
}
```

Output : 

![Output](../Images/o11.png)