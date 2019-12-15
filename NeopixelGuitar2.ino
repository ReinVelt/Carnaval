//LED GITAAR
// door Rein Velt,  november 2019
// De led gitaar bestaat uit 3 ledstrips (ws6812b 5V), een Arduino Nano en een DC/DC converter om 6-40V om te zetten naar
// 5V 3 Ampere.
// De ledstrips zijn zigzag verbonden
//
//    ->  #====#====#====#====#====#====#====#====#====#====#====#====#====#====#  ->
//    <-  #====#====#====#====#====#====#====#====#====#====#====#====#====#====#  <-
//    ->  #====#====#====#====#====#====#====#====#====#====#====#====#====#====#  ->
//
//     =  led    # fretled
//De software maakt gebruik van de Adafruit Neopixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6
#define PIXELSPS 60 //PIXELS PER STRING (3 STRINGS)

//  The overall fire brightness
//  (this can affect both color levels and power consumption)
int brightness = 64;
int k = 0;
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELSPS * 3, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
// For the ultimate NeoPixel guide, check out:
// https://learn.adafruit.com/adafruit-neopixel-uberguide/overview




void setup() {
  delay(100);
  strip.begin();
  strip.setBrightness(brightness);
  strip.show(); // Initialize all pixels to 'off'

}








void loop() {

  delay(100); //10 x per seconde

  //loop colorcycle
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += (256)) {

    //loop ledstrings
    for (int i = 0; i < strip.numPixels(); i++)
    {
      //snaren  color cycle (background color)
      int pixelHue = firstPixelHue + (i * 65536L / (strip.numPixels()));
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue, 255, 128l)));

      //fretten
      if (i < 60) {
        if (i % 5 == 0) {
          strip.setPixelColor(i, 255, 255, 255); //snaar1
        }
      }
      if (i > 59 && i < 120) {
        if (i % 5 == 4) {
          strip.setPixelColor(i, 255, 255, 255); //snaar2 (omgekeerd...want snaren lopen zigzag)
        }
      }
      if (i > 119) {
        if (i % 5 == 0) {
          strip.setPixelColor(i, 255, 255, 255); //snaar3
        }
      }

    }

    //fingerspitzen
    if (firstPixelHue % 10 == 0) {
      k = random(PIXELSPS / 2);
    }
    if (firstPixelHue % 3 == 0)  {
      strip.setPixelColor(k + 1, 255, 255, 0);  //snaar1
    }
    if (firstPixelHue % 3 == 1)  {
      strip.setPixelColor((2 * PIXELSPS) - k - 2, 255, 255, 0); //snaar2 (ook weer omgekeerd...want snaren lopen zigzag)
    }
    if (firstPixelHue % 3 == 2)  {
      strip.setPixelColor(k + (2 * PIXELSPS) + 1, 255, 255, 0); //snaar3
    }
    strip.show();
  }


}
