#include <LiquidCrystal.h>
LiquidCrystal lcd(15,14,4,5,6,7);
byte smiley[8]={
    B00000,
    B00000,
    B01010,
    B00000,
    B00000,
    B10001,
    B01110,
    B00000
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.clear();
  lcd.createChar(2,smiley);
  lcd.setCursor(0,0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  int j = 0;
  bool sens = false;
  bool hauteur = true;
  while (1){
    if (i % 15 == 0){
      sens = !sens;
    }
    if(hauteur == true){
      j = 1;
    }
    if(hauteur == false){
      j = 0;
    }
    lcd.setCursor(i,j);
    lcd.write(2);
    if (sens == true){
      i++;
      hauteur = !hauteur;
    }
    if (sens == false){
      hauteur = !hauteur;
      i--;
    }
    delay(200);
    lcd.clear();
  }

}
