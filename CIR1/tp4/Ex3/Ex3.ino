#include<LiquidCrystal.h>                        // Including lcd display library
LiquidCrystal lcd(15,14,4,5,6,7);           // Define LCD display pins RS,E,D4,D5,D6,D7
int tempPin = A2;                         //VALEUR MIN ET MAX: 0-1023 for 10 bits or 0-4095 for 12 bits
int analogPin = A3;   
int LEDR = 8;

void setup()                                                      
{
  pinMode(LEDR, OUTPUT);
  lcd.begin(16,2);                              //  setting LCD as 16x2 type
  lcd.setCursor(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(analogPin);
  val = map(val, 0, 1023, 0, 40);

  int temp = (5.0 * analogRead(tempPin) * 100.0) / 1024;
  lcd.setCursor(0,0);
  lcd.print(temp);

  lcd.setCursor(10,0);
  lcd.print(val);
  
  if (val > temp){
    digitalWrite(LEDR, HIGH);
  }
  else{
    digitalWrite(LEDR, LOW);
  }

  delay(200);
  lcd.clear();
}
