int ldrPin = A1; // ต่อเข้า Analog A1

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(ldrPin);
  Serial.println(val); // เอามือปิดเซนเซอร์ ค่าจะเปลี่ยนไป
  delay(500);
}