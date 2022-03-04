#include <LiquidCrystal.h>
LiquidCrystal lcd(15,14,4,5,6,7);
void setup() {
  // put your setup code here, to run once:
  lcd.clear();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Hello");
  lcd.setCursor(10,1);
  lcd.print("World!"); 
}

void loop() {
  // put your main code here, to run repeatedly:

}
//ce langage appartient à la catégorie de langages orientés objets
