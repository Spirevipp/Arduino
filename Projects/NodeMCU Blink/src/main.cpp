#include <Arduino.h>
#include <ESP8266WiFi.h>

#define LED D7
#define PENN D6

int buttonpressed = 5;
int firstrun = 0;

unsigned long pMil = 0;
bool enableBlink = false;

char *ssid = "Laksen";
char *password = "arxofgecrirzu";

WiFiServer server(80); // Define Web Server Port

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PENN, OUTPUT);

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

  // blink toggler
  if (enableBlink) {
    if (pMil + 250 <= millis()) {
      digitalWrite(LED, !digitalRead(LED));
      pMil = millis();
    }
  }

  // Check if someone is connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Get message from clients
  String request = client.readStringUntil('\r');

  // Check recieved buttonpress
  if (request.indexOf("/OFF=1") != -1) {
    digitalWrite(LED, LOW);
    enableBlink = false;
    buttonpressed = 0;
    firstrun = 1;
  }
  if (request.indexOf("/ON=1") != -1) {
    digitalWrite(LED, HIGH);
    enableBlink = false;
    buttonpressed = 1;
    firstrun = 1;
  }
  if (request.indexOf("/BLINK=1") != -1) {
    enableBlink = !enableBlink;
    buttonpressed = 2;
    firstrun = 1;
  }
  if (request.indexOf("/Rave=1") != -1) {
    enableBlink = false;
    buttonpressed = 0;
    firstrun = 1;
    digitalWrite(LED, HIGH);
    delay(50);
    digitalWrite(LED, LOW);
  }
  if (request.indexOf("/Penn=1") != -1) {
    digitalWrite(PENN, HIGH);
    delay(50);
    digitalWrite(PENN, LOW);
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
    client.print("LED is currently OFF");
  } else {
    client.print("LED is ");
  }

  if (buttonpressed == 0) {
    client.print("OFF");
  }
  if (buttonpressed == 1) {
    client.print("ON");
  }
  if (buttonpressed == 2) {
    client.print("BLINKING");
  }

  client.println("<br><br>");
  client.println("<a href=\"/ON=1\"\"><button>ON </button></a>");
  client.println("<a href=\"/OFF=1\"\"><button>OFF</button></a><br />");

  client.println("<br><br>");
  client.print("Hanne rave!");
  client.println("<a href=\"/Rave=1\"\"><button>RAVE</button></a>");

  client.println("<br><br>");
  client.println("<a href=\"/BLINK=1\"\"><button>BLINK</button></a>");

  client.println("<br><br>");
  client.print("Penn knapp");
  client.println("<a href=\"/Penn=1\"\"><button>PENN</button></a>");

  client.println("</html>");
  delay(10);
}
