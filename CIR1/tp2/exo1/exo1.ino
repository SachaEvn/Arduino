char compteur = 0; //var global accessible depuis ttes les fonctions
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Bonjour");
}

void loop() {
  // put your main code here, to run repeatedly:
  compteur+=1;
  if(compteur%10 == 0){
    Serial.println('*');
    
  }
  else{
    Serial.print('*');
  }
  
  
  delay(1000);
}
