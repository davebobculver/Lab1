#define LED 11
#define BUTTON 4

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}


float outval = 0; unsigned long tbut = 0; unsigned long tnow = 0; unsigned long tdiff = 0;
int dim = HIGH; int off = LOW;
int state = LOW;
int lastval = LOW;
int val = LOW;
int bl = 50;

void loop() {
val = digitalRead(BUTTON);

if (lastval == LOW && val == HIGH){// Button Press

tbut = millis();
Serial.print("Button press at ");
Serial.println(tbut);

if (off == HIGH){ // Turn of LED if in off mode
digitalWrite(LED,LOW); //Turns off LED  if secodn let go of button
}

delay(bl);
}

if (val == HIGH && dim == HIGH){
if (outval >= 255){outval =255;}
outval += .005;
analogWrite(LED, ((int) (outval)));
}



if (lastval == HIGH && val == LOW){// start turn off if statement

tnow = millis();
tdiff = tnow-tbut;
Serial.print("Button held for ");
Serial.println(tdiff);
Serial.print("Brightness of ");
Serial.println((int) outval);
Serial.print("Button off at ");
Serial.println(tnow);
delay(bl); // Switch Bounce


if (off == HIGH){
off = LOW;
dim = HIGH;
}

else if (dim == HIGH){ //Switch if on dimming mode or turning off mode
off = HIGH;
dim = LOW;
outval =0;
}

}//End switch off if statement

lastval = val;
}

