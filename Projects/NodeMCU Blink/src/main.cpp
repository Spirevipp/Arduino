#include <Arduino.h>
#include <ESP8266WiFi.h>

#define LED 13

int buttonpressed = 5;
int firstrun = 0;

unsigned long pMil = 0;

char *ssid = "Laksen";
char *password = "arxofgecrirzu";

WiFiServer server(80); // Define Web Server Port

void setup() {
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
  delay(10);

  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Wait until connected to WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }

  // Confirmation that WiFi is connected
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the Web Server
  server.begin();
  Serial.println("Web Server Started");

  // Display IP address
  Serial.print("You can connect to the Server here: ");
  Serial.print(WiFi.localIP());
  Serial.println();
  Serial.println();
}
void loop() {
  // Check if someone is connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Get message from clients
  String request = client.readStringUntil('\r');

  // Check recieved buttonpress
  if (request.indexOf("/ON=1") != -1) {
    digitalWrite(LED, HIGH);
    buttonpressed = HIGH;
    firstrun = 1;
  }
  if (request.indexOf("/OFF=1") != -1) {
    digitalWrite(LED, LOW);
    buttonpressed = LOW;
    firstrun = 1;
  }
  if (request.indexOf("/Rave=1") != -1) {
    digitalWrite(LED, HIGH);
    delay(50);
    digitalWrite(LED, LOW);
  }

  // Create Web Page
  client.println("HTTP/1.1 200 OK"); // HTML Header
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");

  client.println("<html>"); // Start of HTML

  client.println("<style>");
  client.println("body {background-color: #ACAEAD;}"); // Set Background Color
  client.println("</style>");

  // update webpage

  if (firstrun == 0) {
    client.print("Please Click a Button ");
  } else {
    client.print("LED is ");
  }

  if (buttonpressed == HIGH) {
    client.print("ON");
  }
  if (buttonpressed == LOW) {
    client.print("OFF");
  }

  client.println("<br><br>");
  client.println("<a href=\"/ON=1\"\"><button>ON </button></a>");
  client.println("<a href=\"/OFF=1\"\"><button>OFF</button></a><br />");

  client.print("Hanne rave!");
  client.println("<a href=\"/Rave=1\"\"><button>RAVE</button></a>");

  client.println("</html>");
  delay(10);
}
