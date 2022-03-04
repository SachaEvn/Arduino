#define LED_ROUGE 8 //on indique le port correspondant aux leds colorés sur la plaquette
  #define LED_ORANGE 9 
  #define LED_VERTE 2  
  #define LED_BLEU 3
  
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_ROUGE, OUTPUT); //on configure le port 8 comme une sortie, on lui envoit un/des signaux
  pinMode(LED_ORANGE, OUTPUT); //idem pour le port 9
  pinMode(LED_VERTE,OUTPUT);
  pinMode(LED_BLEU,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //feu temporaire : 
  clignotte(9,0.5,0.5,6);
  clignotte(9,2,0,1);
  clignotte(8,6,0,1);
}

void clignotte(int pin,int tempsOn,int tempsOff,int cycles){
  for(int i =0;i<cycles;i++){
    digitalWrite(pin,HIGH);
    delay(tempsOn*1000);
    digitalWrite(pin,LOW);
    delay(tempsOff*1000);
  }
}
