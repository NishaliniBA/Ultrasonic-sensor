const int trigPin = 9; // Trigger pin of the ultrasonic sensor
const int echoPin = 10; // Echo pin of the ultrasonic sensor

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second
  pinMode(trigPin, OUTPUT); // Set the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Set the echoPin as an INPUT
}

void loop() {
  long duration, distance; // Variables to store the duration and distance measured by the sensor
  digitalWrite(trigPin, LOW); // Clear the trigPin
  delayMicroseconds(2); // Wait for the sensor to settle
  digitalWrite(trigPin, HIGH); // Set the trigPin high to trigger the sensor
  delayMicroseconds(10); // Wait for a 10 microsecond pulse
  digitalWrite(trigPin, LOW); // Clear the trigPin

  duration = pulseIn(echoPin, HIGH); // Read the duration of the pulse received on the echoPin
  distance = duration * 0.034 / 2; // Calculate the distance in centimeters

  Serial.print("Distance: "); // Print the string "Distance: " followed by the distance measured
  Serial.print(distance); // Print the distance measured
  Serial.println(" cm"); // Print "cm" and a new line

  delay(1000); // Wait for 1 second before taking the next measurement
}
