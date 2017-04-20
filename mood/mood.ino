// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Define the pin
#define PIN            3

// Number of pixels on the strip
#define NUMPIXELS      120

// Setup the Adafruit Neopixel while defining the number of pixels and pin.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//arrays
int inputLength = 10;
int inputArray[10] = {3,2,3,4,3,2,3,4,3,2};
float inputAvg;
float inputSTD;
float inputRange;
float inputMax;
float inputMin;

//color manipulation
float avgPercent;
float rAvg = 127.5;
float gAvg = 127.5;
float bAvg = 0;
float r = 127.5;
float g = 127.5;
float b = 0;
float pulseRange;
float pulseMax;
float pulseMin;

void setup() {
  Serial.begin(57600);

    // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}
 
void loop() {
  serialCom();
  lightItUp();
}
