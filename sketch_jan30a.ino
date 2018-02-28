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
  double m2[6] = {20,30,40,50,60,70};
  move(150, m2);
}

void loop() {
 /* servo[4].write(servo[4].read() + 40);
  servo[5].write(servo[5].read() - 40);
  delay(200);
  servo[4].write(servo[4].read() - 40);
  servo[5].write(servo[5].read() + 40);
  delay(200);
  servo[4].write(servo[4].read() - 40);
  servo[5].write(servo[5].read() + 40);
  delay(200);
  servo[4].write(servo[4].read() + 40);
  servo[5].write(servo[5].read() - 40);
  delay(200);*/
}

void stani() {
  stani_lijeva();
  stani_desna();
}

void stani_lijeva() {
  servo[1].write(90 - 24);

  servo[3].write(90 - 27);

  servo[5].write(90-40);
}


void stani_desna() {
  servo[0].write(90 - 32);

  servo[2].write(90 - 25);

  servo[4].write(90-40);
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

void move(double speed, double m[6]) {
  double a[6];
  
  a[0] = servo[0].read();
  a[1] = servo[1].read();
  a[2] = servo[2].read();
  a[3] = servo[3].read();
  a[4] = servo[4].read();
  a[5] = servo[5].read();

  
   for (int i = 0; i < speed; i++) {
    Serial.println(millis());
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

