int vibPin = 2; // ต่อขา DO เข้า Pin 2

void setup() {
  Serial.begin(9600);
  pinMode(vibPin, INPUT);
}

void loop() {
  int val = digitalRead(vibPin);
  Serial.println(val); // ลองเคาะโมดูล ค่าจะเปลี่ยนระหว่าง 0 กับ 1
  delay(100);
}