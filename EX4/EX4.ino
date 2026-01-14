#define RES A5
#define LED 3

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  // put your setup code here, to run once:

}
float res = 0; // what the value of the resistance is
int res_print = 0; // check to time when to pring resistance in serial

void loop() {
  // put your main code here, to run repeatedly:
res = analogRead(RES); // Read the resistivity

if (res_print% 5000 == 0) { // delay built in by clock
Serial.print("RES ");
Serial.println((int) res); // print current state of resistance
}

res = (res/1024)*255; // scale analog out to 0-255
if (res <= 0 ){res = 0;}
analogWrite(LED, (int) res); // turn on LED

res_print += 1;

}
