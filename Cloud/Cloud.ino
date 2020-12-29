#include <WiFi.h>
#include "DHT.h"
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // define type of sensor DHT 11
DHT dht (DHTPIN, DHTTYPE);

const char* ssid     = "GangBang";//Enter the ssid of your router VSES
const char* password = "GangBang123";//Enter the password of your router gnir33nignEtr@mS

const char* host = "api.thingspeak.com";
//const char* privateKey = "TEHVT5AC1WQHG7VH";//read key
const char* privateKey1 = "IHSE7TBNF779BR78";//write key
//String line,line1;
float h,t;


void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(10);
  Serial.print("Connecting to "); 
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  h = dht.readHumidity();
  t = dht.readTemperature();
  Serial.print("temperature:");
  Serial.println(t);
  Serial.print("Humidity:");
  Serial.println(h);
  upload();
  delay(1000);
}

void upload()
{
        
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
   // We now create a URI for the request
  String url = "/update";
  url += "?api_key=";
  url += privateKey1;
  url += "&field1=";
  url += T;
  url += "&field2=";
  url += H;
 
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(1000);
 
  // Read all the lines of the reply from server and print them to Serial
  while(client.available())
  {
  String line1 = client.readStringUntil('\r');
  Serial.print(line1);
  }
  Serial.println();
  Serial.println("closing connection");
}
