// ขา R, G, B ต้องต่อเข้าขาที่มีสัญลักษณ์ ~ (PWM)
int redPin = 9; // ต่อขา R เข้า Digital 9
int greenPin = 10; // ต่อขา R เข้า Digital 10
int bluePin = 11;  // ต่อขา R เข้า Digital 11

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // เทสต์สีแดง
  analogWrite(redPin, 255); analogWrite(greenPin, 0); analogWrite(bluePin, 0);
  delay(1000);
  // เทสต์สีเขียว
  analogWrite(redPin, 0); analogWrite(greenPin, 255); analogWrite(bluePin, 0);
  delay(1000);
  // เทสต์สีน้ำเงิน
  analogWrite(redPin, 0); analogWrite(greenPin, 0); analogWrite(bluePin, 255);
  delay(1000);
}