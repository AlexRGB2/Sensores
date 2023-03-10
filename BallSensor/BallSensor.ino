const int tiltSensorPin = 2; // pin utilizado por el sensor de inclinación KY-020
int tiltValue = 0; // valor de lectura del sensor de inclinación

void setup() {
  pinMode(tiltSensorPin, INPUT); // Configuramos el pin del sensor de inclinación como entrada
  Serial.begin(9600); // Iniciamos la comunicación serial
}

void loop() {
  tiltValue = digitalRead(tiltSensorPin); // Leemos el valor digital del pin del sensor de inclinación

  if (tiltValue == HIGH) {
    Serial.println("El sensor de inclinación está en posición horizontal");
  } else {
    Serial.println("El sensor de inclinación está en posición vertical");
  }

  delay(1000); // Esperamos un segundo antes de realizar la siguiente lectura
}

