#include<Arduino.h>
#include "attacante.h"
#include "moto.h"
#include "palla.h"
void prova_angolopalla(){
   //passa_angolo()>=315 || passa_angolo()<45
   //passa_angolo()>=45 && passa_angolo()<135
   //passa_angolo()>=135 && passa_angolo()<225
//Serial.println(passa_angolo ());
    if(passa_angolo ()>=315 || passa_angolo ()<45){
        velocita(0, 80);
    }
    else if(passa_angolo ()>=45 && passa_angolo ()<135){//destra
        velocita(-90, 80);
    }
    else if(passa_angolo ()>=135 && passa_angolo ()<225){
        velocita(180, 80);            
    }
    else if(passa_angolo ()>=225 && passa_angolo ()<315){
        velocita(90, 80);
    }
}

void attaccante(){ 
    int velocità=80;
    int velocità_distanza=130;
    int distanza= 190;
    //Serial.println(passa_angolo ());
    if (palla_Vista() == false){
        velocita(0, 0);
    }else
    { 
        if (passa_distanza ()<=distanza){
            velocita(passa_angolo(), velocità_distanza);    
        }
        else{
            if(passa_angolo ()>342 || passa_angolo ()<=18){
                velocita(passa_angolo()*2, velocità); 
            }
            else if (passa_angolo()>18 && passa_angolo()<=90){
                velocita(passa_angolo()*2, velocità);
            }
            else if (passa_angolo()>90 && passa_angolo()<=162){
                velocita(-162, velocità);
            }
            else if (passa_angolo()>162 && passa_angolo()<=198){
                velocita(-90, velocità);    
            }
            else if (passa_angolo()>198 && passa_angolo()<=270){
                velocita(162, velocità);
            }
            else if (passa_angolo()>270 && passa_angolo()<=342){
                velocita(360-((360-passa_angolo())*2), velocità);
            }   
        }
    }
}






/*
if(palla_getAngolo()>=342 || palla_getAngolo()<18){//bbocca
    loopDriverCtrl(0, 80);
}else if(palla_getAngolo()>=18 && palla_getAngolo()<54){
    loopDriverCtrl(-162, 80);    
}else if(palla_getAngolo()>=54 && palla_getAngolo()<90){
    loopDriverCtrl(-180, 80);
}else if(palla_getAngolo()>=90 && palla_getAngolo()<126){
    loopDriverCtrl(90, 80); 
}else if(palla_getAngolo()>=126 && palla_getAngolo()<162){
    loopDriverCtrl(0, 80);
}else if(palla_getAngolo()>=162 && palla_getAngolo()<198){
    loopDriverCtrl(-90, 80);
}else if(palla_getAngolo()>=198 && palla_getAngolo()<234){
    loopDriverCtrl(180, 80);
}else if(palla_getAngolo()>=234 && palla_getAngolo()<270){
    loopDriverCtrl(90, 80);
}else if(palla_getAngolo()>=270 && palla_getAngolo()<306){
    loopDriverCtrl(0, 80);
}else if(palla_getAngolo()>=306 && palla_getAngolo()<342){
    loopDriverCtrl(-90, 80);   
}

 if(palla_getAngolo()>0 && palla_getAngolo()<45){
        loopDriverCtrl(0, 80);  
    }else if(palla_getAngolo()>=45 && palla_getAngolo()<=90){//[-90,-45]
        loopDriverCtrl(-135, 80);
    }else if(palla_getAngolo()>=90 && palla_getAngolo()<=135){//[-135,-90]
        loopDriverCtrl(-180, 80); 
    }else if(palla_getAngolo()>=135 && palla_getAngolo()<=180){ //[-180,-135]
        loopDriverCtrl(135, 80); 
    }else if(palla_getAngolo()>=180 && palla_getAngolo()<=225){//[0,90]
        loopDriverCtrl(0, 80);
    }else if(palla_getAngolo()>=225 && palla_getAngolo()<=270){//[45,90]
        loopDriverCtrl(135, 80);
    }else if(palla_getAngolo()>=270 && palla_getAngolo()<=315){//[90,135]
        loopDriverCtrl(180, 80);
    }else if(palla_getAngolo()>=315 && palla_getAngolo()<=360){//[135,180]
        loopDriverCtrl(0, 80);
    
    }
*/