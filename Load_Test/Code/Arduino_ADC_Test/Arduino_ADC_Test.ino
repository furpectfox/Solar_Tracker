#define ADCPIN A1
const float REFVOLTAGE = 4.914;
const float R1 = 8210;
const float R2 = 1197;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int avgADC;
  int sum = 0;
  for(uint8_t i=0; i<5; i++) {
    sum += analogRead(ADCPIN);
  }
  avgADC = sum / 5;
  float volts = (REFVOLTAGE * avgADC) / 1024.0;

  Serial.print("avgADC: "); Serial.print(avgADC);
  Serial.print("  volts: "); Serial.println(volts, 3); 
  delay(500);

}
