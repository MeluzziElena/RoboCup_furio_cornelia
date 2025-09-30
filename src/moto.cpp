#include <Arduino.h>
#include <QuickPID.h>

#include "moto.h"
#include "motori.h"
#include "bussola.h"
//Variabili di posizione, output, setpoint
//Sentpoint: "dove vogliamo arrivare"
//Orient: posizione attuale del robot
//Output: la veloceta angolare con cui far ruotare il robot per muoversi 
float input{0}, output{0}, setpoint{0};

//Primi tre argomenti: puntatori
//pMode::pOnError (l'azione proporzionale all'errore)
QuickPID ctrl_orient(&input, &output, &setpoint, KP, KI, KD, ctrl_orient.pMode::pOnError, ctrl_orient.dMode::dOnMeas, ctrl_orient.iAwMode::iAwCondition, ctrl_orient.Action::reverse);
void init_drivectrl(void){
    //tempo di campionamento con cui fare il controllo almeno ogni quanto si legge la bussola
    ctrl_orient.SetSampleTimeUs(20'000);
    ctrl_orient.SetOutputLimits(-255, 255);
    //attivazione del contorllo
    ctrl_orient.SetMode(ctrl_orient.Control::automatic);
}

float velocita_m0=0, velocita_m1=0, velocita_m2=0, velocita_m3=0, Vx=0,Vy=0;
void velocita(float angolo, float velocita){
    //angolo=direzione desiderata
    Vx=velocita*sin(radians(angolo));
    Vy=velocita*cos(radians(angolo));

    // orientamento (dalla bussola), portato nel range (-180, 180)
    int orient_int = leggibuss();
    orient_int = orient_int > 180 ? orient_int - 360 : orient_int;
    double orient_mot = 0; //radians(90 - orient_int);

    input= (float)orient_int;

    if (! (ctrl_orient.Compute())) return;
    //è vero solo se è passato il tempo di campionamento
        velocita_m0=cos(teta1+orient_mot)*Vy-sin(teta1+orient_mot)*Vx+output;
        velocita_m1=cos(teta2+orient_mot)*Vy-sin(teta2+orient_mot)*Vx+output;
        velocita_m2=cos(teta3+orient_mot)*Vy-sin(teta3+orient_mot)*Vx+output;
        velocita_m3=cos(teta4+orient_mot)*Vy-sin(teta4+orient_mot)*Vx+output;
        //Serial.println(output);
        //comando ai motori
        commot(0,velocita_m0);
        commot(1,velocita_m1);
        commot(2,velocita_m2);
        commot(3,velocita_m3);
    
    }
    
void test_moto(void){
  static int l=0;
  static unsigned long t = 0;
    if(millis()-t>=800){
      if(l>=4){
        l=0;
      }
      l++;
      t=millis();
    }
      if(l==0){
        velocita(0,80);
      }
      else if(l==1){
        velocita(90,80);
      }
      else if(l==2){
        velocita(180,80);

      }
      else if(l==3){
        velocita(-90,80);
      }
  }
   //spechietto di controllo 
    // Serial.print("velocita0: ");
    // Serial.println(velocita_m0);
    // Serial.print("velocita1: ");
    // Serial.println(velocita_m1);
    // Serial.print("velocita2: ");
    // Serial.println(velocita_m2);
    // Serial.print("velocita3: ");
    // Serial.println(velocita_m3); 