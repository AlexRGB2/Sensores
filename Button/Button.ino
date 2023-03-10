#include <ESP32Servo.h>
#include <analogWrite.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>

Servo servoM;

const int buttonPin = 4;  // pin al que está conectado el botón

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // configuramos el pin como entrada con resistencia pull-up
  Serial.begin(9600);  // inicializamos la comunicación serial a 115200 baudios
  servoM.attach(5);
}

void loop() {
  int buttonState = digitalRead(buttonPin);  // leemos el estado del botón
  if (buttonState == LOW) {  // si el botón está pulsado
    Serial.println("Botón pulsado");  // imprimimos un mensaje por el puerto serial
    servoM.write(360);
  } else {
    servoM.write(0);
  }
  delay(100);  // esperamos 100 milisegundos antes de hacer la siguiente lectura
}