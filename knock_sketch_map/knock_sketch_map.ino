
// these constants won't change:
const int ledPin = 7;      // LED connected to digital pin 13
const int knockSensor = A1; // the piezo is connected to analog pin 0
const int threshold = 8;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light
int mappedValue = 0;



void setup() {
  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  Serial.begin(9600);       // use the serial port
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);

  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    mappedValue = map(sensorReading, 1, 30, 50, 255);
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.print(mappedValue);
    Serial.print(" ");
    Serial.print(sensorReading);
    Serial.println("meow");
  }
  delay(100);  // delay to avoid overloading the serial port buffer
}
