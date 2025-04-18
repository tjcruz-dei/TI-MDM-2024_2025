import mqtt.*;
MQTTClient client;
String ID="Bananablaster1K";
// CHANGE THE ID FOR YOUR UNIQUE CLIENT

void setup() {
  client = new MQTTClient(this);
  //First parameter is the server, the second is an unique client ID string
  //client.connect("mqtt://public:public@public.cloud.shiftr.io",ID+String.valueOf(System.currentTimeMillis()));
  
  //example for broker with no auth required
  client.connect("mqtt://broker.emqx.io",ID+String.valueOf(System.currentTimeMillis()));
 
  client.subscribe("exampleXPTO");
}

void draw() {}

void keyPressed() {
  client.publish("helloXPTO", "world");
}

void messageReceived(String topic, byte[] payload) {
  println("new message: " + topic + " - " + new String(payload));
}
