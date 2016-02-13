#include <Servo.h>

Servo servo;

int x;
int y;


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

  if (state1 == HIGH){ 

    for (int x=20; x<170; x++){
    servo.write(x);
    state1 = digitalRead(button1);
      
      if (state1 == LOW){
      servo.write(x--);
      state1 = digitalRead(button1);
      state2 = digitalRead(button2);


              if (state2 == HIGH){ 
              
              for (int y=170; y>20; y--){
              servo.write(y);
              state2 = digitalRead(button2);
              
              if (state2 == LOW){
              servo.write(y++);
              delay(20);
              
              }
              delay(20);
              }  
              }

      
      delay(20);

      }
    delay(20);
    }  
   }

   if (state2 == HIGH){ 

    for (int y=170; y>20; y--){
    servo.write(y);
    state2 = digitalRead(button2);
    state1 = digitalRead(button2);

      if (state2 == LOW){
      servo.write(y++);
          
          if (state1 == HIGH){ 
          
          for (int x=20; x<170; x++){
          servo.write(x);
          state1 = digitalRead(button1);
          
          if (state1 == LOW){
          servo.write(x--);
          state2 = digitalRead(button2);
          
          delay(20);
          
          }
          delay(20);
          }  
          }
      
      delay(20);

      }
    delay(20);
   }  
  }

}





  

