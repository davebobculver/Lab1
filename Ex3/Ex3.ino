#define LED 13
#define BUTTON 22



void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

int state = LOW; // all vales to make a functioning button press
int lastval = LOW;
int val = LOW;
int bl = 300;

void loop() {

val =  digitalRead(BUTTON); // Read the button input
if (lastval != val){

if (state==HIGH){ //turn off light on press if it was already high
state = LOW;
digitalWrite(LED,state);
delay(bl);
}
else if (state == LOW){ //turn on light if it was LOW
state = HIGH;
digitalWrite(LED,HIGH);
delay(bl);

}
}
lastval = LOW;
}

