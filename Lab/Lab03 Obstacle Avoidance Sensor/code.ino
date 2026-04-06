int irPin = 2; // ต่อขา OUT เข้า Pin 2

void setup() {
  Serial.begin(9600);
  pinMode(irPin, INPUT);
}

void loop() {
  int val = digitalRead(irPin);
  if ( val == 0 ) {
    Serial.println("มืด");
  } else {
    Serial.println("สว่าง");
  }
  delay(100);
}
