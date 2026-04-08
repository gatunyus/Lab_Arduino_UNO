// PassiveBuzzer.ino
int buzzerPin = 2; // + from module to D2 from board

void setup() {
  // No need to declare pinMode because the tone() is automatic handle
}

void loop() {
  // tone(pin, Hz)
  tone(buzzerPin, 262); // Do (C4)
  delay(500);
  
  tone(buzzerPin, 294); // Re (D4)
  delay(500);
  
  tone(buzzerPin, 330); // Mi (E4)
  delay(500);
  // Silence
  noTone(buzzerPin);   
  delay(1000);
}