#define ADCPIN 34
const float R1 = 8210;
const float R2 = 1197;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogReadResolution(12);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sum = 0;
  for(uint8_t i=0; i<5; i++) {
    sum += analogReadMilliVolts(ADCPIN);
  }
  int millivolts = sum / 5;

  Serial.print("  volts: "); Serial.println(millivolts); 
  delay(500);

}
