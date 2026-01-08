#define RES A5
#define LED 11

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  // put your setup code here, to run once:

}
float res = 0;
void loop() {
  // put your main code here, to run repeatedly:
res = analogRead(RES); // Read the resistivity
Serial.print("RES ");
Serial.println((int) res); // print current state of resistance

res = res/4; // Make blink with brightnes
analogWrite(LED, (int) res);

}
