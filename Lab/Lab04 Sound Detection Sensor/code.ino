int soundPin = 5; // ต่อขา DO เข้า Pin 5

void setup() {
  Serial.begin(9600);
  pinMode(soundPin, INPUT);
}

void loop() {
  int val = digitalRead(soundPin);
  if ( val == 0 ) {
    Serial.println("มีเสียง")
  } else {
    Serial.println("ไม่มีเสียง")
  }
}
