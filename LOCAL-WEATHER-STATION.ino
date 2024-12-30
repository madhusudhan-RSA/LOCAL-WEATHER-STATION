#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin definitions
#define DHTPIN 2
#define RAINPIN 3
#define DHTTYPE DHT11

// Initialize sensors
Adafruit_BMP280 bmp;
DHT dht(DHTPIN, DHTTYPE);

// Initialize I2C LCD (16x2 with address 0x27; adjust as needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables
float temperature, humidity, pressure;
bool isRaining;

void setup() {
  Serial.begin(9600);  // Serial Monitor
  Serial1.begin(9600); // Bluetooth communication

  // Initialize sensors
  if (!bmp.begin(0x77)) {
    Serial.println("BMP280 initialization failed!");
    Serial1.println("BMP280 initialization failed!");
    while (1);
  }
  dht.begin();

  // Rain sensor setup
  pinMode(RAINPIN, INPUT);

  // LCD initialization
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Weather Station");
  delay(2000);
  lcd.clear();

  // Bluetooth initialization message
  Serial1.println("Bluetooth Ready: Weather Station");
}

void loop() {
  // Read DHT11
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // Read BMP280
  pressure = bmp.readPressure() / 100.0; // Convert to hPa

  // Read rain sensor
  isRaining = digitalRead(RAINPIN) == LOW; // LOW indicates rain detected

  // Display on Serial Monitor
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    Serial1.println("DHT sensor error!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }
  Serial.print("Pressure: "); Serial.print(pressure); Serial.println(" hPa");
  Serial.print("Rain: "); Serial.println(isRaining ? "Yes" : "No");

  // Send data to Bluetooth
  sendBluetoothData(temperature, humidity, pressure, isRaining);

  // Display on I2C LCD
  displayOnLCD(temperature, humidity, pressure, isRaining);

  delay(2000);
}

void displayOnLCD(float temp, float hum, float press, bool rain) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:"); lcd.print(temp); lcd.print("C");
  lcd.setCursor(8, 0);
  lcd.print("H:"); lcd.print(hum); lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("P:"); lcd.print(press); lcd.print("hPa");
  lcd.setCursor(8, 1);
  lcd.print("Rain:"); lcd.print(rain ? "Yes" : "No");
}

void sendBluetoothData(float temp, float hum, float press, bool rain) {
  Serial1.print("Temp: "); Serial1.print(temp); Serial1.println(" °C");
  Serial1.print("Humidity: "); Serial1.print(hum); Serial1.println(" %");
  Serial1.print("Pressure: "); Serial1.print(press); Serial1.println(" hPa");
  Serial1.print("Rain: "); Serial1.println(rain ? "Yes" : "No");
  Serial1.println("-------------------------");
}
