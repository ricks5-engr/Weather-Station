#include <WiFiConfig.h>
#include <LiquidCrystal_I2C.h>

char light[] = "Day";
LiquidCrystal_I2C lcd(0x27, 16, 2);
WeatherReport report;
void setup()
{
  Serial.begin(115200);
  wifi_setup();
  set_report_receiver(&report);
	lcd.init(); 
	lcd.backlight();
}

void loop()
{
	lcd.clear();                
  lcd.setCursor(0, 0);         
	lcd.print("Temp: ");
  lcd.print(report.temperature);
  lcd.print(" C");      
	lcd.setCursor(0, 1);         
	lcd.print("Hum: ");
  lcd.print(report.humidity);
  lcd.print("\%");
  lcd.print(" , ");
  if (report.light < 40)
  {
    lcd.print("Night");
  }
  else
  {
    lcd.print("Day");
  }
            
  delay(1000);
}