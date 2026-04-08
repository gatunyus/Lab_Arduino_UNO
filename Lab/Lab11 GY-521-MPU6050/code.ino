#include <Wire.h>
#include <math.h>

const int MPU_addr = 0x68;

// Set Offset (Calibration)
float roll_offset = 0.0;   

// Variables for Low-Pass Filter
float filtered_roll = 0;
const float alpha = 0.15; // Adjust smoothness (lower value = smoother)

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B); // Wake up MPU
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B); // Start at the first Data Register
  Wire.endTransmission(false);
  
  // Read 6 bytes in sequence (X, Y, Z, 2 bytes each)
  Wire.requestFrom(MPU_addr, 6, true); 
  
  // Skip X-axis(read and discard 2 bytes)
  Wire.read(); 
  Wire.read(); 
  
  // Read Y and Z axis values and divide by 16384.0 to convert to g-scale
  float AcY = (Wire.read() << 8 | Wire.read()) / 16384.0; 
  float AcZ = (Wire.read() << 8 | Wire.read()) / 16384.0; 

  // Calculate raw roll in degrees (-180 to 180)
  float raw_roll = atan2(AcY, AcZ) * 180.0 / PI;

  // Apply calibration offset
  raw_roll += roll_offset;

  // Apply Low-Pass Filter to smooth the signal
  filtered_roll = (alpha * raw_roll) + ((1.0 - alpha) * filtered_roll);
  
  Serial.print("Roll: "); 
  Serial.print(filtered_roll); 
  Serial.println(" degrees"); 

  delay(100); 
}