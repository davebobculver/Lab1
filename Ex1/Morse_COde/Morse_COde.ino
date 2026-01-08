// Lab 1 Ex 1
#define LED_PIN 13

void setup() {

pinMode(LED_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(LED_PIN, HIGH); // Turn on LED
delay(300); //wait 300 ml sec

digitalWrite(LED_PIN, LOW); //turn off led
delay(300);

} 
