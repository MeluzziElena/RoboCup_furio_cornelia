#include <Arduino.h>
#include <stdbool.h>

#include "palla.h"
#include "pin.h"

float angolo_palla;
float distanza_palla;
bool palla = false;

void int_palla() {
    SERIAL_PALLA.begin(115200);
}

void leggi_palla () {
    while (SERIAL_PALLA.available()) {
        uint8_t messaggio = SERIAL_PALLA.read();
        char LSB= messaggio & 1;
        if (LSB==1) {
            distanza_palla = messaggio;
            if(distanza_palla>1)
                palla=true;
            else
                palla=false;
        }
        else {
            angolo_palla = messaggio*2;
        }
    }
}

float passa_angolo (){
    return angolo_palla;
}

float passa_distanza (){
    return distanza_palla;
}
bool palla_Vista(){
    return palla;
}
bool palla_nonvista(){
    palla=false;
    return palla;
}

void test_palla() {
    Serial.println();
    leggi_palla();
    if(palla){
        Serial.println(String("anglo della palla: ") + angolo_palla);
        Serial.println(String("distanza della palla: ") + distanza_palla);
    }else Serial.println("non si vede la palla");
    delay(100);
}
