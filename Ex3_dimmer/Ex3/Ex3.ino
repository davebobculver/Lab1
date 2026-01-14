#define LED 11
#define BUTTON 4

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}


float outval = 0; unsigned long tbut = 0; unsigned long tnow = 0; unsigned long tdiff = 0; //timing variables
int dim = HIGH; int off = LOW; //used in making light stay on after button release, or turning of on button press
int state = LOW;
int lastval = LOW;
int val = LOW;
int bl = 50;

void loop() {
val = digitalRead(BUTTON);

if (lastval == LOW && val == HIGH){// Button Press

tbut = millis(); // start timing
Serial.print("Button press at ");
Serial.println(tbut);

if (off == HIGH){ // Turn of LED if in off mode
digitalWrite(LED,LOW); //Turns off LED  if secodn let go of button
}

delay(bl); // switch bounce
}

if (val == HIGH && dim == HIGH){ //check to increase brightness per loop
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


if (off == HIGH){ // turn to diming mode of off mores
off = LOW;
dim = HIGH;
}

else if (dim == HIGH){ //Switch if on dimming mode or turning off mode
off = HIGH;
dim = LOW;
outval =0;
}

}//End switch off if statement

lastval = val; // check for button press
}

