#define LED  5

void setup() {
 pinMode(LED, OUTPUT);
}

int i = 0 ;

void loop() {

int bright = sin(((float) i)/100.00)*255; // this is the brightness of the blub
analogWrite(LED, bright); // setting brightness
i+=1; // adding 1 during loop
delay(10); // making it pause
i %= 314; // setting period to blink well. 

}
// for (i=0; i<10000; i++){
// analogWrite(LED,cos(((float) i )/ 100.00 ));
