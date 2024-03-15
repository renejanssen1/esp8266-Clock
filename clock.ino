#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <time.h>
const char *ssid      = "    ";
const char *password  = "    "; 
int u = 0;
int m = 0;
int s = 0;
#define MY_NTP_SERVER "pool.ntp.org"           
#define MY_TZ "CET-1CEST,M3.5.0/02,M10.5.0/03"   

time_t now;
tm tm;

#define PIN D3 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  configTime(MY_TZ, MY_NTP_SERVER); // --> Here is the IMPORTANT ONE LINER needed in your sketch!
  pixels.begin(); 
  Draw_Clock(1); 
  WiFi.begin(ssid, password); 
  Draw_Clock(2); 
  while ( WiFi.status() != WL_CONNECTED )
  delay ( 500 );
}
        
void loop() {
  time(&now);
  localtime_r(&now, &tm);
  u = tm.tm_hour;
  m = tm.tm_min;
  s = tm.tm_sec;
  Draw_Clock(3);
}

void Draw_Clock(byte Phase){
  if (Phase <= 0)
    for (int i = 0; i < 60; i++)
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); //alle leds uit

  if (Phase >= 1)
    for (int i = 0; i < 60; i++)
      pixels.setPixelColor(i, pixels.Color(0, 0 ,0)); //alle leds uit

  if (Phase >= 2)
    for (int i = 4; i < 60; i = i + 5)
      pixels.setPixelColor(i, pixels.Color(0, 0, 120));// elke 5 min blauw gekleurd

  if (Phase >= 3) {
      pixels.setPixelColor(s - 1, pixels.Color(200, 200, 0)); // sec wijzer geel
      pixels.setPixelColor(m - 1, pixels.Color(0, 200, 0));  // minuten wijzer groen
      pixels.setPixelColor((((u % 12) * 5) + m / 12) - 1, pixels.Color(200, 0, 0)); // uur wijzer rood, verspringt elke 12 minuten
  }
  SetBrightness();
  pixels.show();
}

void SetBrightness(){
  if ((u > 21) || ((u == 21) && (m >= 30)) || ((u == 6) && (m <= 15)) || (u < 6)){
      pixels.setBrightness(16);
  }else{
      pixels.setBrightness(255);
  }
}
