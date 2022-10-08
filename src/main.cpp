#include <Arduino.h>

int test_num = 0;

void setup() {
  // put your setup code here, to run once:
  // Sets the data rate in bits per second(baud) for Serial data transmission
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.print(test_num++);
}