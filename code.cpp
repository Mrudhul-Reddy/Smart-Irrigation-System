#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk authentication token (replace with your token)
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";

// Your Wi-Fi credentials
char ssid[] = "YOUR_SSID";
char pass[] = "YOUR_PASSWORD";

// Define the pin for soil moisture sensor and relay
#define MOISTURE_SENSOR_PIN A0
#define RELAY_PIN D1

// Blynk virtual pins
#define MOISTURE_VPIN V1
#define RELAY_VPIN V2

// Initialize the LCD (address, width, height)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust address and dimensions if needed

void setup()
{
  // Debugging console
  Serial.begin(115200);

  // Connect to Wi-Fi
  Blynk.begin(auth, ssid, pass);

  // Set pin modes
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  
  // Initialize relay state
  digitalWrite(RELAY_PIN, LOW);

  // Initialize LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.setCursor(0, 1);
  lcd.print("Motor: OFF");
}

void loop()
{
  Blynk.run();

  // Read soil moisture sensor
  int moistureLevel = analogRead(MOISTURE_SENSOR_PIN);
  Blynk.virtualWrite(MOISTURE_VPIN, moistureLevel);

  // Display on LCD
  lcd.setCursor(9, 0);
  lcd.print(moistureLevel);
  
  // Control relay based on moisture level
  if (moistureLevel < 300)  // Adjust the threshold based on your sensor
  {
    digitalWrite(RELAY_PIN, HIGH);
    Blynk.virtualWrite(RELAY_VPIN, 1);  // Relay ON
    lcd.setCursor(6, 1);
    lcd.print("ON ");
  }
  else
  {
    digitalWrite(RELAY_PIN, LOW);
    Blynk.virtualWrite(RELAY_VPIN, 0);  // Relay OFF
    lcd.setCursor(6, 1);
    lcd.print("OFF");
  }

  delay(1000);  // Delay between readings
}

