#include <Arduino.h>
#include <WiFi.h>
#include <WiFiManager.h> 

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nStarting...");

  WiFiManager wifiManager;

  wifiManager.setConfigPortalTimeout(180); 
  

  bool res = wifiManager.autoConnect("BCA188_ESP32_REUYAN_2024-1594");

  if (!res) {
    Serial.println("Failed to connect or hit timeout. Restarting...");
    ESP.restart();
  }


  Serial.println("Connected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  delay(10000); 
}