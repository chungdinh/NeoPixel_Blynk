#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <ESP8266WiFi.h>

#define PIN 10
#define NUMPIXELS 12
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


char auth[] = "a09a37c6a5e94320912e6573fccdd536";
const char* ssid = "Chung Dinh"; //enter wifi name
const char* pass = "2211196"; //enter wifi password

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pixels.begin();
}
BLYNK_WRITE(V0)
{
  int R=param[0].asInt();
  int G=param[1].asInt();
  int B=param[2].asInt();
  Serial.println(R);
  Serial.println(G);
  Serial.println(B);
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(R,G,B));
    pixels.show();
  }
}
void loop()
{
  Blynk.run();
}

