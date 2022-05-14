#include <IRremote.h>
const int RECV_PIN = 8; 
IRrecv irrecv (RECV_PIN); 
decode_results results;

void setup() {
pinMode (12, OUTPUT);
pinMode (11, OUTPUT);
pinMode (10, OUTPUT);
Serial.begin(9600); 
irrecv.enableIRIn();
irrecv.blink13 (true);
}
void loop() {
if (irrecv.decode (&results)) {
Serial.println (results.value);
long unsigned int g=results.value;
Serial.println (g); 
irrecv.resume ();
if (g==16582903)
{
digitalWrite(12, HIGH);
}
if (g==16615543)
{
digitalWrite (11, HIGH);
}
if (g==16599223)
{
digitalWrite (10, HIGH);
}
if (g==16591063)
{
digitalWrite (12, LOW);
}
if (g==16623703)
{
digitalWrite (11, LOW);
}
if (g==16607383)
{
digitalWrite (10, LOW);
}
}
}