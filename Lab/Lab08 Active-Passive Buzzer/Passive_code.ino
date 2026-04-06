// ไฟล์: PassiveBuzzer.ino
int buzzerPin = 8; // ต่อขา + เข้า Digital 8

void setup() {
  // ไม่ต้องประกาศ pinMode ก็ได้ เพราะคำสั่ง tone() จะจัดการให้เอง
}

void loop() {
  // tone(ขา, ความถี่Hz)
  tone(buzzerPin, 262); // โด (C4)
  delay(500);
  
  tone(buzzerPin, 294); // เร (D4)
  delay(500);
  
  tone(buzzerPin, 330); // มี (E4)
  delay(500);

  noTone(buzzerPin);    // หยุดส่งเสียง
  delay(1000);
}