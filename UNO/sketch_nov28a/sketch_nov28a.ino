//test
#include <DHT.h>

#define DHTPIN 2     // Pin connected to DHT11
#define DHTTYPE DHT11 // DHT 11
#define BUZZER_PIN 8  // Pin connected to buzzer

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    // Read temperature every 2 seconds
    delay(2000);
    float temperature = dht.readTemperature();
    
    if (!isnan(temperature)) {
        Serial.print("T:");
        Serial.println(temperature); // Send temperature data
    }

    // Check for incoming serial data
    if (Serial.available()) {
        char command = Serial.read(); // Read command from Qt app
        if (command == 'B') {
            digitalWrite(BUZZER_PIN, HIGH); // Turn on buzzer
            delay(500);                      // Beep duration
            digitalWrite(BUZZER_PIN, LOW);  // Turn off buzzer
        }
    }
}
