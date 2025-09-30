#include <Arduino.h>

#include "pin.h"
#include "motori.h"

int motori[4] [3] = {
   {M1_PWM, M1_INB, M1_INA},
   {M2_PWM, M2_INB, M2_INA},
   {M3_PWM, M3_INB, M3_INA},
   {M4_PWM, M4_INB, M4_INA}};

void inzpmot (){
    for (int i=0; i<=3; i++){
        for (int j=0; j<=2; j++){
            pinMode(motori[i] [j], OUTPUT);
        }
    }
}

void commot (int qua, int  pwm){
    analogWrite(qua[motori][0], abs(pwm));
    digitalWrite(qua[motori][1], pwm>=0 ? HIGH : LOW);
    digitalWrite(qua[motori][2], pwm>=0 ? LOW : HIGH);

    /*int ina=motori[qua][1];
    int inb=motori[qua][2];
    int pwm1=motori[qua][0];
    digitalWrite(pwm1,200);
    //ORARIO
    digitalWrite(ina,LOW);
    digitalWrite(inb,HIGH);
    //ANTIORARIO
    digitalWrite(ina,HIGH);
    digitalWrite(inb,LOW);*/
   }

void testmot(){
    commot(0,80);
    delay(2000);
    commot(0,-80);
    delay(2000);
    commot(1,80);
    delay(2000);
    commot(1,-80);
    delay(2000);
    commot(2,80);
    delay(2000);
    commot(2,-80);
    delay(2000);
    commot(3,80);
    delay(2000);
    commot(3,-80);
    delay(2000);
    
}

void fermmot(){
    /*//motore 1
    digitalWrite(motori[0][0], HIGH);
    digitalWrite(motori[0][1], HIGH);
    analogWrite(motori[0][2], HIGH);
    //motore 2
    digitalWrite(motori[1][0], HIGH);
    digitalWrite(motori[1][1], HIGH);
    analogWrite(motori[1][2], HIGH);
    //motore 3
    digitalWrite(motori[2][0], HIGH);
    digitalWrite(motori[2][1], HIGH);
    analogWrite(motori[2][2], HIGH);
    //motore 4
    digitalWrite(motori[3][0], HIGH);
    digitalWrite(motori[3][1], HIGH);
    analogWrite(motori[3][2], HIGH);*/
}