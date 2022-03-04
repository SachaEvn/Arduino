//test
#define LED_ROUGE 8 //on indique le port correspondant aux leds colorés sur la plaquette
#define LED_ORANGE 9 
#define LED_VERTE 2  
#define LED_BLEU 3
//ce programme fait clignotter certaines leds
void setup() { 
  pinMode(LED_ROUGE, OUTPUT); //on configure le port 8 comme une sortie, on lui envoit un/des signaux
  pinMode(LED_ORANGE, OUTPUT); //idem pour le port 9
  pinMode(LED_VERTE,OUTPUT);
  pinMode(LED_BLEU,OUTPUT);
  } 


void loop() { 
  digitalWrite(LED_ROUGE, HIGH); //on envoie un signal "high" à la led rouge, l'allumant
  digitalWrite(LED_ORANGE, HIGH); //pareil pour la led orange
  digitalWrite(LED_VERTE,LOW);
  digitalWrite(LED_BLEU,LOW);
  
  delay(1000);  //attente d'une seconde avant de passer à la prochaine instruction
  digitalWrite(LED_ROUGE, LOW); //on passe la led rouge à "low", l'éteignant
  digitalWrite(LED_ORANGE, LOW); //encore pareil pour la led orange
  digitalWrite(LED_VERTE,HIGH);
  digitalWrite(LED_BLEU,HIGH);
  delay(1000); //attente d'une seconde avant de revenir au début de la boucle
  }
