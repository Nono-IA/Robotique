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

int a = 0;       //compteur boucle
int distD; 
int distG;// distance obstacle 
int analogPinG = 1;
int analogPinD = 0;

void loop()
{
    initia();
    distD = analogRead(analogPinD);
    distG = analogRead(analogPinG);
    Serial.print("distG = ");
    Serial.println(distG);
    //if (a == 0)
    //{
    //     initia();
    //}
    //a = a + 1;
    //arriere();
    //if (a > 10)
    //{
    //    marche();
    //}
    //while (a > 0)
    //{
    //    initia();
    //}
}

void initia()
{
    servogauchepied.write(60);
    servodroitepied.write(100);
    servogauchebassin.write(80);
    servodroitebassin.write(80);
    servogauchepied.write(80);
    servodroitepied.write(80);
    delay(100);
}

void marche()
{
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

void course()
{
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
    servodroitebassin.write(105);
    servogauchebassin.write(105);
    servodroitepied.write(80);
    delay(200);

    'etape6';
    servogauchepied.write(80);
    delay(300);
}

void droite ()
{
    'etape1';
    servogauchepied.write(110);
    delay(100);
    servodroitepied.write(105);
    delay(500);

    'etape2';
    servodroitebassin.write(45);
    servogauchepied.write(80);
    delay(300);

    'etape3';
    servodroitepied.write(70);
    delay(110);
    servogauchepied.write(55);
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
    servodroitepied.write(40);
    delay(150);
    servogauchepied.write(55);
    delay(300);

    'etape2';
    servogauchebassin.write(95);
    servodroitepied.write(80);
    delay(300);

    'etape3';
    servogauchepied.write(80);
    delay(100);
    servodroitepied.write(100);
    delay(300);

    'etape4';
    servogauchebassin.write(80);
    servodroitepied.write(80);
    delay(300);

}

void arriere ()
{
    'etape1';
    servogauchepied.write(110);
    delay(100);
    servodroitepied.write(105);
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
