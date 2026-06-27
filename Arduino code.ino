#define SMOKE_SENSOR A0  // MQ-2 sensor on analog pin A0
#define LED_PIN 7        // LED on digital pin 7
#define BUZZER_PIN 8     // Buzzer on digital pin 8

// MQ-2 gas sensors need their heater to warm up before readings are usable;
// ignore the sensor for this long after power-on to avoid boot-time false alarms.
#define WARMUP_MS 20000UL

// Hysteresis around the trip point (tune per sensor/environment): arm above
// ALARM_ON, disarm only below ALARM_OFF, so the alarm latches instead of
// chattering when smoke hovers near the threshold.
#define ALARM_ON 320
#define ALARM_OFF 280

bool alarm = false;

void setup() {
    pinMode(LED_PIN, OUTPUT);      // analogRead() needs no pinMode on A0
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int smokeValue = analogRead(SMOKE_SENSOR);
    Serial.print("Smoke Sensor Value: ");
    Serial.println(smokeValue);

    // Hold off until the MQ-2 has warmed up.
    if (millis() < WARMUP_MS) {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(BUZZER_PIN, LOW);
        delay(200);
        return;
    }

    if (!alarm && smokeValue > ALARM_ON) alarm = true;
    else if (alarm && smokeValue < ALARM_OFF) alarm = false;

    digitalWrite(LED_PIN, alarm ? HIGH : LOW);
    digitalWrite(BUZZER_PIN, alarm ? HIGH : LOW);

    delay(200);
}
