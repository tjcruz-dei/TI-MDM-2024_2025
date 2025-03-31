#define ButtonX A0 //0 would also work
#define ButtonY A1 //1 would also work
const long CALIBRATION_TIME = 10000;

long ellapsed;
int maxX=0,maxY=0,minX=1024,minY=1024;

void setup() {    
   Serial.begin (9600);
   ellapsed=millis();

   //Serial.println("Callibrating for still position");
   //Calibração – máximos e mínimos em repouso
   while ((millis()-ellapsed)<CALIBRATION_TIME){
   // X e Y are local
     int X = analogRead(ButtonX); 
     int Y = analogRead(ButtonY); 
     if (X>maxX) maxX=X;  
     if (X<minX) minX=X;
     if (Y>maxY) maxY=Y;
     if (Y<minY) minY=Y;
   }
   //Serial.println("End of Callibration");
 } 

void loop() {   
   if (millis()-ellapsed>100){  
     int X = analogRead(ButtonX); 
     int Y = analogRead(ButtonY); 
     int XSend=0, YSend=0;

     ellapsed=millis();
     
     if ((X<minX) || (X>maxX))
      XSend=X-512;
     
     if ((Y<minY) || (Y>maxY)) 
      YSend=Y-512;
   
     Serial.println(String(XSend)+":"+String(YSend));
   }
}
