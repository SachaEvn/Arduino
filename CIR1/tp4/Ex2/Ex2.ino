#include<LiquidCrystal.h>                        // Including lcd display library
LiquidCrystal lcd(15,14,4,5,6,7);           // Define LCD display pins RS,E,D4,D5,D6,D7
int analogPin = A3;                         //VALEUR MIN ET MAX: 0-1023 for 10 bits or 0-4095 for 12 bits
int LEDB = 3;
int LEDO = 9;
int LEDR = 8;

void setup()                                                      

{
  pinMode(LEDB, OUTPUT);     
  pinMode(LEDO, OUTPUT); 
  pinMode(LEDR, OUTPUT);
  lcd.begin(16,2);                              //  setting LCD as 16x2 type
  lcd.setCursor(0,0);
  //int seed = randomSeed(micros());
  
}
int alea = random(1023);


void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(analogPin);
  lcd.setCursor(0,0);
  lcd.print(val);
  lcd.setCursor(10,0);
  lcd.print(alea);
  
  lcd.setCursor(0,1);
  lcd.print(abs(alea - val));
  
  if ((abs(alea - val) < 5) && (abs(alea - val) >= 0)){
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDO, LOW);
    digitalWrite(LEDB, LOW);
  }
  else if ((abs(alea - val) < 15) && (abs(alea - val) >= 0)){
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDO, HIGH);
    digitalWrite(LEDB, LOW);
  }
  else if ((abs(alea - val) < 50) && (abs(alea - val) >= 0)){
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDO, LOW);
    digitalWrite(LEDB, HIGH);
  }
  else{
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDO, LOW);
    digitalWrite(LEDB, LOW);
  }


  delay(200);
  lcd.clear();
}
