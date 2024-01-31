const int analogPin1 = A1; // Flowsensor
const int analogPin0 = A0; // Drucksensor

// Funktion für die manuelle Skalierung
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Flowsensor
  float valueFlow = analogRead(analogPin1);
  float durchflussFlow = mapFloat(valueFlow, 85.00, 477.00, 0.0, 10.00);

  // Drucksensor
  float valuePressure = analogRead(analogPin0);
  float druckPressure = mapFloat(valuePressure, 85.00, 477.0, 0.0, 10.00);

  Serial.print("Flowrate (Flowsensor): ");
  Serial.print(durchflussFlow, 2);
  Serial.println(" l/min");

  Serial.print("Pressure (Drucksensor): ");
  Serial.print(druckPressure, 2);
  Serial.println(" bar");

  Serial.println();

  delay(500);
}