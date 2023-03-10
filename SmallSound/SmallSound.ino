const int soundSensorPin = 14;  // pin utilizado por el sensor de sonido KY-038
int soundValue = 0;             // valor de lectura del sensor de sonido
int alex = 5;
int alex2 = 4;

void setup() {
  Serial.begin(9600);  // Iniciamos la comunicación serial
  pinMode(alex, OUTPUT);
  pinMode(alex2, OUTPUT);
}

void loop() {
  soundValue = analogRead(soundSensorPin);  // Leemos el valor analógico del pin del sensor de sonido

  // Mostramos el valor leído en el puerto serie
  if (soundValue >= 40) {
    Serial.print("Valor del sensor de sonido: ");
    Serial.println(soundValue);
    digitalWrite(alex, HIGH);
    digitalWrite(alex2, LOW);
  } else {
    digitalWrite(alex, LOW);
  }

  delay(100);  // Esperamos un segundo antes de realizar la siguiente lectura
}
