
#include <WiFi.h>
#include <PubSubClient.h>

// Define random ID
String ID_MQTT;
char *letters = "abcdefghijklmnopqrstuvwxyz0123456789";

// Wi-Fi settinges
const char *SSID = "iMinion 15";
const char *PASSWORD = "cerealkiller";

const char* TOPIC_TESTPUB="sensor/TX_01LDR";
const char* TOPIC_TESTSUB="sensor/D4_01ABC";

// Define MQTT Broker and PORT
//broker.hivemq.com can be another alternative for a public broker
const char *BROKER_MQTT = "broker.emqx.io";
int BROKER_PORT = 1883;
const char* password =  "public";
const char* user =  "public";

WiFiClient espClient;
PubSubClient MQTT(espClient); 

unsigned long lastMillis = 0;

// Starts the Wi-Fi
void startWifi(void) {
  reconnectWiFi();
}

// Starts everything from MQTT
void initMQTT(void) {
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);
  MQTT.setCallback(callbackMQTT);
}

// Callback --- Get the messages here
void callbackMQTT(char *topic, byte *payload, unsigned int length) {
  String msg;

  // Convert payload to string
  for (int i = 0; i < length; i++) {
    char c = (char)payload[i];
    msg += c;
  }

  Serial.printf("Topic: %s\n", topic);
  Serial.printf("Message: %s\n", msg, topic);

  digitalWrite(15,msg=="true");
}

// Connects to the Broker with a specific random ID
void reconnectMQTT(void) {
  while (!MQTT.connected()) {
    ID_MQTT = "";
    Serial.print("* Starting connection with broker: ");
    Serial.println(BROKER_MQTT);

    int i = 0;
    for (i = 0; i < 10; i++) {
      ID_MQTT = ID_MQTT + letters[random(0, 36)];
    }

    //(MQTT.connect(ID_MQTT.c_str()),"user","password")
    if (MQTT.connect(ID_MQTT.c_str())) {
      Serial.print("* Connected to broker successfully with ID: ");
      Serial.println(ID_MQTT);
      MQTT.subscribe(TOPIC_TESTSUB);
    } else {
      Serial.println("* Failed to connected to broker. Trying again in 2 seconds.");
      delay(2000);
    }
  }
}

// Checks both Wi-Fi and MQTT state, and reconnects if something failed.
void checkWiFIAndMQTT(void) {
  if (!MQTT.connected())
    reconnectMQTT();
  reconnectWiFi();
}

void reconnectWiFi(void) {
  if (WiFi.status() == WL_CONNECTED)
    return;

  WiFi.begin(SSID, PASSWORD); // Conecta na rede WI-FI

  Serial.print("* Connecting to Wifi ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("* Successfully connected to Wi-Fi, with local IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  pinMode(15,OUTPUT);
  
  Serial.println("Start");

  startWifi();
  initMQTT();
}

void loop() {
  // publish a message roughly every second.
  if (millis() - lastMillis > 100) {
    checkWiFIAndMQTT();
    int LDR = analogRead(35);  
    lastMillis = millis();
    MQTT.publish(TOPIC_TESTPUB, String(LDR).c_str());
  }
  MQTT.loop();
}
