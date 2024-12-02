#include <DHT.h>

#define DHTPIN 2      // Pin connected to DHT11
#define DHTTYPE DHT11 // DHT 11
#define BUZZER_PIN 8  // Pin connected to buzzer
#define VOLUME_PIN 9  // PWM pin for volume control

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(BUZZER_PIN, OUTPUT);
   // pinMode(VOLUME_PIN, OUTPUT);
}

void loop() {
    // Read temperature every 2 seconds
    delay(1000);
    float temperature = dht.readTemperature();
    
    if (!isnan(temperature)) {
        Serial.print("T:");
        Serial.println(temperature);
    }

    // Check for incoming serial data
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        
        if (command.startsWith("V")) {  // Volume command
            int volume = command.substring(1).toInt();
            //analogWrite(VOLUME_PIN, map(volume, 0, 100, 0, 255));
        }
        else if (command == "B") {  // Beep command
            digitalWrite(BUZZER_PIN, HIGH);
            delay(200);
            digitalWrite(BUZZER_PIN, LOW);
        }
    }
}
