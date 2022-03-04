#include <LiquidCrystal.h>
#define btn 2
LiquidCrystal lcd(15,14,4,5,6,7);



const byte interrupt = 3;
volatile int counter = 0;
volatile bool isPress = false;




void pressed(){
  counter +=1;
  isPress = true;
}

void setup() {
  pinMode(2, INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Counter : "+String(counter));
  attachInterrupt(0,pressed,FALLING);
}

void loop(){
    if(isPress){
      delay(100);
      lcd.setCursor(0,0);
      lcd.print("Counter : "+String(counter));
      isPress = false;
      
    }
 }
