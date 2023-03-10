#define THERMISTORNOMINAL 10000  // valor nominal del termistor a 25°C
#define TEMPERATURENOMINAL 25    // temperatura nominal a la que se midió el valor nominal
#define BCOEFFICIENT 3950        // coeficiente B del termistor
#define SERIESRESISTOR 10000     // resistencia en serie con el termistor

int sensorPin = 15;  // pin al que está conectado el sensor

void setup() {
  Serial.begin(9600);  // inicializamos la comunicación serial a 9600 baudios
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // leemos el valor del pin A0
  float resistance = (float)SERIESRESISTOR / ((1023.0 / sensorValue) - 1.0);  // calculamos la resistencia del termistor
  float temperature = 1.0 / (log(resistance / THERMISTORNOMINAL) / BCOEFFICIENT + 1.0 / (TEMPERATURENOMINAL + 273.15)) - 273.15;  // calculamos la temperatura en grados Celsius
  Serial.println(temperature);  // imprimimos la temperatura por el puerto serial
  delay(2000);  // esperamos 1 segundo antes de hacer la siguiente medición
}
