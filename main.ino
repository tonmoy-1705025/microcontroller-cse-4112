#include <DHT.h>
#include <LiquidCrystal.h>
#define PUMP_PIN PA7
#define DHT_Sensor_Pin PC13
#define DHTTYPE DHT11  // Set DHT sensor Type
DHT dht(DHT_Sensor_Pin, DHTTYPE); // Initialize the DHT sensor

const int rs = PA5, en = PA4, d4 = PA3, d5 = PA2, d6 = PA1, d7 = PA0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // initialize the 16*2 LCD display

// Motor Data
float TARGET_TEMP = 27.0;
float PumpDuration = 0.3;
bool pump_on = false;
int timer = 0;
bool canRun = true;
const long interval = 86400000;   // 24 hours in milliseconds
//const long interval = 60000;   // 24 hours in milliseconds


unsigned long previousMillis = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("==! Welcome !==");
  lcd.setCursor(0, 1);
  lcd.print(" To MC Project");
  dht.begin();
  pinMode( PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, HIGH);
}

void Display_decimal(LiquidCrystal& lcd, float data) {
  int dataInt = data * 10;
  lcd.print(dataInt / 10);
  lcd.print(".");
  lcd.print(dataInt % 10);
}


void loop() {

  delay(2000);

  unsigned long currentMillis = millis();
  Serial.println(currentMillis);

  if ( pump_on == true ){
    timer = (currentMillis-previousMillis)/1000 ;
    if ( timer >= (PumpDuration*60) ){
      pump_on = false;
      timer = 0;
      digitalWrite(PUMP_PIN, HIGH);
      Serial.println("Motor Has been Stoppeddd!!");
    }
  }


  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  // Is error Humidity and temparature
  if (isnan(humidity) || isnan(temperature)) {
    // lcd.clear();
    // lcd.print("Failed to read");
    // lcd.setCursor(0, 1);
    // lcd.print("from DHT sensor!");
    // Serial.println("Failed to read from DHT sensor!");

    return;
  }

  if ( currentMillis - previousMillis >= interval ){
    canRun = true;
    Serial.println("It reached 24 hours");
  }
  else {
    Serial.println("Cannot Run Only ");
    Serial.println( (currentMillis - previousMillis)/1000 );
  }

  // If it reached the temparature 
  if ( canRun == true && temperature >= TARGET_TEMP ){
    Serial.print("Teamp reached ");

    // set time
    pump_on = true;
    canRun = false;
    previousMillis = currentMillis;
    digitalWrite(PUMP_PIN, LOW);
    Serial.println("Motor Has been started!!");

  }

  lcd.clear();
  lcd.print("Humi: ");
  Display_decimal(lcd, humidity);
  lcd.print("% |");
  if (pump_on==true) lcd.print("ON");
  else lcd.print("OFF");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  Display_decimal(lcd, temperature);
  lcd.print("c |");
  if (pump_on==true) lcd.print(timer);
  else lcd.print(" -");

  // Serial.print("Humidity: ");
  // Serial.print(humidity);
  // Serial.print("%\t");
  // Serial.print("Temperature: ");
  // Serial.print(temperature);
  // Serial.println("°C");
}
