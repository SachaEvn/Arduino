
void setup() {
  // put your setup code here, to run once:
  #define LED_VERTE 2
}

void ledOnForTiming(int port_led,int timing) {
  pinMode(port_led,OUTPUT);
  digitalWrite(port_led,HIGH);
  delay(timing*1000);
  digitalWrite(port_led,LOW);
  delay(timing*1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  ledOnForTiming(LED_VERTE,2);

}
