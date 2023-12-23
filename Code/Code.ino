// ###########################################################################################################################################
// #
// # Code for the printables "XMAS neon LED star" project:
// # https://www.printables.com/de/model/683004-xmas-neon-led-star
// #
// # Code by https://github.com/AWSW-de
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/NEON-LED-STAR#GPL-3.0-1-ov-file
// #
// ###########################################################################################################################################


// ###########################################################################################################################################
// # Code version:
// ###########################################################################################################################################
String Code_Version = "V1.0.0";


// ###########################################################################################################################################
// # Settings:
// ###########################################################################################################################################
int UseAnimation = 1;  // Turn animation on (1) or off (0) during runtime


// ###########################################################################################################################################
// # Includes:
// #
// # FastLED                // by Daniel Garcia               // https://github.com/FastLED/FastLED
// #
// ###########################################################################################################################################
#include "FastLED.h"


// ###########################################################################################################################################
// # Hardware settings:
// ###########################################################################################################################################
// How many LEDs are in your neon LED strip?:
#define NUM_LEDS 22
// Data pin - here D5 with GPIO 14 on the Wemos D1 mini ESP8266:
#define DATA_PIN 14


// ###########################################################################################################################################
// # Definitions:
// ###########################################################################################################################################
// Define the array of leds:
CRGB leds[NUM_LEDS];


// ###########################################################################################################################################
// # Startup function:
// ###########################################################################################################################################
void setup() {
  // Initialize the LED strip:
  FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);

  // Switch all LEDs off first:
  LEDS.showColor(CRGB(0, 0, 0));

  // Set LED brightness (0-255);
  LEDS.setBrightness(255);

  // Some animation and LED color output testing first:

  // Set all LEDs to red:
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(25);
  }
  delay(1000);

  // Set all LEDs to green:
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(25);
  }
  delay(1000);

  // Set all LEDs to blue:
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(25);
  }
  delay(1000);

  // Set all LEDs to white:
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::White;  // <<< LAST COLOR WHEN ANIMATION IS TURNED OFF <<<
    FastLED.show();
    delay(25);
  }
  delay(1000);
}


// ###########################################################################################################################################
// # Runtime function:
// ###########################################################################################################################################
void loop() {
  if (UseAnimation == 1) {
    // Set all LEDs to green and run a white pixel around:
    for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::White;
      leds[i - 1] = CRGB::Green;
      FastLED.show();
      delay(250);
    }

    delay(5000);  // Wait 5 seconds

    // Set all LEDs to white and run a red pixel around:
    for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::Red;
      leds[i - 1] = CRGB::White;
      FastLED.show();
      delay(250);
    }

    delay(5000);  // Wait 5 seconds

    // Set all LEDs to green and run a cyan pixel around:
    for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::Cyan;
      leds[i - 1] = CRGB::Green;
      FastLED.show();
      delay(250);
    }

    delay(5000);  // Wait 5 seconds

    // Set all LEDs to white:
    for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::White;
      FastLED.show();
      delay(250);
    }

    delay(5000);  // Wait 5 seconds

    // Set all LEDs to yellow:
    for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::Yellow;
      FastLED.show();
      delay(250);
    }

    delay(5000);  // Wait 5 seconds

    // Set all LEDs to cyan:
    for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::Cyan;
      FastLED.show();
      delay(250);
    }

    delay(5000);  // Wait 5 seconds

    // Set all LEDs to orange:
    for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CRGB::Orange;
      FastLED.show();
      delay(250);
    }

    delay(5000);  // Wait 5 seconds
  }
}