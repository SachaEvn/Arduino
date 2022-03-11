#include <LiquidCrystal.h>
#define btnRed 8
#define btnOrange 9 
#define btnGreen 2

LiquidCrystal lcd(15,14,4,5,6,7);

int h = 0;
int m = 0;
int s = 0;
int dec = 0;
long startTime;
long currentTime;
long millisTime;
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
    bool isPaused = true;
    
    while(true){
      if(digitalRead(btnOrange) == LOW){
        isPaused = true;
      }
      else if(digitalRead(btnRed) == LOW){
        if(isPaused == true){
          isPaused = false;
          startTime = millis();
        }
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
      else{
        h = 0;
        m = 0;
        s = 0;
        dec = 0;
      }
      if(isPress && isPaused){
        lcd.setCursor(0,1);
        lcd.print("diff(s):"+String(millisTime));
        millisTime = 0;
        currentTime = 0;
        startTime = millis();
        m = 0;
        s = 0;
      }
      else if(isPress && !isPaused){
        lcd.setCursor(0,1);
        millisTime = millis();
        millisTime = (millisTime -startTime)/1000;
        currentTime = (h*3600+m*60+s+dec*0.1);
        lcd.print(millisTime - currentTime);
      }
      
      lcd.setCursor(0,0);
      char str[16];
      sprintf(str,"%02d:%02d:%02d:%d",h,m,s,dec);  
      lcd.print(str);
      delay(100);
      lcd.clear();
    }
    
  }
  // notre programme accumule environ 1s de retard par rapport à millis toutes les 10 secondes (comptées par le programme)
  // on mesure environ 6s de retard au bout d'une minute
  // on mesure environ 16.5s de retard au bout de trois minutes
