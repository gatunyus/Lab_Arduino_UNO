int tiltPin = 3; // ต่อขา DO เข้า Pin 3

void setup() {
  Serial.begin(9600);
  pinMode(tiltPin, INPUT);
}

void loop() {
  int val = digitalRead(tiltPin);
  Serial.println(val); // ลองจับโมดูลเอียงไปมา ค่าจะเปลี่ยน
  delay(100);
}