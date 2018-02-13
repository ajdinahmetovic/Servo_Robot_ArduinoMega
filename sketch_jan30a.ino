#include <Servo.h>

Servo servo[12];

int kuk_desno = 9;
int kuk_lijevo = 10;

int koljeno_desno = 5;
int koljeno_lijevo = 4;

int zglob_desno = 6;
int zglob_lijevo = 11;

void setup() {
  servo[kuk_lijevo].attach(kuk_lijevo, 0, 180);
  servo[kuk_desno].attach(kuk_desno, 0, 180);

  servo[koljeno_lijevo].attach(koljeno_lijevo, 0, 180);
  servo[koljeno_desno].attach(koljeno_desno, 0, 180);

  servo[zglob_lijevo].attach(zglob_lijevo, 0, 180);
  servo[zglob_desno].attach(zglob_desno, 0, 180);

  stani();
}

void loop() {


  delay(1000);
 
  servo[kuk_lijevo].write(65);
  servo[koljeno_lijevo].write(65);
  delay(150);
  servo[kuk_desno].write(65);
  servo[koljeno_desno].write(65);


  delay(50);

 
  servo[kuk_lijevo].write(111);
  servo[koljeno_lijevo].write(111);
  delay(150);
  servo[kuk_desno].write(111);
  servo[koljeno_desno].write(111);

 delay(1000);

 servo[kuk_lijevo].write(-65);
  servo[koljeno_lijevo].write(-65);
  delay(150);
  servo[kuk_desno].write(-65);
  servo[koljeno_desno].write(-65);


  delay(50);
 
  servo[kuk_lijevo].write(-111);
  servo[koljeno_lijevo].write(-111);
  delay(150);
  servo[kuk_desno].write(-111);
  servo[koljeno_desno].write(-111);
  
// stani_lijeva();
// delay(200);
// stani_desna();
  delay(0);
}

void stani() {
  stani_lijeva();
  stani_desna();
}

void stani_lijeva() {
  servo[kuk_lijevo].write(90 - 24);

  servo[koljeno_lijevo].write(90 - 27);

  servo[zglob_lijevo].write(90-40);
}


void stani_desna() {
  servo[kuk_desno].write(90 - 32);

  servo[koljeno_desno].write(90 - 25);

  servo[zglob_desno].write(90-40);
}


void iskorak_lijevo() {
  servo[kuk_lijevo].write(65);
  servo[koljeno_lijevo].write(65);
  delay(100);
  servo[kuk_lijevo].write(111);
  servo[koljeno_lijevo].write(111);
  
}

void iskorak_desno() {
  servo[kuk_desno].write(65);
  servo[koljeno_desno].write(65);

  delay(100);
  
  servo[kuk_desno].write(111);
  servo[koljeno_desno].write(111);
  
}


void iskorak_lijevo2() {
  servo[kuk_lijevo].write(-65);
  servo[koljeno_lijevo].write(-65);
  delay(100);
  servo[kuk_lijevo].write(-111);
  servo[koljeno_lijevo].write(-111);
  
}

void iskorak_desno2() {
  servo[kuk_desno].write(-65);
  servo[koljeno_desno].write(-65);

  delay(100);
  
  servo[kuk_desno].write(-111);
  servo[koljeno_desno].write(-111);
  
}

