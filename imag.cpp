/**
 * imag.h
 * 
 * imag, a firmware for the ESP8266/ESP32 platform
 * for configuring iot diy devices using a Captive Portal
 * 
 * @author Creator Nsisong
 * @version 1.0.1
 * @license MIT
 */

#include "imag.h"

// Constructor to initialize member variables
Imag::Imag() : mqttClient(wifiClient), webServer(80) {
  // Initialize member variables to default values
  ssid = "";
  password = "";
  mqttServer = "";
  mqttPort = 1883; // Default MQTT port
  mqttAuthKey = "";
  mqttPassword = "";
  deviceName = "ESP Device";
}

// -------------------------------------
// WiFi Setup and Scanning Functions
// -------------------------------------

// Setup WiFi with SSID and password
void Imag::setupWiFi(const char* ssid, const char* password) {
  this->ssid = ssid;
  this->password = password;

  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Begin WiFi connection
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// Scan for available WiFi networks
void Imag::scanWiFi() {
  Serial.println("Scanning for available WiFi networks...");
  int n = WiFi.scanNetworks(); // Scan networks
  for (int i = 0; i < n; ++i) {
    // Print SSID and RSSI (signal strength)
    Serial.print(WiFi.SSID(i));
    Serial.print(" (");
    Serial.print(WiFi.RSSI(i));
    Serial.println(")");
  }
}

// -------------------------------------
// MQTT Setup and Communication Functions
// -------------------------------------

// Setup MQTT server configuration
void Imag::setupMQTT(const char* server, const int port, const char* authKey, const char* password) {
  mqttServer = server;
  mqttPort = port;
  mqttAuthKey = authKey;
  mqttPassword = password;

  // Set server and port for the MQTT client
  mqttClient.setServer(mqttServer, mqttPort);
}

// Connect to the MQTT server
void Imag::connectMQTT() {
  while (!mqttClient.connected()) {
    Serial.print("Connecting to MQTT...");

    // Connect using auth key and password
    if (mqttClient.connect(deviceName, mqttAuthKey, mqttPassword)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000); // Wait 5 seconds before retrying
    }
  }
}

// Publish a message to a specific topic
void Imag::publishMQTT(const char* topic, const char* message) {
  if (mqttClient.connected()) {
    mqttClient.publish(topic, message); // Publish message to the topic
    Serial.print("Published message: ");
    Serial.print(message);
    Serial.print(" to topic: ");
    Serial.println(topic);
  } else {
    Serial.println("MQTT not connected. Cannot publish.");
  }
}

// -------------------------------------
// Device Setup Functions
// -------------------------------------

// Setup device with a name
void Imag::setupDevice(const char* deviceName) {
  this->deviceName = deviceName; // Assign device name
  Serial.print("Device Name Set: ");
  Serial.println(deviceName);
}

// -------------------------------------
// TODO
// Web Server Functions
// -------------------------------------

// Start the web server to handle HTTP requests
void Imag::startWebServer() {
  webServer.on("/", std::bind(&Imag::handleRoot, this));           // Root page
  webServer.on("/wifi", std::bind(&Imag::handleWiFiConfig, this)); // WiFi config page
  webServer.on("/mqtt", std::bind(&Imag::handleMQTTConfig, this)); // MQTT config page
  webServer.on("/info", std::bind(&Imag::handleDeviceInfo, this)); // Device info page

  webServer.begin(); // Start the web server
  Serial.println("Web server started");
}

// Handle root page of the web server
void Imag::handleRoot() {
  String html = "<html><body><h1>Welcome to the ESP Web Interface</h1></body></html>";
  webServer.send(200, "text/html", html); // Send response to the client
}

// Handle WiFi configuration page
void Imag::handleWiFiConfig() {
  String html = "<html><body><h1>WiFi Configuration</h1>";
  html += "<form action='/save_wifi' method='POST'>";
  html += "SSID: <input type='text' name='ssid'><br>";
  html += "Password: <input type='password' name='password'><br>";
  html += "<input type='submit' value='Save'>";
  html += "</form></body></html>";
  webServer.send(200, "text/html", html); // Send response to the client
}

// Handle MQTT configuration page
void Imag::handleMQTTConfig() {
  String html = "<html><body><h1>MQTT Configuration</h1>";
  html += "<form action='/save_mqtt' method='POST'>";
  html += "Server: <input type='text' name='server'><br>";
  html += "Port: <input type='number' name='port'><br>";
  html += "Auth Key: <input type='text' name='authKey'><br>";
  html += "Password: <input type='password' name='password'><br>";
  html += "<input type='submit' value='Save'>";
  html += "</form></body></html>";
  webServer.send(200, "text/html", html); // Send response to the client
}

// Handle device information page
void Imag::handleDeviceInfo() {
  String html = "<html><body><h1>Device Information</h1>";
  html += "<p>Device Name: " + String(deviceName) + "</p>";
  html += "<p>IP Address: " + WiFi.localIP().toString() + "</p>";
  html += "</body></html>";
  webServer.send(200, "text/html", html); // Send response to the client
}

// -------------------------------------
// TODO// Helper Functions
/*
reconnectMQTT: Ensures the MQTT connection is maintained.
saveWiFiConfig and saveMQTTConfig: Placeholder functions that you can later implement for saving configuration to 
EEPROM or a file system like SPIFFS.

*/
// -------------------------------------

// Reconnect to the MQTT server if disconnected
void Imag::reconnectMQTT() {
  if (!mqttClient.connected()) {
    connectMQTT(); // Attempt to reconnect
  }
  mqttClient.loop(); // Ensure the MQTT client processes incoming messages
}

// Save WiFi configuration (dummy function for now)
void Imag::saveWiFiConfig() {
  // Implement saving to EEPROM or SPIFFS here if needed
  Serial.println("WiFi configuration saved (not implemented)");
}

// Save MQTT configuration (dummy function for now)
void Imag::saveMQTTConfig() {
  // Implement saving to EEPROM or SPIFFS here if needed
  Serial.println("MQTT configuration saved (not implemented)");
}
