#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFiMulti.h>   // Include the Wi-Fi-Multi library

ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'



int led1pin = 0;  //GPIO0
int led2pin = 1;  //GPIO1
int led3pin = 2;  //GPIO2
int led4pin = 3;  //GPIO3

IPAddress staticIP(192, 168, 1, 25); //ESP static ip
IPAddress gateway(192, 168, 1, 1);   //IP Address of your WiFi Router (Gateway)
IPAddress subnet(255, 255, 255, 0);  //Subnet mask
IPAddress dns(8, 8, 8, 8);  //DNS

const char* ssid     = "Smart_Gorjaw";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "gorjaw@!85";           // The password of the Wi-Fi network
const char* deviceName = "SmartLight";         // The device name
String serverUrl = "192.168.1.252";
String payload;
String device_key = "smart_light";

ESP8266WebServer server(80);

void handleDevice() {
  String led1 = server.arg("led1");
  String led2 = server.arg("led2");
  String led3 = server.arg("led3");
  String led4 = server.arg("led4");

  led1.trim();
  led2.trim();
  led3.trim();
  led4.trim();

    if (led1 == "1") {
      digitalWrite(led1pin, 1);
    }
    else if (led1 == "0") {
      digitalWrite(led1pin, 0);
    }
    if (led2 == "1") {
      digitalWrite(led2pin, 1);
    }
    else if (led2 == "0"){
      digitalWrite(led2pin, 0);
    }
    if (led3 == "1") {
      digitalWrite(led3pin, 1);
    }
    else if (led3 == "0") {
      digitalWrite(led3pin, 0);
    }
    if (led4 == "1") {
      digitalWrite(led4pin, 1);
    }
    else if (led4 == "0") {
      digitalWrite(led4pin, 0);
    }
 
  server.send(200, "text/html", "OK");
}

void handlePong() {
  server.send(200, "text/html", device_key);
}

void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);

// add Wi-Fi networks you want to connect to
  wifiMulti.addAP("Smart_Gorjaw", "gorjaw@!85");   
  wifiMulti.addAP("Relay_control", "123456789");
  wifiMulti.addAP("linux", "12345678");


  pinMode(led1pin, OUTPUT);
  pinMode(led2pin, OUTPUT);
  pinMode(led3pin, OUTPUT);
  pinMode(led4pin, OUTPUT);


  WiFi.begin(ssid, password);
  Serial.println("");
  WiFi.disconnect();
  WiFi.config(staticIP, subnet, gateway, dns);
  WiFi.begin(ssid, password);

  WiFi.mode(WIFI_STA);

  delay(500);
  Serial.println("");
  Serial.println("WiFi connected");

  Serial.print(WiFi.localIP());
  server.on("/ping/", handlePong);
  server.on("/control/", handleDevice);
  server.begin();
}

void loop() {
  server.handleClient();
}
