#include <DHT.h>
#include <LiquidCrystal.h>

// Pin definitions
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // Initialize a 16x2 LCD
  dht.begin();      // Start the DHT sensor
  lcd.print("Initializing...");
  delay(2000);      // Pause for startup
  lcd.clear();
}

void loop() {
  float tempC = dht.readTemperature();      // Read temperature in Celsius
  float tempF = (tempC * 9 / 5) + 32;       // Convert to Fahrenheit
  float humidity = dht.readHumidity();      // Read humidity

  if (isnan(tempC) || isnan(humidity)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor error!");
    delay(2000);
    return;
  }

  lcd.setCursor(0, 0); // Set to top-left corner
  lcd.print("Temp: ");
  lcd.print(tempF);
  lcd.print((char)223); // Degree symbol
  lcd.print("F");

  lcd.setCursor(0, 1); // Set to second row
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  delay(2000); // Refresh every 2 seconds
}
