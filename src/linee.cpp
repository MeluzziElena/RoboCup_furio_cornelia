#include <Arduino.h>
#include "linee.h"
#include "pin.h"
#include "moto.h"
#include "palla.h"
int direzione=0;
int sensori[8];
int grad[8];
bool linee[8];
void inizializa_linee(){
    Serial.begin(9600);
    grad[0]=138;/*FURIO*/
    grad[1]=135;/*FURIO*/
    grad[2]=122;/*FURIO*/
    grad[3]=106;/*FURIO*/
    grad[4]=128;/*FURIO*/
    grad[5]=116;/*FURIO*/
    grad[6]=78;/*FURIO*/
    grad[7]=80;/*FURIO*/
}
void lettura_linee(){
    sensori[0]=analogRead(S1IN);
    sensori[1]=analogRead(S1ES);
    sensori[2]=analogRead(S2IN);
    sensori[3]=analogRead(S2ES);
    sensori[4]=analogRead(S3IN);
    sensori[5]=analogRead(S3ES);
    sensori[6]=analogRead(S4IN);
    sensori[7]=analogRead(S4ES);
    for(int i=0; i<=7;i++){
        if(grad[i]<sensori[i]){
            linee[i]=true;
        }
        else{
            linee[i]=false;
        }
    }
}
bool hobeccatounalinea(){
    if(linee[0] || linee[1] || linee[2] || linee[3] || linee[4] || linee[5] || linee[6] || linee[7]){
        return true;
    }
    else{
        return false;}
    }
int movimento() {
    static unsigned long t=0;
    static bool sto_risolvendo_le_linee=false;
    int velocità = 200;
    if(hobeccatounalinea()) t=millis();
    if (millis()-t <= 400) {
        //Serial.println("vista");
        sto_risolvendo_le_linee=true;
        velocita(direzione,velocità);
    }
    else sto_risolvendo_le_linee=false;
    if ((linee[0] && linee[2]) | (linee[1] && linee[3])) {
        direzione=-135;
        } 
        else if ((linee[2] && linee[4]) || (linee[3] && linee[5])) {
            direzione=-45;
        } 
        else if ((linee[4] && linee[6]) || (linee[5] && linee[7])) {
            direzione=45;
        } 
        else if ((linee[6] && linee[0]) || (linee[7] && linee[1])) {
            direzione=135;
        } 
        else if ((linee[6] && linee[7]) || (linee[3] && linee[2])) {
            velocita(0, 0);
        }
        else if ((linee[0] && linee[1]) || (linee[5] && linee[4])) {
            velocita(0, 0);
        }      
        else if (linee[0] || linee[1]) {
            direzione=180;
        } 
        else if (linee[2] || linee[3]) {
            direzione=-90;
        } 
        else if (linee[4] || linee[5]) {
            direzione=0;
        } 
        else if (linee[6] || linee[7]) {
            direzione=90;
            
        }
       return sto_risolvendo_le_linee;
}
void test_linee(){
    Serial.println("----------------------");
    Serial.println (analogRead(S1IN));
    Serial.println (analogRead(S1ES));
    Serial.println (analogRead(S2IN));
    Serial.println (analogRead(S2ES));
    Serial.println (analogRead(S3IN));
    Serial.println (analogRead(S3ES));
    Serial.println (analogRead(S4IN));
    Serial.println (analogRead(S4ES));
   /*Serial.println("----------------------");
    Serial.println("----------------------");
    Serial.println (linee[0]);
    Serial.println (linee[1]);
    Serial.println (linee[2]);
    Serial.println (linee[3]);
    Serial.println (linee[4]);
    Serial.println (linee[5]);
    Serial.println (linee[6]);
    Serial.println (linee[7]);
    Serial.println("----------------------");*/
    delay(1000);
}









/*void movimento() {
        if (linee[0] || linee[1]) {
          direzione=180;//blocco davanti vel0,0
          t=millis();
        } 
        else if (linee[2] || linee[3]) {
            direzione=-90;
        } 
        else if (linee[4] || linee[5]) {
            direzione=0;
        } 
        else if (linee[6] || linee[7]) {
            direzione=90;
        } 
        else if ((linee[0] && linee[2]) || (linee[1] && linee[3])) {
            direzione=-135;
        } 
        else if ((linee[2] && linee[4]) || (linee[3] && linee[5])) {
            direzione=-45;
        } 
        else if ((linee[4] && linee[6]) || (linee[5] && linee[7])) {
            direzione=45;
        } 
        else if ((linee[6] && linee[0]) || (linee[7] && linee[1])) {
            direzione=135;
        } 
        else if ((linee[6] && linee[7]) || (linee[3] && linee[2])) {
            velocita(0, 0);
        }

        else if ((linee[0] && linee[1]) || (linee[5] && linee[4])) {
            velocita(0, 0);
        }
        
    }*/