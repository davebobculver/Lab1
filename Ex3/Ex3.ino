#define LED 13
#define BUTTON 22



void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

int state = LOW;
int lastval = LOW;
int val = LOW;
int bl = 300;

void loop() {

val =  digitalRead(BUTTON); // Read the button input
if (lastval != val){
if (state==HIGH){
state = LOW;
digitalWrite(LED,state);
delay(bl);
}
else if (state == LOW){
state = HIGH;
digitalWrite(LED,HIGH);
delay(bl);

}
}
lastval = LOW;
}

