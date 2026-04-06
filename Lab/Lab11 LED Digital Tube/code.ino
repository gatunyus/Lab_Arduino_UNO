#include <TM1637Display.h>

#define CLK 4 // ต่อขา CLK เข้า Pin 4
#define DIO 5 // ต่อขา DIO เข้า Pin 5

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(0x0f); // ตั้งความสว่างสูงสุด
}

void loop() {
  display.showNumberDec(1234, false); // แสดงตัวเลข 1234 บนหน้าจอ
  delay(1000);
}