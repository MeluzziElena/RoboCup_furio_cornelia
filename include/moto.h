#ifndef moto_h
#define moto_h
#include <Arduino.h>

//angoli 
#define teta1 radians(45)
#define teta2 radians(-45)
#define teta3 radians(-135)
#define teta4 radians(135)

#define KP 2.0   
#define KI 0.0
#define KD 0.1

void init_drivectrl(void);
void drive(int, int); 
void test_moto(void);
void velocita(float, float); /*controlla la velocità*/
#endif