#include <Servo.h>

Servo servo;

int led = 8;

void setup() {
  servo.attach(12);
  pinMode(led, OUTPUT);
}

void loop() {
 
 servo.write(60);
 digitalWrite(led, HIGH);
 delay(2000);
 digitalWrite(led, LOW);
 servo.write(30);


}
