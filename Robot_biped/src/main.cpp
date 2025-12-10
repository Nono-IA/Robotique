#include <Arduino.h>
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

int a = 0; // compteur boucle
int distD;
int distG; // distance obstacle
int analogPinG = 1;
int analogPinD = 0;
bool mar; // mode marche(true) ou course(false)
int vitesse_etape = 0;
int vitesse_equilibre = 75;  // 100ms pour que le robot se stabilise
int vitesse_redescente = 17; // 30ms pour descendre tranquillement
int vitesse_smooth = 8 ;

void initia()
{
    servogauchebassin.write(80);
    servodroitebassin.write(80);
    servogauchepied.write(80);
    servodroitepied.write(80);
    mar = true;
}

void marche()
{
    // etape1
    servogauchepied.write(105);
    delay(vitesse_equilibre);
    servodroitepied.write(100);
    delay(vitesse_etape);

    // etape2
    if (mar)
    {
        for (int i = 0; i < 25; i++)
        {

            servodroitebassin.write(80 - i);
            servogauchebassin.write(80 - i);
            delay(vitesse_smooth);
        } // 80 to 55
    }
    else
    {
        for (int i = 0; i < 50; i++)
        {

            servodroitebassin.write(105 - i);
            servogauchebassin.write(105 - i);
            delay(vitesse_smooth);
        } // 105 to 55
    }
    servogauchepied.write(80);
    delay(vitesse_etape);

    // etape3  // 100 to 80
    for (int i = 0; i < 20; i++)
    {
        servodroitepied.write(100 - i);
        delay(vitesse_redescente);
    }
    delay(vitesse_etape);

    // etape4
    servodroitepied.write(45);
    delay(vitesse_equilibre);
    servogauchepied.write(60);
    delay(vitesse_etape);

    // etape5  // 55 to 80
    for (int i = 0; i < 25; i++)
    {
        servodroitebassin.write(55 + i);
        servogauchebassin.write(55 + i);
        delay(vitesse_smooth);
    }
    servodroitepied.write(80);
    delay(vitesse_etape);

    // etape6  // 60 to 80
    for (int i = 0; i < 20; i++)
    {
        servogauchepied.write(60 + i);
        delay(vitesse_redescente);
    }
    delay(vitesse_etape);
    mar = true;
}

void course()
{

    // etape1
    servogauchepied.write(105);
    delay(vitesse_equilibre);
    servodroitepied.write(100);
    delay(vitesse_etape);

    // etape2
    if (mar)
    {
        for (int i = 0; i < 25; i++)
        {
            servodroitebassin.write(80 - i);
            servogauchebassin.write(80 - i);
            delay(vitesse_smooth);
        } // 80 to 55
    }
    else
    {
        for (int i = 0; i < 50; i++)
        {
            servodroitebassin.write(105 - i);
            servogauchebassin.write(105 - i);
            delay(vitesse_smooth);
        } // 105 to 55
    }
    servogauchepied.write(80);

    // etape3  // 100 to 80
    for (int i = 0; i < 20; i++)
    {
        servodroitepied.write(100 - i);
        delay(vitesse_redescente);
    }

    // etape4
    servodroitepied.write(45);
    delay(vitesse_equilibre);
    servogauchepied.write(60);
    delay(vitesse_etape);

    // etape5
    for (int i = 0; i < 55; i++)
    {
        Serial.println(i);
        servodroitebassin.write(50 + i);
        servogauchebassin.write(50 + i);
        delay(vitesse_smooth);
    } // angle 50 to 105
    servodroitepied.write(80);

    // etape6  // 60 to 80
    for (int i = 0; i < 20; i++)
    {
        servogauchepied.write(60 + i);
        delay(vitesse_redescente);
    }

    mar = false;
}

void droite()
{
    if (mar == false)
    {
        initia();
    }
    // etape1
    servogauchepied.write(105);
    delay(vitesse_equilibre);
    servodroitepied.write(100);
    delay(vitesse_etape);

    // etape2
    // baisser servodroitebassin de 80 à 55
    for (int i = 80; i >= 55; i--)
    {
        servodroitebassin.write(i);
        delay(vitesse_smooth);
    }
    // ramener servogauchepied vers 80
    for (int i = 105; i >= 80; i--)
    {
        servogauchepied.write(i);
        delay(vitesse_smooth);
    }
    delay(vitesse_etape);

    // etape3
    // abaisser servodroitepied vers 80
    for (int i = 105; i >= 80; i--)
    {
        servodroitepied.write(i);
        delay(vitesse_redescente);
    }
    delay(vitesse_etape);

    // etape4
    // baisser servogauchepied vers 60
    servogauchepied.write(60);
    delay(vitesse_equilibre);

    // remettre servodroitebassin et servogauchepied à 80 en douceur
    for (int i = 55; i <= 80; i++)
    {
        servodroitebassin.write(i);
        delay(vitesse_smooth);
    }
    for (int i = 60; i <= 80; i++)
    {
        servogauchepied.write(i);
        delay(vitesse_redescente);
    }
    delay(vitesse_etape);
}

void gauche()
{
    if (mar == false)
    {
        initia();
    }
    // etape1
    servodroitepied.write(45);
    delay(vitesse_equilibre);
    servogauchepied.write(60);
    delay(vitesse_etape);

    // etape2
    // pousser servogauchebassin vers 95 depuis 80
    for (int i = 80; i <= 95; i++)
    {
        servogauchebassin.write(i);
        delay(vitesse_smooth);
    }
    // ramener servodroitepied vers 80
    for (int i = 45; i <= 80; i++)
    {
        servodroitepied.write(i);
        delay(vitesse_smooth);
    }
    delay(vitesse_etape);

    // etape3
    // remettre servogauchepied à 80 en douceur
    for (int i = 60; i <= 80; i++)
    {
        servogauchepied.write(i);
        delay(vitesse_redescente);
    }
    // pousser servodroitepied vers 95 progressivement
    servodroitepied.write(95);
    delay(vitesse_equilibre);
    delay(vitesse_etape);

    // etape4
    // ramener servogauchebassin et servodroitepied à 80 en douceur
    for (int i = 95; i >= 80; i--)
    {
        servogauchebassin.write(i);
        delay(vitesse_smooth);
    }
    for (int i = 95; i >= 80; i--)
    {
        servodroitepied.write(i);
        delay(vitesse_redescente);
    }
    delay(vitesse_etape);
}

void arriere()
{

    // etape1
    servogauchepied.write(105);
    delay(vitesse_equilibre);
    servodroitepied.write(100);
    delay(vitesse_etape);

    // etape2
    // pousser bassin arrière vers 105
    for (int i = 80; i <= 105; i++)
    {
        servodroitebassin.write(i);
        servogauchebassin.write(i);
        delay(vitesse_smooth);
    }
    // ramener servogauchepied à 80
    for (int i = 105; i >= 80; i--)
    {
        servogauchepied.write(i);
        delay(vitesse_smooth);
    }
    delay(vitesse_etape);

    // etape3
    // remettre servodroitepied à 80 en douceur
    for (int i = 100; i >= 80; i--)
    {
        servodroitepied.write(i);
        delay(vitesse_redescente);
    }
    delay(vitesse_etape);

    // etape4
    // abaisser servodroitepied vers 45 puis remonter servogauchepied vers 60
    servodroitepied.write(45);
    delay(vitesse_equilibre);
    servogauchepied.write(60);
    delay(vitesse_etape);

    // etape5
    // ramener bassins à 80 et pied droit à 80 doucement
    for (int i = 105; i >= 80; i--)
    {
        servodroitebassin.write(i);
        servogauchebassin.write(i);
        delay(vitesse_smooth);
    }
    for (int i = 45; i <= 80; i++)
    {
        servodroitepied.write(i);
        delay(vitesse_redescente);
    }
    delay(vitesse_etape);

    // etape6
    // remettre servogauchepied à 80 doucement
    for (int i = 60; i <= 80; i++)
    {
        servogauchepied.write(i);
        delay(vitesse_redescente);
    }
    delay(vitesse_etape);
}

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
        while (distD <= 300 || distG <= 300)
        {
            distD = analogRead(analogPinD);
            distG = analogRead(analogPinG);
            Serial.print("distG = ");
            Serial.print(distG);
            Serial.print(": distD = ");
            Serial.println(distD);
            delay(200);
        }
        a = a + 1;
    }
    {
        distD = analogRead(analogPinD);
        distG = analogRead(analogPinG);
        Serial.print("distG = ");
        Serial.print(distG);
        Serial.print(": distD = ");
        Serial.println(distD);
        delay(200);
    }

    // Logique d'évitement d'obstacles
    if (distD >= 200 && distG >= 200) // obstacle devant les deux capteurs
    {
        while (distD >= 200 && distG >= 200)
        {
            arriere();
            distD = analogRead(analogPinD);
            distG = analogRead(analogPinG);
        }
    }
    if (distD >= 100 && distG <= 100) // obstacle à droite seulement
    {
        while (distD >= 100 && distG <= 100)
        {
            gauche();
            distD = analogRead(analogPinD);
            distG = analogRead(analogPinG);
        }
    }
    if (distD <= 150 && distG >= 150) // obstacle à gauche seulement
    {
        while (distD <= 150 && distG >= 100)
        {
            droite();
            distD = analogRead(analogPinD);
            distG = analogRead(analogPinG);
        }
    }
    if (distD <= 70 && distG <= 70) // pas d'obstacle
    {
        course();
    }
    else // pas d'obstacle proche
    {
        marche();
    }
    

    /*// Algorithme de la main droite
    if (distD < 150)
    {
        // Si pas d'obstacle à droite, avancer
        marche();
    }
    else if (distD >= 150 && distG < 150)
    {
        // Si obstacle à droite mais pas à gauche, tourner à droite pour suivre le mur
        droite();
    }
    else if (distD >= 150 && distG >= 150)
    {
        // Si obstacles des deux côtés, faire demi-tour
        arriere();
    }
    else
    {
        // Si obstacle à gauche mais pas à droite, avancer ou ajuster
        marche();
    }*/
}
