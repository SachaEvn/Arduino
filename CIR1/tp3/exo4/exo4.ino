#include <LiquidCrystal.h>
#define btn 2
#define ledRed 8

LiquidCrystal lcd(15,14,4,5,6,7);



const byte interrupt = 3;
volatile bool state = false;

char message[13] = "ISEN ARDUINO";


void pressed(){
  state = !state;
  digitalWrite(ledRed,state);
}

void setup() {
  pinMode(2, INPUT);
  pinMode(8,OUTPUT);
  lcd.begin(16,2);
  attachInterrupt(0,pressed,FALLING);
}

void loop(){
   lcd.setCursor(0,0);
   if(!state){
     for(int i =0;i<12;i++){
       lcd.print(message[i]);
       delay(1000);
     }
     delay(3000);
     lcd.clear();
   }
 }
