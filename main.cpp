// Pin assignments
const int buzzerPin = 10;   // Pin for the buzzer
const int flamePin = 12;    // Pin for the flame sensor
int Flame = HIGH;           // Variable to store the flame sensor state
int redled = 6;             // Pin for the red LED
int greenled = 5;           // Pin for the green LED
int motorPin = 8;           // Pin for the motor

void setup() {
  // Set pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(flamePin, INPUT);
  pinMode(motorPin, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the state of the flame sensor
  Flame = digitalRead(flamePin);

  // Check if flame is detected
  if (Flame == LOW) {
    // Fire detected
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
    digitalWrite(motorPin, HIGH);  // Activate the motor (assuming HIGH activates the motor)
    
    // Print message to serial monitor
    Serial.println("Fire Detected! Water Sprinkler Activated!");
  } else {
    // No fire detected
    digitalWrite(buzzerPin, LOW);
    digitalWrite(greenled, HIGH);
    digitalWrite(motorPin, LOW);  // Turn off the motor
    digitalWrite(redled, LOW);
    
    // Print message to serial monitor
    Serial.println("Fire Not Detected!");
  }
  // Add a delay or other logic as needed
}
