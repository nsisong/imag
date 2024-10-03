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


#ifndef IMAG_H
#define IMAG_H

#include <WiFi.h>           // For Wi-Fi functionality
#include <PubSubClient.h>    // For MQTT functionality
#include <ESP8266WebServer.h> // For Web server functionality
#include <ArduinoJson.h>     // For parsing and formatting JSON data

// Class to handle Wi-Fi configuration
class ImagWiFi {
  public:
    // Constructor: initializes Wi-Fi credentials
    ImagWiFi(const char* ssid, const char* password);

    // Function to connect to the Wi-Fi network
    void connect();

    // Function to scan for available Wi-Fi networks
    void scanNetworks();

    // Function to display connection status
    void displayStatus();
    
  private:
    const char* ssid;       // Wi-Fi network SSID
    const char* password;   // Wi-Fi network password
    bool isConnected;       // Flag to check Wi-Fi connection status
};

// Class to handle MQTT setup and configuration
class ImagMQTT {
  public:
    // Constructor: initializes MQTT server, port, and credentials
    ImagMQTT(const char* server, int port, const char* authKey, const char* password);

    // Function to set up MQTT connection
    void setup();

    // Function to publish a message to a topic
    void publish(const char* topic, const char* message);

    // Function to subscribe to a topic
    void subscribe(const char* topic);

    // Function to check the MQTT connection and reconnect if necessary
    void checkConnection();
    
  private:
    const char* mqttServer;     // MQTT server address
    const char* mqttAuthKey;    // Authentication key for the MQTT server
    const char* mqttPassword;   // MQTT server password
    int mqttPort;               // MQTT server port
    WiFiClient espClient;       // Wi-Fi client for connecting to MQTT
    PubSubClient client;        // PubSubClient instance for MQTT communication
};

// Class to handle device info and setup
class ImagDevice {
  public:
    // Constructor: initializes device details like name and ID
    ImagDevice(const char* deviceName);

    // Function to display device info (MAC, IP, etc.)
    void displayInfo();

    // Function to handle setup (e.g., device name, configuration)
    void setupDevice();

  private:
    const char* deviceName;   // Name of the device
    String chipID;            // Chip ID for the device (can be fetched using ESP.getChipId())
    String macAddress;        // MAC address of the device (fetched via WiFi.macAddress())
};

// Class to manage web interface using AsyncWebServer
class ImagWeb {
  public:
    // Constructor: sets up the web server on a specified port
    ImagWeb(int port);

    // Function to start the web server
    void startServer();

    // Function to add a route to the web server
    void addRoute(const char* path, const char* contentType, String(*handler)());

  private:
    AsyncWebServer server;    // AsyncWebServer instance
    int serverPort;           // Port for the web server
};

#endif
