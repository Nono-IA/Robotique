#include <Servo.h>
Servo servogauchepied,servodroitepied,servogauchebassin,servodroitebassin;
void setup() {
servodroitepied.attach(4);
servodroitebassin.attach(5);
servogauchepied.attach(6);
servogauchebassin.attach(7);
}
int a = 0;

void loop() {
  'setup';
  if (a==0){
    servogauchepied.write(60);
    servodroitepied.write(100);
    servogauchebassin.write(80);
    servodroitebassin.write(80);
    servogauchepied.write(80);
    servodroitepied.write(80);
    delay(1000);
    a=1;
  }

  'etape1';
  servogauchepied.write(110);
  delay(100);
  servodroitepied.write(105);
  delay(500);
 
 
  'etape2';
  servodroitebassin.write(55);
  servogauchebassin.write(55);
  servogauchepied.write(80);
  delay(300);

  'etape3';
  servodroitepied.write(80);
  delay(300);

 
  'etape4';
  servodroitepied.write(40);
  delay(150);
  servogauchepied.write(55);
  delay(300);

  'etape5';
  servodroitebassin.write(80);
  servogauchebassin.write(80);
  servodroitepied.write(80);
  delay(300);

  'etape6';
  servogauchepied.write(80);
  delay(300);

}

