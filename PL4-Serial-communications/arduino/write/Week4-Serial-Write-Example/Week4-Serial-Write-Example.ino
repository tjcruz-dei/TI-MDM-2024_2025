/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 4
* Example serial communication with Arduino (write)
* 
* @since:   03–03–2023      
* @based:   https://www.arduino.cc/en/Tutorial/BuiltInExamples/ASCIITable
*/

void setup() {
  // Initialize serial data rate (bits per second) and wait for port to open
  Serial.begin(9600); 

  // wait for serial port to connect. Needed for native USB port only (Leonardo only)
  while (!Serial) {
    ; 
  }
}

void loop() {
  Serial.println("123");
}
