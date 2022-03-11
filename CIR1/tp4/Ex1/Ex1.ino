#include<LiquidCrystal.h>                        // Including lcd display library
LiquidCrystal lcd(15,14,4,5,6,7);           // Define LCD display pins RS,E,D4,D5,D6,D7
int analogPin = A3;                         //VALEUR MIN ET MAX: 0-1023 for 10 bits or 0-4095 for 12 bits

void setup()                                                      

{
  lcd.begin(16,2);                              //  setting LCD as 16x2 type
  lcd.setCursor(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(analogPin);
  lcd.setCursor(0,0);
  lcd.print(val);
  
  int volt = map(val, 0, 1023, 0, 5);
  lcd.setCursor(8,0);
  lcd.print(volt);

  lcd.setCursor(0,1);
  int bar = map(val, 0, 1023, 0, 16);
  for(int i = 0; i<bar ;i++){
    lcd.setCursor(i,1);
    lcd.print("=");
  }
  delay(200);
  lcd.clear();
}
