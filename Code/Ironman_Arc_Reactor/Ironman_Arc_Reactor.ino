// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

// XIAO SAMD21 for small size Guide -> https://wiki.seeedstudio.com/Seeeduino-XIAO/
// Board Manager file -> https://files.seeedstudio.com/arduino/package_seeeduino_boards_index.json

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        7 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 28 // Popular NeoPixel ring size
#define GROUPSIZE 7 // How many LEDS to light togther in a circular sweeping pattern

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVALFOR 15 // Time (in milliseconds) to pause between pixels
#define DELAYVALMAIN 15 // Time (in milliseconds) to pause between pixels

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  //pixels.clear(); // Set all pixel colors to 'off'
  //pixels.show();   // Send the updated pixel colors to the hardware.
  //delay(DELAYVALMAIN); // Pause before next pass through main void loop

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    int j=i-GROUPSIZE;
    int k=i+(NUMPIXELS-GROUPSIZE);
    pixels.setPixelColor(i, pixels.Color(170, 170, 170));
    pixels.setPixelColor(j, pixels.Color(0, 0, 0));
    pixels.setPixelColor(k, pixels.Color(0, 0, 0));
  //  pixels.setPixelColor(k, pixels.Color(150, 150, 150));
  //  pixels.setPixelColor(k-1, pixels.Color(0, 0, 0));
 
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVALFOR); // Pause before next pass through for loop    
  }
 // pixels.setPixelColor(26, pixels.Color(0, 0, 0));
 // pixels.setPixelColor(27, pixels.Color(0, 0, 0));
  //delay(DELAYVALMAIN); // Pause before next pass through main void loop
}
