
#include <Adafruit_MPU6050.h>
#include "lcd/lcd.h"
//#include <Adafruit_SSD1306.h>
static void tcaselect(uint8_t i);

Adafruit_MPU6050 mpu;
//Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);
//================================
static void mpu6050Init(void) {

  tcaselect(0);//Adafruit TCA9548A I2C Multiplexer module
   // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
//  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
//    Serial.println(F("SSD1306 allocation failed"));
//    for (;;)
//      ; // Don't proceed, loop forever
//  }
//  display.display();
//  delay(500); // Pause for 2 seconds
//  display.setTextSize(1);
//  display.setTextColor(WHITE);
//  display.setRotation(0);
  
}
extern SensorState currentState;

//===================================
static void mpu6050Read(void) {

tcaselect(0);//Adafruit TCA9548A I2C Multiplexer module

sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  currentState.acceleration_x = a.acceleration.x;
  currentState.acceleration_y = a.acceleration.y;
  currentState.acceleration_z = a.acceleration.z;

  currentState.gyro_x = g.gyro.x;
  currentState.gyro_y = g.gyro.y;
  currentState.gyro_z = g.gyro.z;

//  display.clearDisplay();
// display.setCursor(0, 0);
/*
  Serial.print("Accelerometer ");
  Serial.print("X: ");
  Serial.print(a.acceleration.x, 1);
  Serial.print(" m/s^2, ");
  Serial.print("Y: ");
  Serial.print(a.acceleration.y, 1);
  Serial.print(" m/s^2, ");
  Serial.print("Z: ");
  Serial.print(a.acceleration.z, 1);
  Serial.println(" m/s^2");*/

/*  display.println("Accelerometer - m/s^2");
  display.print(a.acceleration.x, 1);
  display.print(", ");
  display.print(a.acceleration.y, 1);
  display.print(", ");
  display.print(a.acceleration.z, 1);
  display.println("");*/
/*
  Serial.print("Gyroscope ");
  Serial.print("X: ");
  Serial.print(g.gyro.x, 1);
  Serial.print(" rps, ");
  Serial.print("Y: ");
  Serial.print(g.gyro.y, 1);
  Serial.print(" rps, ");
  Serial.print("Z: ");
  Serial.print(g.gyro.z, 1);
  Serial.println(" rps");
*/
  /* display.println("Gyroscope - rps");
  display.print(g.gyro.x, 1);
  display.print(", ");
  display.print(g.gyro.y, 1);
  display.print(", ");
  display.print(g.gyro.z, 1);
  display.println("");

  display.display();
  delay(100);
  */
}