#include<DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define wlevp A0
#define dhtp A1
#define DHTTYPE DHT11
#define smoip A2
#define ldrp A3
#define rainp 13
// #define   turbidiyty  A5
#define wpumpp 12                    // water pump with relay
#define ind1    11                   //water level
#define ind2     10                     //temperature , moisture , humidity
//#define ind3    9                      // turbidity
#define ind4   8                      // ldr
#define ind5    7                     //rain
#define buzz   6
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 lcd(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


DHT dht(dhtp,DHTTYPE);
void setup() 
{
  Serial.begin(9600);
  dht.begin();
    lcd.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    lcd.clearDisplay();

    lcd.setTextSize(1.8);
    lcd.setTextColor(SSD1306_WHITE);     
    lcd.display();
    pinMode(wlevp,INPUT);
    pinMode(dhtp,INPUT);
    pinMode(smoip,INPUT);
    pinMode(ldrp,INPUT);
    pinMode(rainp,INPUT);
    pinMode(wpumpp,OUTPUT);
    pinMode(ind1,OUTPUT);
    pinMode(ind2,OUTPUT);
    pinMode(ind4,OUTPUT);
    pinMode(ind5,OUTPUT);
    pinMode(buzz,OUTPUT);
}


void loop() 
{
  int wlev,tem,hum,smoi,rain,ldr,buz;
  wlev = analogRead(wlevp);
  tem = dht.readTemperature();
  hum = dht.readHumidity();
  smoi = analogRead(smoip);
  rain = digitalRead(rainp);
  ldr = analogRead(ldrp);
  buz=0;
  lcd.display();
  lcd.clearDisplay();
  lcd.setCursor(0, 0);
  if(wlev>=70)
  {
    lcd.println("waterlev :High");
  }
  else if (wlev>=500)
  {
     lcd.println("waterlev :Medium");
  }
  else
  {
    lcd.println("waterlev :Low");
  } 
  lcd.setCursor(0, 25);
  lcd.println("temperature ");
  lcd.println(tem);
  delay(1000);
  lcd.display();
  lcd.clearDisplay();
  lcd.setCursor(0,0);
  lcd.println("humidity ");
  lcd.println(hum);
  lcd.setCursor(0,25);
  lcd.println("soilmoist");
  lcd.println(smoi);
  delay(1000);
  lcd.display();
  lcd.clearDisplay();
  lcd.setCursor(0,0);
 
  lcd.setCursor(0,25);
  if(rain==0)
  {
    lcd.println("Rain");
  }
  else
  {
    lcd.println("not rain");
  }
  delay(1000);
  lcd.display();
  lcd.clearDisplay();
  lcd.setCursor(0,0);
  lcd.println("light intensity");
  lcd.setCursor(0,25);
  lcd.println("level:");
  lcd.println(ldr);
  if(smoi<= 30)
  {
    digitalWrite(wpumpp, HIGH);
  }
  else
  {
    digitalWrite(wpumpp, LOW);
  }
  if(wlev<=300)
  {
    digitalWrite(ind1, HIGH);
    buz=1;
  }
  else
  {
    digitalWrite(ind1,LOW);
  }
  if(tem>=52 || smoi<=300 || hum<=30)
  {
    digitalWrite(ind2 , HIGH);
    buz=1;
  }
  else
  {
    digitalWrite(ind2 , LOW);
  }
  
  if(ldr>=1000)
  {
    digitalWrite(ind4 ,HIGH);
    buz=1;
  }
  else
  {
    digitalWrite(ind4, LOW);
  }
  if(rain==0)
  {
    digitalWrite(ind5, HIGH);
    buz=1;
  }
  else
  {
    digitalWrite(ind5, LOW);
  }
  if(buz==1)
  {
    digitalWrite(buzz, HIGH);
  }
  else
  {
    digitalWrite(buzz , LOW);
  }
  delay(1000);
  //Serial.print("wlev,tem,hum,smoi,rain,ldr");
  Serial.print(wlev);
  Serial.print(",");
  Serial.print(tem);
  Serial.print(",");
  Serial.print(hum);
  Serial.print(",");
  Serial.print(smoi);
  Serial.print(",");
  Serial.print(rain);
  Serial.print(",");
  Serial.print(ldr);
  Serial.print("\n");

}