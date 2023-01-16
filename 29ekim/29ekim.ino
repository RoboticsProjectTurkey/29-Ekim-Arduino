int sayi; 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display;  

const unsigned char PROGMEM ataturk [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x20, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x24, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x30, 0x60, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xC0, 0x24, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0x04, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x48, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x01, 0x48, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x50, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x01, 0xC0, 0x02, 0x50, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x06, 0xC0, 0x00, 0xE0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x08, 0x80, 0x04, 0xF0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x30, 0x80, 0x21, 0xCC, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xC0, 0x80, 0x69, 0x82, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x00, 0x80, 0x31, 0x81, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC6, 0x01, 0x02, 0x31, 0x00, 0x40, 0x00, 0x00,
0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x98, 0x01, 0x12, 0x21, 0x00, 0x20, 0x00, 0x00,
0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1E, 0x01, 0xE0, 0x01, 0x34, 0x20, 0x00, 0x18, 0x00, 0x00,
0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x3A, 0x03, 0x80, 0x02, 0x24, 0x00, 0x00, 0x08, 0x00, 0x00,
0x00, 0x00, 0x0C, 0x02, 0x00, 0x00, 0x61, 0x47, 0x00, 0x02, 0x66, 0x00, 0x00, 0x04, 0x00, 0x00,
0x00, 0x00, 0x08, 0x02, 0x00, 0x00, 0xC3, 0x8F, 0x07, 0x02, 0xB0, 0x00, 0x00, 0x02, 0x00, 0x00,
0x00, 0x00, 0x18, 0x04, 0x00, 0x01, 0x83, 0xAE, 0x04, 0x84, 0x30, 0x00, 0x00, 0x01, 0x00, 0x00,
0x00, 0x00, 0x30, 0x08, 0x00, 0x03, 0x03, 0x0A, 0x09, 0x83, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
0x00, 0x00, 0x20, 0x08, 0x00, 0x02, 0x03, 0x02, 0x19, 0x02, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
0x00, 0x00, 0x60, 0x10, 0x00, 0x04, 0x07, 0x14, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
0x00, 0x00, 0x40, 0x20, 0x00, 0x08, 0x06, 0x04, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
0x00, 0x00, 0xC0, 0x40, 0x00, 0x18, 0x0E, 0x24, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
0x00, 0x00, 0x80, 0x80, 0x00, 0x30, 0x0E, 0x0C, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
0x00, 0x01, 0x81, 0x00, 0x00, 0x20, 0x1C, 0x48, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
0x00, 0x01, 0x02, 0x00, 0x00, 0x60, 0x14, 0x08, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
0x00, 0x03, 0x06, 0x00, 0x00, 0x40, 0x34, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
0x00, 0x06, 0x0C, 0x00, 0x00, 0x40, 0x29, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
0x00, 0x07, 0xFF, 0x00, 0x00, 0x80, 0x69, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
0x00, 0x1C, 0x30, 0xC0, 0x00, 0x80, 0x42, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
0x00, 0x68, 0xC0, 0x20, 0x01, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
0x00, 0x99, 0x80, 0x10, 0x01, 0x01, 0x9C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,
0x01, 0x1E, 0x00, 0x08, 0x01, 0x01, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00,
0x02, 0x38, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
0x01, 0xE0, 0x00, 0x04, 0x43, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
0x00, 0x40, 0x00, 0x04, 0xC2, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
0x00, 0xC0, 0x00, 0x00, 0x02, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x80, 0x00, 0x02, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x00, 0x00, 0x02, 0x01, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00,
0x02, 0x00, 0x00, 0x02, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00,
0x06, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
0x0C, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x18, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x20, 0x00, 0x10, 0x18, 0x00, 0x00, 0x00, 0x30, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x20, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x11, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

};
void setup()   {            
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.begin();
   

  // miniature bitmap display
}


void loop() {  
  display.clearDisplay();
  display.drawBitmap(0, 0, ataturk, 128, 64, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.display();
  delay(2500);
  display.clearDisplay();
  display.setCursor(10,55);
  display.print("Robotics Project");
  display.setTextSize(2);
  display.setCursor(23,0);
  display.print("29 Ekim");
  display.setCursor(35,20);
  display.print("Kutlu");
  display.setCursor(35,40);
  display.print("Olsun");
  display.display();
  delay(2500);
/*  sayi=sayi+1;
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0,0);
  display.println(sayi);
  display.setTextSize(3);
  display.println(sayi);
  display.display();
  display.clearDisplay();
 */ 
}
