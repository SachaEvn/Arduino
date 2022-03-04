#define RED 8
#define ORANGE 9
#define GREEN 2

long currentTime=0;
long previousTime=0;

long interval,interval1=500, interval2=2000;
bool ledState=LOW;

struct led{
  long previousTime;
  long interval;
  bool ledState;
};

void setup() {
  Serial.begin(9600);
  pinMode(RED,OUTPUT);
  pinMode(ORANGE,OUTPUT);
  pinMode(GREEN,OUTPUT);
}
void loop() {
  long startMil = millis();
  struct led Red = {startMil,700,LOW};
  struct led Orange = {startMil,1300,LOW};
  struct led Green = {startMil,1700,LOW};
  while(true){
    
    long currentTime = millis();
    if(currentTime - startMil == 5000){
      Serial.print("\n-----------------");
      Serial.print("Atm : 5 seconds");
      Serial.print(F("RED State : "));
      Serial.println(Red.ledState);
      Serial.print(F("Orange State : "));
      Serial.println(Orange.ledState);
      Serial.print(F("Green State : "));
      Serial.println(Green.ledState);
      Serial.print("-----------------\n");
      }
    if((currentTime - Red.previousTime)>Red.interval){
      Red.previousTime = currentTime;
      Red.ledState = !Red.ledState;
      digitalWrite(RED,Red.ledState);
      Serial.print(F("RED State : "));
      Serial.println(Red.ledState);
    }
    if((currentTime - Orange.previousTime)>Orange.interval){
      Orange.previousTime = currentTime;
      Orange.ledState = !Orange.ledState;
      digitalWrite(ORANGE,Orange.ledState);
      Serial.print(F("Orange State : "));
      Serial.println(Orange.ledState);
    }
    if((currentTime - Green.previousTime)>Green.interval){
      Green.previousTime = currentTime;
      Green.ledState = !Green.ledState;
      digitalWrite(GREEN,Green.ledState);
      Serial.print(F("Green State : "));
      Serial.println(Green.ledState);
    }
  }
}


//ce programme allume la led orange pendant deux secondes, puis l'éteint pendant 0.5 secondes. En boucle.
