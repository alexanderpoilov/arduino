
#include <Wire.h>
#include <DFRobot_DHT11.h>
#include <LiquidCrystal_I2C.h>

DFRobot_DHT11 DHT; //define sensor DHT11

#define DHT11_PIN 2 //define sensor pin DHT11

const int relayOnePin =  3; //relay 1 pin control
const int relayTwoPin =  4; //relay 2 pin control
const int relayThreePin = 5; //relay 3 pin control
const int relayFourPin =  6; //relay 4 pin control

int moisture; // earth moisture pin

LiquidCrystal_I2C lcd(0x3F,20,4); //address LCD

void setup(){
//  Serial.begin(115200);
  pinMode(relayOnePin, OUTPUT); //make pin output mode
  pinMode(relayTwoPin, OUTPUT); //make pin output mode
  pinMode(relayThreePin, OUTPUT); //make pin output mode
//  pinMode(relayFourPin, OUTPUT); //make pin output mode
  lcd.init();
  lcd.backlight();
}

void loop(){
//  moisture = analogRead(A0); //// earth moisture sensor pin
//  moisture = map(moisture,0,1023,100,1); //map moisture sensor data 1-100
  DHT.read(DHT11_PIN); //read data from sensor
//  Serial.print("temp:");
//  Serial.print(DHT.temperature);
//  Serial.print("  humi:");
//  Serial.println(DHT.humidity);
  lcd.setCursor(0,0);
  lcd.print("temperature: ");
  lcd.setCursor(13,0);
  lcd.print(DHT.temperature);
  lcd.setCursor(0,1);
  lcd.print("humidity: ");
  lcd.setCursor(10,1);
  lcd.print(DHT.humidity);
  lcd.setCursor(0,2);
//  lcd.print("nO4BA: ");
//  lcd.setCursor(6,2);
//  lcd.print(moisture);
  if (DHT.temperature > 30) {
//    Serial.println("MAX TEMPERATURE");
//    Serial.println("relay off");
    digitalWrite(relayOnePin, true);
    digitalWrite(relayTwoPin, true);
    digitalWrite(relayThreePin, true);
    lcd.setCursor(0,3);
    lcd.print("relays: off");
  };
  if (DHT.temperature <= 25) {
//    Serial.println("MIN TEMPERATURE");
//    Serial.println("relay on");
    digitalWrite(relayOnePin, false);
    digitalWrite(relayTwoPin, false);
    digitalWrite(relayThreePin, false);
    lcd.setCursor(0,3);
    lcd.print("relays: on");
//    
  };
delay(1000);
}
