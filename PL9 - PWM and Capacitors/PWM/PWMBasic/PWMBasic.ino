
int ledPin = 9; // LED connected to pin 9 (with PWM capabilities)
int i = 0; // We will use this to count up and down

void setup() {
 pinMode(ledPin, OUTPUT);
}

void loop() {
for (i=0; i<255; i++){// loop from 0 to 254 to fade in
  analogWrite(ledPin, i); // set the led brightness
  delay(10); // wait 10ms because analogWrite is instantaneous
}
for (i=255; i>0; i--){// loop from 0 to 254 to fade in
  analogWrite(ledPin, i); // set the led brightness
  delay(10); // wait 10ms because analogWrite is instantaneous
}
}
