#define LED_ROUGE 8 
#define LED_ORANGE 9 
#define BTN 2 
#define LED_BLEUE 3

// Le programme fait clignoter la led rouge et la led orange de l'arduino
void setup() {                    // Initialisation des variables, ici en fonction des pins
  pinMode(LED_ROUGE, OUTPUT);     // Initialisation des LEDs en fonction des pins de la carte, ici led rouge, sortie 8
  pinMode(LED_ORANGE, OUTPUT);    // Meme chose pour a led orange, sortie 9
  pinMode(BTN, INPUT);
  pinMode(LED_BLEUE, OUTPUT);
  //exo(LED_ROUGE, 1);

} 


int exo(bool test){
  if (test == true) {
      digitalWrite(LED_BLEUE, HIGH);
      delay(500);
      digitalWrite(LED_BLEUE, LOW);
      digitalWrite(LED_ORANGE, HIGH);
      delay(500);
      digitalWrite(LED_ORANGE, LOW);
      digitalWrite(LED_ROUGE, HIGH);
      delay(500);
      digitalWrite(LED_ROUGE, LOW);
  }
  else if (test == false) {
      digitalWrite(LED_ROUGE, HIGH);
      delay(500);
      digitalWrite(LED_ROUGE, LOW);
      digitalWrite(LED_ORANGE, HIGH);
      delay(500);
      digitalWrite(LED_ORANGE, LOW);
      digitalWrite(LED_BLEUE, HIGH);
      delay(500);
      digitalWrite(LED_BLEUE, LOW);
    }
}

bool pos = true;
void loop() {                       // Fonction loop, qui effectura les actions en boucle
   if (digitalRead(BTN)== LOW){
      pos = !pos;
   }
   exo(pos);
}
