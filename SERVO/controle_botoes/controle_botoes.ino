#include <Servo.h>

Servo servo;

int x = 90;

int state1;
int state2;

int button1 = 3;
int button2 = 2;

void setup() {

  servo.attach(12);

}

void loop() {

  state2 = digitalRead(button2);
  state1 = digitalRead(button1);

  if (state2 == HIGH){
    state2 = digitalRead(button2); 
    servo.write(x);
    x++;
    delay(10);
    } else {
      servo.write(x);
    }

  
  if (state1 == HIGH){
    state1 = digitalRead(button1); 
    servo.write(x);
    x--;
    delay(10);
    } else {
      servo.write(x);
    }
  
}





  

