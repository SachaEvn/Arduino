#include <LiquidCrystal.h>
LiquidCrystal lcd(15,14,4,5,6,7);

void setup() {
  lcd.clear();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  char mot = "Hello";
}
// Meme fonctionnement que les languages orientés objets

void loop(){
  int i = 0;
  bool sens = false;
  while (1){
    if (i % 11 == 0){
      sens = !sens;
    }
    lcd.setCursor(i,0);
    lcd.print("Hello");
    if (sens == true){
      i++;
    }
    if (sens == false){
      i--;
    }
    delay(500);
    lcd.clear();
  }
}
