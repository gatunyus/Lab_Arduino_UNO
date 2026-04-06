// ไฟล์: ActiveBuzzer.ino
int buzzerPin = 8; // ต่อขา + เข้า Digital 8

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // สั่งให้ดัง (HIGH)
  digitalWrite(buzzerPin, HIGH); 
  delay(1000); 
  
  // สั่งให้เงียบ (LOW)
  digitalWrite(buzzerPin, LOW);  
  delay(1000);
}