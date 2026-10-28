#include <Arduino.h>
#include <WiFi.h>
#include <WiFiManager.h> 

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nStarting...");

  WiFiManager wifiManager;

  // ⚠️ CHANGE THIS TO YOUR NAME AND NUMBER
  wifiManager.setConfigPortalTimeout(180); // 3 minutes timeout (180 seconds)
  
  // This creates the Wi-Fi network "BCA188_ESP32_YOUR_NAME"
  // You can add a password here if you want, but the lab doesn't require it.
  bool res = wifiManager.autoConnect("BCA188_ESP32_NERI_2024-1316");

  if (!res) {
    Serial.println("Failed to connect or hit timeout. Restarting...");
    ESP.restart();
  }

  // If you get here, it connected successfully!
  Serial.println("Connected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Nothing to do here, the connection is handled in setup()
  delay(10000); 
}