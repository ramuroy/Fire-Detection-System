#define SMOKE_SENSOR A0  // MQ-2 sensor connected to Analog pin A0
#define LED_PIN 7        // LED connected to digital pin 7
#define BUZZER_PIN 8     // Buzzer connected to digital pin 8
#define THRESHOLD 300    // Adjust the threshold based on sensor readings

void setup() {
    pinMode(SMOKE_SENSOR, INPUT);  // Set smoke sensor as input
    pinMode(LED_PIN, OUTPUT);      // Set LED as output
    pinMode(BUZZER_PIN, OUTPUT);   // Set buzzer as output
    Serial.begin(9600);            // Initialize serial communication
}

void loop() {
    int smokeValue = analogRead(SMOKE_SENSOR);  // Read sensor value
    Serial.print("Smoke Sensor Value: ");
    Serial.println(smokeValue);  // Print sensor value for debugging

    if (smokeValue > THRESHOLD) {  // If smoke exceeds threshold
        digitalWrite(LED_PIN, HIGH);   // Turn on LED
        digitalWrite(BUZZER_PIN, HIGH); // Activate buzzer
    } else {
        digitalWrite(LED_PIN, LOW);    // Turn off LED
        digitalWrite(BUZZER_PIN, LOW); // Deactivate buzzer
    }

    delay(500);  // Small delay to stabilize readings
}