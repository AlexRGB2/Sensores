int aPin = 12;
int analogVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogVal = analogRead(aPin);
  Serial.println("Valor Analogico");
  Serial.println(analogVal);
  delay(1000);
}
