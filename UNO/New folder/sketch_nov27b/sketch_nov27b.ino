#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Define the pin connected to the DHT11
#define DHTPIN 2  // Pin connected to DHT11 data pin
#define DHTTYPE DHT11  // DHT11 sensor

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);  // Start serial communication
  Serial.println("DHT11 Sensor Test");
  
  dht.begin();  // Start the DHT sensor
}

void loop() {
  // Wait a few seconds between readings
  delay(2000);

  // Read temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if readings failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print values to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
