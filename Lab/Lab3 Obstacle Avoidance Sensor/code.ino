int irPin = 4; // ต่อขา OUT เข้า Pin 4

void setup() {
  Serial.begin(9600);
  pinMode(irPin, INPUT);
}

void loop() {
  int val = digitalRead(irPin);
  Serial.println(val); // เอามือบังเซนเซอร์ ค่าจะเปลี่ยนเป็น 0 (LOW)
  delay(100);
}