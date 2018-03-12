#include <Servo.h>

Servo servo[12];

int kuk_desno = 9;
int kuk_lijevo = 10;

int koljeno_desno = 5;
int koljeno_lijevo = 4;

int zglob_desno = 6;
int zglob_lijevo = 11;

void setup() {
  Serial.begin(9600);
  
  servo[0].attach(kuk_lijevo, 0, 180);
  servo[1].attach(kuk_desno, 0, 180);

  servo[2].attach(koljeno_lijevo, 0, 180);
  servo[3].attach(koljeno_desno, 0, 180);

  servo[4].attach(zglob_lijevo, 0, 180);
  servo[5].attach(zglob_desno, 0, 180);

  stani();

  delay(1000);

  //move(1000, -45, -45, -45, -45, 0, 0);
}

void loop() {
 
 move(1000, 0, 0, 0, 0, -10, -10);
 move(1000, 0, 0, 0, 0, -10, -10);
 move(2000, 0, -90, 0, -90, 0, 0);
 move(2000, 0, 0, 0, 0, 20, 20);
delay(1000000);
 move(2000, -90, -90, -90, -90, 0, -30);
}

void stani() {
  stani_lijeva();
  stani_desna();
}

void stani_lijeva() {
  servo[1].write(90 - 24);

  servo[3].write(90 - 27);

  servo[5].write(90- 34);
}


void stani_desna() {
  servo[0].write(90 - 32);

  servo[2].write(90 - 25);

  servo[4].write(90 - 36);
}


void iskorak_lijevo() {
  servo[1].write(65);
  servo[3].write(65);
  delay(100);
  servo[1].write(111);
  servo[3].write(111);
  
}

void iskorak_desno() {
  servo[0].write(65);
  servo[2].write(65);

  delay(100);
  
  servo[0].write(111);
  servo[2].write(111);
  
}


void iskorak_lijevo2() {
  servo[1].write(-65);
  servo[3].write(-65);
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

void move(double speed, int m1, int m2, int m3, int m4, int m5, int m6) {
  double a[6], m[6];

  m[0] = m1;
  m[1] = m2;
  m[2] = m3;
  m[3] = m4;
  m[4] = m5;
  m[5] = m6;
  
  for (int i = 0; i < 6; i++) {
    a[i] = servo[i].read();
  }

  
   for (int i = 0; i < speed; i++) {
    //Serial.println(millis());
    for (int j = 0; j < 6; j++) {
      a[j] += m[j] / speed;

      //Serial.println(j + ' ' + a[j]);

      if (abs(a[j] - servo[j].read()) > 1) {
        //Serial.println("Pomjerio ");
        servo[j].write((int)a[j]);
      }
    }
    //delay(1);
   }
}

