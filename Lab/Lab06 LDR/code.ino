int ldrPin = A0; // ต่อเข้า Analog A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(ldrPin);
  if (val > 600) {
    Serial.println("มืด");
  } else {
    Serial.println("สว่าง");
  }
  delay(500);
}
