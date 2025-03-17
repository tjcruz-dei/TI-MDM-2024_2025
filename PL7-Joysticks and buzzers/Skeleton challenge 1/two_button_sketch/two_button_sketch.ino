#define ButtonA 6
#define ButtonB 7

long ellapsed;

void setup() { 
  pinMode (ButtonA,INPUT_PULLUP);
  pinMode (ButtonB,INPUT_PULLUP);
  Serial.begin (9600);
  ellapsed=millis(); 
}

void loop() {
  if (millis()-ellapsed>50){
     bool R = !digitalRead(ButtonA); 
     bool L = !digitalRead(ButtonB);

     ellapsed=millis();
     if (R && L)
          Serial.println('X');
     else {
          if (R) Serial.println('R');
          if (L) Serial.println('L');
     }
  }
}
