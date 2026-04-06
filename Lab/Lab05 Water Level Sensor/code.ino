int waterPin = A0; // ต่อเข้า Analog A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(waterPin);
  Serial.print("วัดค่าได้ : ");
  Serial.print(val);
  Serial.print(" - สถานะ: ");

  if (val < 10) {
    // ถ้าน้อยกว่า 10 ถือว่าไม่มีน้ำเลย
    Serial.println("แห้ง");
  } 
  else if (val >= 10 && val <= 300) {
    // ค่าระหว่าง 10 ถึง 300
    Serial.println("ชื้นเล็กน้อย");
  } 
  else if (val > 300 && val <= 600) {
    // ค่าระหว่าง 301 ถึง 600
    Serial.println("ชื้นมาก");
  } 
  else {
    // ค่าที่มากกว่า 600 ขึ้นไป
    Serial.println("เปียก");
  }

  delay(1000); 
}
