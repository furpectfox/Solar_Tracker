
#define ADC_SAMPLES_NUM 5
#define SENSE_RESISTANCE 1
#define REFERENCE_VOLTAGE 1.1
#define KNOWN_VOLTAGE 0.724

void setup() {
  // put your setup code here, to run once:
  analogReference(INTERNAL);
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int sum = 0;
  for(uint8_t i=0; i < ADC_SAMPLES_NUM; i++) {
    int ADCVal = analogRead(A3);
    sum = sum + ADCVal;
    delay(50);
  }
  float ADCFinal = (float)sum / ADC_SAMPLES_NUM;
  float senseVoltage = (ADCFinal * REFERENCE_VOLTAGE)/1024;
  float current = senseVoltage / SENSE_RESISTANCE;
  Serial.println(current,3);

}
