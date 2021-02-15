#include "WiFiEsp.h"
#include "SoftwareSerial.h"

SoftwareSerial Serial1(2,3);
 
char ssid[] = "UPNYK-Dosen";     
char pass[] = "dos2018*#";           
char server[] = "10.254.15.154";     
 
bool responDariServer = false;
int PinAlarm = 8;
int PinGetar = A0;
 
bool statusKomunikasiWifi = false;
long waktuMulai;
long waktuMintaData = 5000; 
 
WiFiEspClient client;
int status = WL_IDLE_STATUS;
 
void setup()
{
  Serial.begin(115200);
  Serial.println("Koneksi arduino dengan mySql menggunakan ESp8266 dan XAMPP");
  Serial.println("Ketik pesan yang akan dikirim (pastikan setting serial ke \"both NL & CR\")");
  Serial.println();
  pinMode(PinAlarm, OUTPUT);     
  pinMode(PinGetar, INPUT);
 
  Serial1.begin(9600);
  WiFi.init(&Serial1);
 
  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }
 
  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }
 
  // you're connected now, so print out the data
  Serial.println("You're connected to the network");
   
  printWifiStatus();
  waktuMulai = millis();
}

bool kirimKeDatabase(String namaVariabel, String nilai)
{
  Serial.println();
  Serial.println("Starting connection to server...");
  // if you get a connection, report back via serial
  if (client.connect(server, 80)) {
    Serial.println("Connected to server");
    // Make a HTTP request
 
    // parameter 1
    client.print("GET /arduino_mysql/dariArduino.php?");
    client.print("variabel=");
    client.print(namaVariabel);
     
    // parameter 2 dan selanjutnya
    client.print("&");
    client.print("nilai=");
    client.print(nilai);
     
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
 
    return true;
  }
  return false;
}
 
void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
 
  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
 
  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
 
  IPAddress gateway = WiFi.gatewayIP();
  Serial.print("gateway:");
  Serial.print(gateway);
  Serial.println(" ");
}

long TP_init(){
  long measurement=pulseIn (PinGetar, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
} 

void loop()
{
  // periksa respon dari server
  if(statusKomunikasiWifi)
  {
    // if the server's disconnected, stop the client
    if (!client.connected()) {
      Serial.println("Disconnecting from server...");
      client.stop();
      statusKomunikasiWifi = false;
      responDariServer = true;
    }
  }
  long measurement = TP_init();
  delay(50);
  Serial.print("measurment = ");
  Serial.println(measurement);
  if (measurement > 800){
    digitalWrite(PinAlarm, HIGH);
    char buf[8];
    sprintf(buf, "%d", measurement);
    statusKomunikasiWifi = kirimKeDatabase("dataDariSerial",buf);
  }
  else{
    digitalWrite(PinAlarm, LOW); 
  }
 
}
