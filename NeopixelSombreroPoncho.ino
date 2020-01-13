//LED PONCHO EN SOMBRERO
// door Rein Velt,  januaro 2020
// De led gitaar bestaat uit 4 ledstrips (ws6812b 5V) voor de poncho, 2  ledstrips voor de somrero, een Arduino Nano en een 5V USB dc powerpack

// De ledstrips zijn doorverbonden
//
//    ->#====#->#====#->#====#->#====#------>#====#->#====#->
//             p  o  n  c  h  o               s o m b r e r o

//De software maakt gebruik van de Adafruit Neopixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6
#define PIXELSPONCHO 240 //4 x 1 meter (60 pixels/meter) 
#define PIXELSSOMBRERO 160 //2 x 1 meter (60 pixels/meter)

//  The overall fire brightness
//  (this can affect both color levels and power consumption)
int brightness = 64;
uint16_t k = 0;
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELSPONCHO+PIXELSSOMBRERO , PIN, NEO_GRB + NEO_KHZ800);

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

  delay(10); //10 x per seconde
  k++;
  //loop colorcycle
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += (1024)) {

    //DO PONCHO COLORS
    for (int i = 0; i < PIXELSPONCHO; i++)
    {
      //poncho background color (rainbow)
      int pixelHue = firstPixelHue + (i * 65536L / (PIXELSPONCHO));
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue, 255, 128l)));
    } 

    //DO SOMBRERO COLORS
    for (int i = 0; i < PIXELSSOMBRERO; i++)
    {
      //sombrero background color (rainbow)
      int pixelHue = firstPixelHue + (i * 32816L / (PIXELSSOMBRERO));
      if (i%2==0)
      {
        strip.setPixelColor(PIXELSPONCHO+i, strip.gamma32(strip.ColorHSV(pixelHue, 255, 128l)));
      }
      else
      {

        strip.setPixelColor(PIXELSPONCHO+i, strip.gamma32(strip.ColorHSV(pixelHue<<2, 255, 128l)));
      }
    } 
   
   
    
   
    strip.show();
  }


}
