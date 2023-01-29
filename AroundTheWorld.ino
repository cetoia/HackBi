// A basic everyday NeoPixel strip test program.



#include <Adafruit_NeoPixel.h>


// Which pin on the Arduino is connected to the NeoPixels?

#define LED_PIN    3

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 46

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


// setup() function -- runs once at startup --------------------------------

void setup() {
 
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(180); // Set BRIGHTNESS to about 1/5 (max = 255)
}

uint32_t white = strip.Color(255, 255, 255);
// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  // Fill along the length of the strip in various colors...
  //colorWipe(strip.Color(255,   0,   0), 50); // Red
  //colorWipe(strip.Color(  0, 255,   0), 50); // Green
  //colorWipe(strip.Color(  0,   0, 255), 50); // Blue

  // Do a theater marquee effect in various colors...
  //theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
  //theaterChase(strip.Color(127,   0,   0), 50); // Red, half brightness
  //theaterChase(strip.Color(  0,   0, 127), 50); // Blue, half brightness

  //rainbow(10);             // Flowing rainbow cycle along the whole strip
  //theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
  //randomFlag(10000);
  
  armenia(10000);
  bangladesh(10000);
  chad(10000);
  estonia(10000);
  gabon(10000);
  lithuania(10000);
  netherlands(10000);
  peru(10000);
  sierraLeone(10000);
  thailand(10000);

  
}


// Some functions for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    strip.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}

void randomFlag(int wait)
{
  int x = random(10);
  if (x==0)
  {      
    armenia(wait);
  }  
  if (x==1)
  {      
    bangladesh(wait);
  }  
  if (x==2)
  {      
    chad(wait);
  }  
  if (x==3)
  {      
    estonia(wait);
  }  
  if (x==4)
  {      
    gabon(wait);
  }  
  if (x==5)
  {      
    lithuania(wait);
  }  
  if (x==6)
  {      
    netherlands(wait);
  }  
  if (x==7)
  {      
    peru(wait);
  }  
  if (x==8)
  {      
    sierraLeone(wait);
  }  
  if (x==9)
  {      
    thailand(wait);
  }  
}

void armenia(int wait) 
{
  uint32_t red = strip.Color(237,0,0);
  uint32_t blue = strip.Color(0,47,166);
  uint32_t yellow = strip.Color(254,165,0);
  strip.fill(red, 0, 12); //red
  strip.fill(blue, 12, 12);  //blue
  strip.fill(yellow, 24, 12); //yellow

  strip.show();
  delay(wait);
  strip.setPixelColor(36, white);
}

void bangladesh(int wait)
{
  uint32_t green = strip.Color(0,255,71);
  uint32_t red = strip.Color(218,40,28);
  strip.fill(green, 0, 15); //green
  strip.fill(red, 15, 2);  //red
  strip.fill(green, 17, 2);  //green
  strip.fill(red, 19, 2);  //red
  strip.fill(green, 21, 15); //green

  strip.show();
  delay(wait);
  strip.setPixelColor(37, white);
}

void chad(int wait)
{
  uint32_t red = strip.Color(255,0,10);
  uint32_t yellow = strip.Color(255,202,0);
  uint32_t blue = strip.Color(0,37,104);
  strip.fill(red, 0, 2); //red
  strip.fill(yellow, 2, 2);  //yellow
  strip.fill(blue, 4, 4); //blue
  strip.fill(yellow, 8, 2);  //yellow
  strip.fill(red, 10, 4); //red
  strip.fill(yellow, 14, 2);  //yellow
  strip.fill(blue, 16, 4); //blue
  strip.fill(yellow, 20, 2);  //yellow
  strip.fill(red, 22, 4); //red
  strip.fill(yellow, 26, 2);  //yellow
  strip.fill(blue, 28, 4); //blue
  strip.fill(yellow, 32, 2);  //yellow
  strip.fill(red, 34, 2); //red

  strip.show();
  delay(wait);
  strip.setPixelColor(38, white);
}

void estonia(int wait)
{
  uint32_t blue = strip.Color(0,114,213);
  uint32_t black = strip.Color(0,0,0);
   
  strip.fill(blue, 0, 12); //blue
  strip.fill(black, 12, 12);  //black
  strip.fill(white, 24, 12); //white

  strip.show();
  delay(wait);
  strip.setPixelColor(39, white);
}

void gabon(int wait)
{
  uint32_t green = strip.Color(0,220,30);
  uint32_t yellow = strip.Color(255,209,0);
  uint32_t blue = strip.Color(36,117,201);
  strip.fill(green, 0, 12); //green
  strip.fill(yellow, 12, 12);  //yellow
  strip.fill(blue, 24, 12); //blue

  strip.show();
  delay(wait);
  strip.setPixelColor(40, white);
}

void lithuania(int wait)
{
  uint32_t yellow = strip.Color(255,190,0);
  uint32_t green = strip.Color(10,200,10);
  uint32_t red = strip.Color(255,0,5);
  strip.fill(yellow, 0, 12); //yellow
  strip.fill(green, 12, 12);  //green
  strip.fill(red, 24, 12); //red

  strip.show();
  delay(wait);
  strip.setPixelColor(41, white);
}

void netherlands(int wait)
{
  uint32_t red = strip.Color(255,0,5);
  uint32_t  blue = strip.Color(21,21,255);
  strip.fill(red, 0, 12); //red
  strip.fill(white, 12, 12);  //white
  strip.fill(blue, 24, 12); //blue

  strip.show();
  delay(wait);
  strip.setPixelColor(42, white);
}

void peru(int wait) 
{
  uint32_t red = strip.Color(255,0,0);
  strip.fill(red, 0, 2); //red
  strip.fill(white, 2, 2);  //white
  strip.fill(red, 4, 4); //red
  strip.fill(white, 8, 2);  //white
  strip.fill(red, 10, 4); //red
  strip.fill(white, 14, 2);  //white
  strip.fill(red, 16, 4); //red
  strip.fill(white, 20, 2);  //white
  strip.fill(red, 22, 4); //red
  strip.fill(white, 26, 2);  //white
  strip.fill(red, 28, 4); //red
  strip.fill(white, 32, 2);  //white
  strip.fill(red, 34, 2); //red

  strip.show();
  delay(wait);
  strip.setPixelColor(43, white);
}

void sierraLeone(int wait)
{
  uint32_t green = strip.Color(0,186,24);
  uint32_t blue = strip.Color(0,114,203);
  strip.fill(green, 0, 12); //green
  strip.fill(white, 12, 12);  //white
  strip.fill(blue, 24, 12); //blue

  strip.show();
  delay(wait);
  strip.setPixelColor(44, white);
}

void thailand(int wait)
{
  uint32_t red = strip.Color(255,3,3);
  uint32_t  blue = strip.Color(45,42,255);
  strip.fill(red, 0, 6); //red
  strip.fill(white, 6, 6);  //white
  strip.fill(blue, 12, 12); //blue
  strip.fill(white, 24, 6);  //white
  strip.fill(red, 30, 6); //red

  strip.show();
  delay(wait);
  strip.setPixelColor(45, white);
}