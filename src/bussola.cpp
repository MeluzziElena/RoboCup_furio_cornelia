#include <Adafruit_BNO055.h>
#include "bussola.h"
//creazione oggetto IMU (bussola) da libreria Adafruit
Adafruit_BNO055 bno = Adafruit_BNO055 (55, 0x28); 
// inizializiamo un timer a 0
unsigned long bus_timer=0;
//angolo di ritorno dall'ultima lettura
int angolo=0;

void inibuss(){
    //iniziamo la comunicazione con la IMU se non funziona si blocca in un ciglo e no va
    while (! (bno.begin(OPERATION_MODE_IMUPLUS))){
        Serial.println("bussola non trovata");
    }
    //uso del cristallo esterno, più preciso per i tempi di clock
    bno.setExtCrystalUse(true); 
    //millis() riporta il tempo dall'accensione dei microcontrollore in millisecondi
    bus_timer=millis();
}
int leggibuss(){
    //per evitare clock stretching, aggiorniamo ogni 20ms
    if(millis() - bus_timer >=20){
        imu::Vector<3> euler =bno.getVector(Adafruit_BNO055::VECTOR_EULER);
        angolo=(int) euler.x();
        bus_timer=millis(); //aggiorna l'angolo all'ultima lettura
    }
    return angolo;
}
void testbuss() {
    Serial.println(leggibuss());
}
