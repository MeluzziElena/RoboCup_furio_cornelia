#ifndef motori_h
#define motori_h
void inzpmot (); /*inizializazione pin dei motori quindi se son input e output*/
void commot (int qua, int pwm); /*controllo di velocità e direzione dei motori
qua = quale motore
pwm = velocità direzione */
void fermmot(); /*ferma il motore*/
void testmot (); /*test dei motori*/
#endif

