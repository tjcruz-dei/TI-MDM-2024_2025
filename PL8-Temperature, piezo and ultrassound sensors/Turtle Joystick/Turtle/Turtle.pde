import processing.serial.*;

Serial myPort;      
PVector turtle;

void setup() {
  size(800,800);
  //change to match your port
  println(Serial.list());
  String portName = Serial.list()[2]; 
  myPort = new Serial(this, portName, 9600); 
  myPort.bufferUntil('\n');
  myPort.clear();
  turtle= new PVector(width/2,height/2);
}

void draw(){
  turtle.x = constrain (turtle.x, 0, width);
  turtle.y = constrain (turtle.y, 0, height);
  ellipse(turtle.x,turtle.y,10,10); 
}

void serialEvent( Serial myPort) {
  String[] SP=null;
  String val;
  
  try{
    val = myPort.readString();
    //println(val);
    
    if (val!=null)
     SP=split(val.strip(),':');
     PVector joyDir=new PVector();
     
     if ((SP!=null) && (SP.length==2))  {
       joyDir.x=(int(SP[0])/512.0)*5;
       joyDir.y=(int(SP[1])/512.0)*5;
       turtle.add(joyDir);   
     }
  } catch (Exception e) {
            e.printStackTrace(); 
  }
}
