#include "painlessMesh.h"
#include <PubSubClient.h>

// Mesh Settings (Keep it equal on client)
#define MESH_PREFIX "whateverYouLike"
#define MESH_PASSWORD "somethingSneaky"
#define MESH_PORT 5555

// Wifi settings
#define STATION_SSID "WIFI_SSID"
#define STATION_PASSWORD "WIFI_PASSWORD"

// MQTT Broker
IPAddress mqttBroker(192, 168, 0, 101);

Scheduler userScheduler; // to control your personal task
painlessMesh mesh;
IPAddress myIP(0, 0, 0, 0);

// Prototype
void receivedCallback(uint32_t from, String &msg);
IPAddress getlocalIP();
// create a random host name
String HOSTNAME = "ESP8266Client-" + String(random(0xffff), HEX);

// Wifi client
WiFiClient wifiClient;
// Pubsub client
PubSubClient mqttClient(mqttBroker, 1883, NULL, wifiClient);

// Send my ID every 10 seconds to inform others
Task logServerTask(10000, TASK_FOREVER, []() {
  DynamicJsonDocument msg(1024);
  msg["topic"] = "logServer";
  msg["nodeId"] = mesh.getNodeId();

  String str;
  serializeJson(msg, str);

  mesh.sendBroadcast(str);

  // log to serial
  serializeJson(msg, Serial);
  Serial.printf("\n");
});

void setup()
{
  Serial.begin(115200);

  //mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC | COMMUNICATION | GENERAL | MSG_TYPES | REMOTE | DEBUG ); // all types on
  //mesh.setDebugMsgTypes( ERROR | CONNECTION | SYNC | S_TIME );  // set before init() so that you can see startup messages
  mesh.setDebugMsgTypes(ERROR | CONNECTION | S_TIME); // set before init() so that you can see startup messages

  mesh.init(MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT, WIFI_AP_STA, 6);
  mesh.onReceive(&receivedCallback);

  mesh.onNewConnection([](size_t nodeId) {
    Serial.printf("New Connection %u\n", nodeId);
  });

  mesh.onDroppedConnection([](size_t nodeId) {
    Serial.printf("Dropped Connection %u\n", nodeId);
  });

  mesh.stationManual(STATION_SSID, STATION_PASSWORD);
  mesh.setHostname((char *)HOSTNAME.c_str());

  // Add the task to the your scheduler
  userScheduler.addTask(logServerTask);
  logServerTask.enable();
}

void loop()
{
  userScheduler.execute(); // it will run mesh scheduler as well
  mesh.update();
  mqttClient.loop();

  if (myIP != getlocalIP())
  {
    myIP = getlocalIP();
    Serial.println("My IP is " + myIP.toString());

    if (mqttClient.connect((char *)HOSTNAME.c_str()))
    {
      Serial.printf("logServer: MQTT Connected!");
    }
  }
}

void receivedCallback(uint32_t from, String &msg)
{
  Serial.printf("logServer: Received from %u msg=%s\n", from, msg.c_str());
  if (mqttClient.connected())
  {
    mqttClient.publish("sensor", msg.c_str());
  }
}

IPAddress getlocalIP()
{
  return IPAddress(mesh.getStationIP());
}
