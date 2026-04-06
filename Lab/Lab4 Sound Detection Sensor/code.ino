int soundPin = 5; // ต่อขา DO เข้า Pin 5

void setup() {
  Serial.begin(9600);
  pinMode(soundPin, INPUT);
}

void loop() {
  int val = digitalRead(soundPin);
  Serial.println(val); // ลองปรบมือหรือเป่าลมใส่ไมค์ ค่าจะเปลี่ยน
  delay(100);
}