// this #ifndef stops this file
// from being included mored than
// once by the compiler.
#ifndef _MOTORS_H
#define _MOTORS_H

#define L_PWM_PIN 10
#define L_DIR_PIN 16
#define R_PWM_PIN 9
#define R_DIR_PIN 15

#define FWD LOW
#define REV HIGH



// Class to operate the motor(s).
class Motors_c {
public:

  // Constructor, must exist.
  Motors_c() {
  }
  float lspeed, rspeed;
  void init();
  // int forward(float lspeed, float rspeed);
  int setMotorPower(float lspeed, float rspeed);
};


// Use this function to
// initialise the pins and
// state of your motor(s).
void Motors_c::init() {
  pinMode(L_PWM_PIN, OUTPUT);
  pinMode(L_DIR_PIN, OUTPUT);
  pinMode(R_PWM_PIN, OUTPUT);
  pinMode(R_DIR_PIN, OUTPUT);

  // Set initial direction (HIGH/LOW)
  // for the direction pins.
  // ...
  digitalWrite(L_DIR_PIN, FWD);
  digitalWrite(R_DIR_PIN, FWD);

  // Set initial power values for the PWM
  // Pins.
  // ...
  analogWrite(L_PWM_PIN, 0);
  analogWrite(R_PWM_PIN, 0);

  // Start serial, send debug text.
  Serial.begin(9600);
  delay(1);
  Serial.println("***RESET***");
}

// Motors_c::forward(float lspeed, float rspeed){
//   digitalWrite(L_DIR_PIN, FWD);
//   digitalWrite(R_DIR_PIN, FWD);
//   if( lspeed < 0 ) lspeed = lspeed * -1.0;
//   analogWrite( L_PWM_PIN, lspeed );
//   if( rspeed < 0 ) rspeed = rspeed * -1.0;
//   analogWrite( R_PWM_PIN, rspeed );
// }


//     L    R   Direction L R
//     -    -             R R
//     -    +             R F
//     +    -             F R
//     +    +             F F
Motors_c::setMotorPower(float lspeed, float rspeed) {

  // Set the direction pin LEFT
  if (lspeed < 0) {  // -
    digitalWrite(L_DIR_PIN, REV);

  } else {  // +
    digitalWrite(L_DIR_PIN, FWD);
  }

  // Set the direction pin RIGHT
  if (rspeed < 0) {  // -
    digitalWrite(R_DIR_PIN, REV);

  } else {  // +
    digitalWrite(R_DIR_PIN, FWD);
  }

  // error?
  // what to do if lspeed < -255 or lspeed > 255
  // and for right.
  // analogWrite( pin, [ 0 : 255 ] )

  // Set the speed LEFT
  if( lspeed < 0 ) lspeed = lspeed * -1.0;
  analogWrite( L_PWM_PIN, lspeed );


  // Set the speed RIGHT
  if( rspeed < 0 ) rspeed = rspeed * -1.0;
  analogWrite( R_PWM_PIN, rspeed );

}

#endif
