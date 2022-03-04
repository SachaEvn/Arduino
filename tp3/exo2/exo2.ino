#define LED 9
 long currentTime=0;

 long previousTime=0;

 long interval,interval1=500, interval2=2000;

 bool ledState=LOW;
void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}
void loop() {
  currentTime=millis();
  if(ledState){
    interval=interval2;
  }
  else{
    interval=interval1;
  }
  if((currentTime-previousTime)>interval){
    previousTime=currentTime;
    ledState=!ledState;
    digitalWrite(LED,ledState);
    Serial.print(F("LED State : "));
    Serial.println(ledState);
  }
}


//ce programme allume la led orange pendant deux secondes, puis l'éteint pendant 0.5 secondes. En boucle.
