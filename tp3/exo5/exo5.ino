#include <LiquidCrystal.h>
#define btnRed 8
#define btnOrange 9 
#define btnGreen 2

LiquidCrystal lcd(15,14,4,5,6,7);

int h = 0;
int m = 0;
int s = 0;
int dec = 0;
bool isPress = false;
void pressed(){
  
  isPress = !isPress;
  
}

void setup() {
  lcd.clear();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  pinMode(btnRed, INPUT);
  pinMode(btnOrange,INPUT);
  pinMode(btnGreen, INPUT);
  attachInterrupt(0,pressed,FALLING);

}

void loop(){
    //rouge -> démarre et reprends après la pause
    //orange -> reset le chrono
    //vert -> affiche sur une deuxieme ligne le temps mesuré par millis vs par le chrono
    /*
    int h = 0;
    int m = 0;
    int s = 0;
    int dec = 0;
    */
    bool isPaused = true;
    
    while(true){
      if(digitalRead(btnOrange) == LOW){
        h = 0;
        m = 0;
        s = 0;
        dec = 0;
        isPaused = true;
      }
      else if(digitalRead(btnRed) == LOW){
        isPaused = false;
      }
      if(isPress){
        lcd.setCursor(0,1);
        long millisTime = millis();
        /*
        lcd.print("m:"+String(millisTime));
        lcd.print(" p:"+String(totalChrono));
        */
        long currentTime = h*3600+m*60+s;
        lcd.print("diff(s):"+String(millisTime/1000 - currentTime));
      }
      if(!isPaused){
        
        dec+=1;
        if(dec%10 == 0 && dec!=0){
          s+=1;
          dec = 0;
          if(s%60 == 0 && s != 0){
            m+=1;
            s=0;
            if(m%60 == 0 && m!=0){
              h+=1;
              m=0;
            }
          }
        }
      }
      lcd.setCursor(0,0);
      char str[16];
      sprintf(str,"%02d:%02d:%02d:%d",h,m,s,dec);  
      lcd.print(str);
      delay(100);
      lcd.clear();
    }
    
  }
