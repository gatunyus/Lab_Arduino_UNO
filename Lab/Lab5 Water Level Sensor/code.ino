int waterPin = A0; // ต่อขา S (Signal) เข้า Analog A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(waterPin);
  Serial.println(val); // จุ่มน้ำ ค่าจะเพิ่มขึ้น (0 - 1023)
  delay(500);
}