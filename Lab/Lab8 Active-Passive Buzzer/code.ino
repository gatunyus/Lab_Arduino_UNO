int buzzerPin = 8; // ต่อขา I/O หรือ Signal เข้า Pin 8

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // ถ้าเป็น Active Buzzer เสียงจะดังจี๊ดยาวๆ
  // ถ้าเป็น Passive Buzzer เสียงจะดังติ๊ดๆ หรือใช้คำสั่ง tone() สร้างเสียงได้
  digitalWrite(buzzerPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
  delay(1000);
}