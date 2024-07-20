//Velocity Detector V3
//As of July 19, 2024
//This code was written with assistance from ChatGPT

const int sensorPin = 3; // Photo Interrupter sensor is attached to pin 3
const float flagLength = 0.584; // Length of the flag in cm

unsigned long entryTime = 0; // Time when the object enters the sensor's field of view
unsigned long exitTime = 0; // Time when the object exits the sensor's field of view
bool objectDetected = false; // Flag to indicate if the object is currently detected

void setup() {
  pinMode(sensorPin, INPUT); // Photo interrupter is input
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorState = digitalRead(sensorPin);

  if (sensorState == LOW && !objectDetected) {
    // Object entering the sensor's field of view for the first time
    entryTime = micros(); // Record the entry time
    objectDetected = true; // Set the flag to indicate object detection
  }
  else if (sensorState == HIGH && objectDetected) {
    // Object exiting the sensor's field of view
    exitTime = micros(); // Record the exit time
    objectDetected = false; // Reset the object detection flag

    // Calculate the duration the object was blocking the sensor
    unsigned long blockingTime = exitTime - entryTime;

    // Calculate velocity
    float velocity = (flagLength/100) / (blockingTime / 1000000.0); // Convert flag length to meters and blocking time to seconds

    // Output velocity to serial monitor
    Serial.print("Velocity: ");
    Serial.print(velocity);
    Serial.println(" m/s");
    
  }
}
