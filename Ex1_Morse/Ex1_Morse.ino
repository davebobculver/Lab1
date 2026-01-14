// MORSE CODE
#define LED 13

int dotl = 300; //time for a dot (dot length)
int dahl = 900; //time for a dash (dash length)

void setup() {  // Sets the pin mode
  pinMode(LED, OUTPUT);
}

void blink(int on, int off) // Defines blink feature
{
digitalWrite(LED,HIGH); // Turn on the blink
delay(on); // wait for an amount of time
digitalWrite(LED, LOW); //turn off the blinking
delay(off);
}

void dash(){ //dash length
blink(dahl,dotl); //on for a dash, off for a dot
}

void dot(){ // dot lenght
blink(dotl,dotl);
}


void sl(){ // space between letters; including off time of dah and dot
delay(dahl-dotl); 
}

void sw(){ // space between words
 delay(dotl*7);
}

void loop() { // This spell 'jazz' in morse code
  dot(); dash(); dash(); dash(); sl();
  dot(); dash(); sl();
  dash(); dash(); dot(); dot(); sl();
  dash(); dash(); dot(); dot(); sw();

}
