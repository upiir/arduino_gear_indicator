// Arduino UNO gear indicator for manual transmission for a car
// using SSD1306 IIC 128x64px OLED display and 4 Hall sensors
// since Hall sensors are not supported on WOKWI, they are simulated with potentiometers

// created by upir, 2023
// youtube channel: https://www.youtube.com/upir_upir

// YOUTUBE VIDEO: https://youtu.be/QixtxaAda18
// Source Files: https://github.com/upiir/arduino_gear_indicator
// WOKWI Sketch: https://wokwi.com/projects/392232701520726017

// Links from the video:
// AH3503 Hall Sensor : https://s.click.aliexpress.com/e/_DEYCKSl
// Round magnets: https://s.click.aliexpress.com/e/_DEzBT9B
// Shifter handle: https://s.click.aliexpress.com/e/_DddI3NR
// 128x64 SSD1306 OLED Display 1.54": https://s.click.aliexpress.com/e/_DCYdWXb 
// 128x64 SSD1306 OLED Display 0.96": https://s.click.aliexpress.com/e/_DCKdvnh
// 128x64 SSD1306 OLED Display 2.42": https://s.click.aliexpress.com/e/_DFdMoTh
// Arduino UNO: https://s.click.aliexpress.com/e/_AXDw1h
// Arduino breadboard prototyping shield: https://s.click.aliexpress.com/e/_ApbCwx
// Breadboard wires: https://s.click.aliexpress.com/e/_DmMQcLB
// Arduino breadboard holder: https://github.com/LaskaKit/LaskaKit-Printed-Parts/tree/main/Arduino%20Uno%20Breadboard%20400%20Holder
// Image2cpp (convert array to image): https://javl.github.io/image2cpp/
// Photopea (online graphics editor like Photoshop): https://www.photopea.com/
// KiCad (for designing PCBs): https://www.kicad.org/

// Related videos with Arduino UNO and 128x64 OLED screen:
// Arduino OLED menu: https://youtu.be/HVHVkKt-ldc
// U8g vs U8g2: https://youtu.be/K5e0lFRvZ2E
// Arduino Parking Sensor - https://youtu.be/sEWw087KOj0
// Turbo pressure gauge with Arduino and OLED display - https://youtu.be/JXmw1xOlBdk
// Arduino Car Cluster with OLED Display - https://youtu.be/El5SJelwV_0
// Knob over OLED Display - https://youtu.be/SmbcNx7tbX8
// Arduino + OLED = 3D ? - https://youtu.be/kBAcaA7NAlA
// Arduino OLED Gauge - https://youtu.be/xI6dXTA02UQ
// Smaller & Faster Arduino - https://youtu.be/4GfPQoIRqW8
// Save Image from OLED Display to PC - https://youtu.be/Ft2pRMVm44E


#include <U8g2lib.h> // u8g2 library is used to draw on the OLED screen
#include <Wire.h> // library required for IIC communication
#include "gear_bitmaps.h" // small bitmaps for gears
#include "gear_bitmaps_fullscreen.h" // fullscreen bitmaps for gears

//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R3, /* reset=*/ U8X8_PIN_NONE); // initialization for the used OLED display, rotated by 90°
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // initialization for the used OLED display

const unsigned char upir_logo [] PROGMEM = { 0xEA, 0x3A, 0xAA, 0x28, 0x6A, 0x1A, 0x26, 0x2A, }; // upir logo

int current_gear = 0;  // -1 = R, 0 = N, 1 = 1, 2 = 2, ...
int mode = 0; // mode 0 = debug, 1 = fullscreen images

void setup() {   // put your setup code here, to run once

  pinMode(A0, INPUT); // set pin A0 as input to read analog voltage from the Hall Sensor
  pinMode(A1, INPUT); // set pin A1 as input to read analog voltage from the Hall Sensor
  pinMode(A2, INPUT); // set pin A2 as input to read analog voltage from the Hall Sensor
  pinMode(A3, INPUT); // set pin A3 as input to read analog voltage from the Hall Sensor

  u8g2.begin(); // start the u8g2 library
}

void loop() { // put your main code here, to run repeatedly

  int hall_0_value = analogRead(A0); // read the analog value on pin A0, value will be between 0 - 1023
  int hall_1_value = analogRead(A1); // read the analog value on pin A1, value will be between 0 - 1023
  int hall_2_value = analogRead(A2); // read the analog value on pin A2, value will be between 0 - 1023
  int hall_3_value = analogRead(A3); // read the analog value on pin A3, value will be between 0 - 1023

  int percentage_value_0 = round(abs(hall_0_value - 512) / 5.12); // convert hall value to range 0-100%
  int percentage_value_1 = round(abs(hall_1_value - 512) / 5.12); // convert hall value to range 0-100%
  int percentage_value_2 = round(abs(hall_2_value - 512) / 5.12); // convert hall value to range 0-100%
  int percentage_value_3 = round(abs(hall_3_value - 512) / 5.12); // convert hall value to range 0-100%

  // calculate the current gear
  // hall sensors are arranged like this
  //
  //   A0               A3
  //      1     3     5
  //      │     │     │
  //      ├─────┼─────┘
  //      │     │     │
  //      2     4     R
  //   A1               A2

  if (percentage_value_0 > 30 && percentage_value_3 > 30) {
    current_gear = 3; // 3rd gear
  }
  else if (percentage_value_1 > 30 && percentage_value_2 > 30) {
    current_gear = 4; // 4th gear
  }
  else if (percentage_value_0 > 30) {
    current_gear = 1; // 1st gear
  }
  else if (percentage_value_3 > 30) {
    current_gear = 5; // 5th gear
  }
  else if (percentage_value_1 > 30) {
    current_gear = 2; // 2nd gear
  }
  else if (percentage_value_2 > 30) {
    current_gear = -1; // reverse
  }
  else {
    current_gear = 0; // neutral
  }


  mode = digitalRead(3); // set the screen layout based on the value on pin3: 0 = debug, 1 = fullscreen images

  u8g2.clearBuffer();	// clear the internal memory

  if (mode == 0) { // debug mode with circles and smaller images

    // draw four circles
    u8g2.drawCircle(16, 16, round(percentage_value_0 * 0.16), U8G2_DRAW_ALL);  // max radius should be 16px (100% * 0.16 = 16px)
    u8g2.drawCircle(16, 16 + 32, round(percentage_value_1 * 0.16), U8G2_DRAW_ALL);
    u8g2.drawCircle(16 + 32, 16 + 32, round(percentage_value_2 * 0.16), U8G2_DRAW_ALL);
    u8g2.drawCircle(16 + 32, 16, round(percentage_value_3 * 0.16), U8G2_DRAW_ALL);

    // draw four labels with percentage values
    u8g2.setFont(u8g2_font_pressstart2p_8u); // set font
    u8g2.setCursor(0, 20);
    u8g2.print(percentage_value_0);

    u8g2.setCursor(0, 20 + 32);
    u8g2.print(percentage_value_1);

    u8g2.setCursor(0 + 32, 20 + 32);
    u8g2.print(percentage_value_2);

    u8g2.setCursor(0 + 32, 20);
    u8g2.print(percentage_value_3);

    u8g2.setDrawColor(1); // set the drawing color to white
    u8g2.setBitmapMode(1); // draw transparent images

    u8g2.drawXBMP(64, 0, 64, 64, gear_bitmaps[current_gear + 1]); // draw the current gear bitmap on the right side of the screen
    u8g2.drawXBMP(128-16-4, 64-4, 16, 4, upir_logo);   // draw upir logo   

  } else { // fullscreen images
    u8g2.drawXBMP(28, 0, 72, 64, bitmaps_gears_fullscreen[current_gear + 1]);
    u8g2.drawXBMP(128-16-4, 64-4, 16, 4, upir_logo);   // draw upir logo   
  }

  u8g2.sendBuffer(); // transfer internal memory to the display
}

