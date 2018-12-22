//code write by Moz for YouTube changel LogMaker360, 27-10-2015
//code belongs to this video: https://www.youtube.com/watch?v=6jZMJ7DFCY0

#include <SoftwareSerial.h>
#include <FastLED.h>

#define LED_PIN     9
#define NUM_LEDS    7

CRGB leds[NUM_LEDS];
SoftwareSerial BT(11, 10); 
//SoftwareSerial BT(1, 0); 
// creates a "virtual" serial port/UART
// connect BT module TX to 0
// connect BT module RX to 1
// connect BT Vcc to 5V, GND to GND
void setup()  
{
  // set digital pin to control as an output
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  // set the data rate for the SoftwareSerial port
  // Send test message to other device
  Serial.begin(9600);
  Serial.println("Serial ready");
  BT.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  BT.println("Bluetooth ready");
}
char a; // stores incoming character from other device
void display(int i){
  for(int j = 0; j < 7; j++){
    if((i - 2 + j) < 7)
      leds[i - 2 + j] = CRGB(0, 60, 60);
    if((i - 2 - j) > 0)
      leds[i - 2 - j] = CRGB(0, 60, 60);
    FastLED.show();
    delay(400);
    }
} 
void loop() 
{
  for(int i = 2; i < 9; i++){
    if(digitalRead(i)== LOW){
        //Serial.println(i);
        //Serial.println(" is touched");
        //leds[i-2] = CRGB(0, 60, 60);
        BT.println(i);
        //FastLED.show();
        display(i);
      }
    else{
      leds[i-2] = CRGB(85, 60, 180);
      FastLED.show();
    }
  }
  /*for(int i = 0; i < 10; i++){
    BT.print(i);
    delay(2000);
  }*/
  
}
