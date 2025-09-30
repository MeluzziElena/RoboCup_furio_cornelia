#include <Arduino.h>
#include "motori.h"
#include "bussola.h"
#include "moto.h"
#include "palla.h"
#include "attacante.h"
#include "linee.h"


void setup() {
  inzpmot ();
  inibuss();
  init_drivectrl();
  int_palla ();
  inizializa_linee();
}

void loop() {
 /*/ lettura_linee();
  if (movimento()==false){
    leggi_palla ();                                                 
    attaccante();
  }*/
 leggi_palla();
 //testbuss();
 //test_moto();
}