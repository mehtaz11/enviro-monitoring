#include <DHT.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

// DHT11 settings
#define DHTPIN D4        
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// OLED settings
Adafruit_SSD1306 display;  

// MQ-135 settings
#define MQ135_PIN A0

void setup() {
  // Initialize Serial for debugging
  Serial.begin(115200);

  // Initialize DHT11 sensor
  dht.begin(); 

  // Initialize MQ-135
  pinMode(MQ135_PIN, INPUT);
}

void loop() {
  // Read data from DHT11 and MQ-135
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int mq135_value = analogRead(MQ135_PIN);

  // Display values on OLED
  display.clearDisplay();
  
  display.print("Temp: ");
  display.print(temperature);
  display.print(" C");

  display.print("\nHumidity: ");
  display.print(humidity);
  display.print(" %");

  display.print("\nMQ-135: ");
  display.print(mq135_value);

  display.display();

  delay(5000);  // Delay between readings
}
