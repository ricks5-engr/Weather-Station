#include <WiFiConfig.h>
#include <Adafruit_AHTX0.h>
#include <Wire.h>

#define I2C_SDA 6
#define I2C_SCL 7

uint8_t receiverAddress[] = {0x34, 0xB7, 0xDA, 0xF6, 0x38, 0x4C};

Adafruit_AHTX0 aht;
WeatherReport report;

const int light = 4;
int brightness = 0;

void setup() {
 
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);
  aht.begin();

  wifi_setup();
  peer_setup(receiverAddress);

}
void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);
  report.humidity = humidity.relative_humidity;
  report.temperature = temp.temperature;
  brightness = analogRead(light);
  report.light = brightness; 
  send_report(receiverAddress, report);
  delay(10000);
}
