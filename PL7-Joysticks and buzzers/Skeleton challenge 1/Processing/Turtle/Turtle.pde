import processing.serial.*;

Serial myPort;  
String val;     
PVector heading;
PVector turtle;

void setup() {
  size(800,800);

  String portName = Serial.list()[1]; //change to match your port
  myPort = new Serial(this, portName, 9600); 
  myPort.bufferUntil('\n');
  myPort.clear();
  
  heading= new PVector(1,0);
  turtle= new PVector(400,400);
}

void draw(){
  ellipse(turtle.x,turtle.y,10,10);
  turtle.add(heading);
}

void serialEvent( Serial myPort) {
  try {
    val = myPort.readStringUntil('\n');
    
    String SP=trim(val);
    if (SP!=null) {
      //your stuff here
    }
  } catch (Exception e) {
            e.printStackTrace(); 
  }
}
