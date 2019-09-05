#include "painlessMesh.h"

#define   MESH_PREFIX     "whateverYouLike"
#define   MESH_PASSWORD   "somethingSneaky"
#define   MESH_PORT       5555

Scheduler     userScheduler; // to control your personal task
painlessMesh  mesh;

// Prototype
void receivedCallback( uint32_t from, String &msg );

void sendMessage(DynamicJsonDocument msg);

size_t logServerId = 0;

void sendMessage(DynamicJsonDocument msg) {
    String str;
    serializeJson(msg, str);
    if (logServerId == 0) // If we don't know the logServer yet
        mesh.sendBroadcast(str);
    else
        mesh.sendSingle(logServerId, str);

    // log to serial
    serializeJson(msg, Serial);
    Serial.printf("\n");  
  
}

// Send message to the logServer every 2 seconds 
Task myLoggingTask(2000, TASK_FOREVER, []() {
    DynamicJsonDocument msg(1024);

    msg["type"] = "temperature";
    msg["value"] = random(0, 100);
    msg["node"] = mesh.getNodeId();
    sendMessage(msg);

    msg["type"] = "humidity";
    msg["value"] = random(20, 100);
    msg["node"] = mesh.getNodeId();
    sendMessage(msg);

    msg["type"] = "lux";
    msg["value"] = random(50, 500);
    msg["node"] = mesh.getNodeId();
    sendMessage(msg);
});

void setup() {
  Serial.begin(115200);
    
  mesh.setDebugMsgTypes( ERROR | STARTUP | CONNECTION );  // set before init() so that you can see startup messages

  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT, WIFI_AP_STA, 6 );
  mesh.onReceive(&receivedCallback);

  // Add the task to the your scheduler
  userScheduler.addTask(myLoggingTask);
  myLoggingTask.enable();
}

void loop() {
    userScheduler.execute(); // it will run mesh scheduler as well
    mesh.update();
}

void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf("logClient: Received from %u msg=%s\n", from, msg.c_str());

  // Saving logServer
  DynamicJsonDocument root(1024);
  if (root.containsKey("topic")) {
      if (String("logServer").equals(root["topic"].as<String>())) {
          // check for on: true or false
          logServerId = root["nodeId"];
          Serial.printf("logServer detected!!!\n");
      }
      Serial.printf("Handled from %u msg=%s\n", from, msg.c_str());
  }
}
