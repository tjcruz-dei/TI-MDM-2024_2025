    
PVector heading;
PVector turtle;
long count=0;

void setup() {
  size(800,800);
  
  heading= new PVector(1,0);
  turtle= new PVector(400,400);
}

void draw(){
  ellipse(turtle.x,turtle.y,10,10);
  turtle.add(heading);
  if (count==0) heading.rotate(random(-10,10));
  count=(count+1)%100;
  println(count);
}
