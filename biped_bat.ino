#include <Servo.h>

Servo servogauchepied, servodroitepied, servogauchebassin, servodroitebassin;
void setup()
{
    Serial.begin(9600);
    Serial.flush();
    servodroitepied.attach(4);
    servodroitebassin.attach(5);
    servogauchepied.attach(6);
    servogauchebassin.attach(7);
   
}

int a = 0;    //compteur boucle
int distD; 
int distG;// distance obstacle 
int analogPinG = 1;
int analogPinD = 0;

void loop()
{
    distD = analogRead(analogPinD);
    distG = analogRead(analogPinG);
    Serial.print("distG = ");
    Serial.print(distG);
    Serial.print(": distD = ");
    Serial.println(distD);
    if (a == 0)
    {
        initia();
    }
    a = a + 1;
    if (distD >= 250 && distG >=250){
        while (distD >= 250 && distG >=250){
            arriere();
            distD = analogRead(analogPinD);
            distG = analogRead(analogPinG);
        }
    }
    if (distD >= 250 && distG <=250){
        while (distD >= 250 && distG <=250){
            gauche();
            distD = analogRead(analogPinD);
            distG = analogRead(analogPinG);
        }
    }
    if (distD <= 250 && distG >=250){
        while (distD <= 250 && distG >=250){
            droite();
            distD = analogRead(analogPinD);
            distG = analogRead(analogPinG);
        }
    }
    if(distD <= 100 && distG <= 100){
        course();
    }
    else{
        marche();
    }
}

void initia()
{
    servogauchebassin.write(80);
    servodroitebassin.write(80);
    servogauchepied.write(80);
    servodroitepied.write(80);
    delay(100);
}

void marche()
{
    'etape1';
    servogauchepied.write(105);
    delay(100);
    servodroitepied.write(100);
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
    servodroitepied.write(45);
    delay(150);
    servogauchepied.write(60);
    delay(300);

    'etape5';
    servodroitebassin.write(60);
    servogauchebassin.write(60);
    delay(70);
    servodroitebassin.write(70);
    servogauchebassin.write(70);
    delay(70);
    servodroitebassin.write(80);
    servogauchebassin.write(80);
    servodroitepied.write(80);
    delay(300);

    'etape6';
    servogauchepied.write(80);
    delay(300);
}

void course()
{
    'etape1';
    servogauchepied.write(105);
    delay(100);
    servodroitepied.write(100);
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
    servodroitepied.write(45);
    delay(150);
    servogauchepied.write(60);
    delay(300);

    'etape5';
    servodroitebassin.write(65);
    servogauchebassin.write(65);
    delay(100);
    servodroitebassin.write(80);
    servogauchebassin.write(80);
    delay(100);
    servodroitebassin.write(90);
    servogauchebassin.write(90);
    servodroitepied.write(80);
    delay(100);
    servodroitebassin.write(105);
    servogauchebassin.write(105);
    delay(200);

    'etape6';
    servogauchepied.write(80);
    delay(500);
}

void droite ()
{
    'etape1';
    servogauchepied.write(105);
    delay(100);
    servodroitepied.write(100);
    delay(500);

    'etape2';
    servodroitebassin.write(55);
    servogauchepied.write(80);
    delay(300);

    'etape3';
    servodroitepied.write(75);
    delay(110);
    servogauchepied.write(60);
    servodroitepied.write(80);
    delay(300);

    'etape4';
    servodroitebassin.write(80);
    servogauchepied.write(80);
    delay(300);

}

void gauche ()
{
    'etape1';
    servodroitepied.write(45);
    delay(150);
    servogauchepied.write(60);
    delay(300);

    'etape2';
    servogauchebassin.write(95);
    servodroitepied.write(80);
    delay(300);

    'etape3';
    servogauchepied.write(80);
    delay(100);
    servodroitepied.write(95);
    delay(300);

    'etape4';
    servogauchebassin.write(80);
    servodroitepied.write(80);
    delay(300);

}

void arriere ()
{
    'etape1';
    servogauchepied.write(105);
    delay(100);
    servodroitepied.write(100);
    delay(500);

    'etape2';
    servodroitebassin.write(105);
    servogauchebassin.write(105);
    servogauchepied.write(80);
    delay(300);

    'etape3';
    servodroitepied.write(80);
    delay(300);

    'etape4';
    servodroitepied.write(45);
    delay(150);
    servogauchepied.write(60);
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
