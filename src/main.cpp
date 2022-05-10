#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>

#define LED 15
static bool status = HIGH;
Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  if (aht.begin()) {
    Serial.println("Found AHT20");
  } else {
    Serial.println("Didn't find AHT20");
  } 
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);
  Serial.printf("Temperature: %f C degrees\n", temp.temperature);
  Serial.printf("Hum: %f RH\n", humidity.relative_humidity);
  digitalWrite(LED, status);
  status = !status;
  delay(10000);
}