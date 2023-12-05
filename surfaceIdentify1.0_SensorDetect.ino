#include "motors.h"

#define EMIT_PIN 11         // Documentation says 11.
#define LS_LEFT_PIN 12      // Complete for DN1 pin
#define LS_MIDLEFT_PIN 18   // Complete for DN2 pin
#define LS_MIDDLE_PIN 20    // Complete for DN3 pin
#define LS_MIDRIGHT_PIN 21  // Complete for DN4 pin
#define LS_RIGHT_PIN 22     // Complete for DN5 pin
#define MAX_SAMPLES 5
Motors_c motors;

int ls_pins[5] = { LS_LEFT_PIN,
                   LS_MIDLEFT_PIN,
                   LS_MIDDLE_PIN,
                   LS_MIDRIGHT_PIN,
                   LS_RIGHT_PIN };
float results[MAX_SAMPLES];

float sensor1[100];
float sensor2[100];
float sensor3[100];
float sensor4[100];
float sensor5[100];

int result_index;

// FILE *fpt = fopen("SensorData.csv", "w+");

void setup() {
  motors.init();
  // Set some initial pin modes and states
  pinMode(EMIT_PIN, INPUT);     // Set EMIT as an input (off)
  pinMode(LS_LEFT_PIN, INPUT);  // Set line sensor pin to input
  pinMode(LS_MIDLEFT_PIN, INPUT);
  pinMode(LS_MIDDLE_PIN, INPUT);
  pinMode(LS_MIDRIGHT_PIN, INPUT);
  pinMode(LS_RIGHT_PIN, INPUT);
  float lineSensors(int number);

  Serial.begin(9600);
  delay(1000);
  Serial.println("***RESET***");

  for (int i = 0; i < 100; i++) {
    sensor1[i] = 0;
    sensor2[i] = 0;
    sensor3[i] = 0;
    sensor4[i] = 0;
    sensor5[i] = 0;
  }
  result_index = 0;

  // fprintf(fpt,"time, 1, 2, 3, 4, 5\n");
}


void loop() {
  
  float reading_1 = lineSensors(0);
  reading_1 = (reading_1 - 732.87) / 150.06;
  Serial.print(reading_1);
  float reading_2 = lineSensors(0);
  reading_2 = (reading_2 - 340.39) / 214.43;
  Serial.print(",");
  Serial.print(reading_2);
  float reading_3 = lineSensors(0);
  reading_3 = (reading_3 - 264.92) / 210.17;
  Serial.print(",");
  Serial.print(reading_3);
  float reading_4 = lineSensors(0);
  reading_4 = (reading_4 - 318.28) / 209.47;
  Serial.print(",");
  Serial.print(reading_4);
  float reading_5 = lineSensors(0);
  reading_5 = (reading_5 - 585.57) / 206.37;
  Serial.print(",");
  Serial.println(reading_5);

  // Possible improvements
  // - a combination of all 5 sensors? mean? mode？ min? max?
  // - a stastical measure of which is more reliable? (inverse variance weighting on wikipedia)
  // - instead of an instant decision, it could collect x samples then decide.
  // Probably, just pick one of the above that you predict will be most effective.
  // Try to explain how and why it might be better
  // 

  if (reading_3 >= 4.45 && reading_3 <= 4.55) { // && reading_3 <= 4.55){
    motors.setMotorPower(0,0);
    delay(1000);
  }else if (reading_3 >= 6.45 && reading_3 <= 6.55){
    motors.setMotorPower(0,0);
    delay(1000);
  }else if (reading_3 >= 8.45 && reading_3 <= 8.55){
    motors.setMotorPower(0,0);
    delay(1000);
  }else if (reading_3 >= 10.45 && reading_3 <= 10.55){
    motors.setMotorPower(0,0);
    delay(1000);
  }else{
    motors.setMotorPower(18, 18);
  }

  return;

  // while (1) {
    for (int i = 0; i < 5; i++) {
      results[i] = lineSensors(i);
      // Serial.print(results[i]);
      // Serial.print(",");
    }
    // Serial.println();
    // delay(10);
  // }
  // unsigned long trialTime = millis();
  // float trialTime_f = (float)trialTime;
  // for(int j = 0; j < 1000000; j++){
  // fprintf(fpt, "%f,%f,%f,%f,%f,%f\n", trialTime_f, results[1], results[2], results[3], results[4], results[5]);

  sensor1[result_index] = lineSensors(0);
  sensor2[result_index] = lineSensors(1);
  sensor3[result_index] = lineSensors(2);
  sensor4[result_index] = lineSensors(3);
  sensor5[result_index] = lineSensors(4);

  result_index += 1;
  // Serial.println(result_index);
  if (result_index >= 100) {
  reportResults();
  }
}

void reportResults() {
  int j = 1;
  // experiment is over.
  // while (1) {
    //stop motors
    //motors.stop(0,0);

    // print results.
  for (j = 1; j < 2; j++) {
    for (int i = 0; i < 50; i++) {
      Serial.print(j);
      Serial.print(",");
      Serial.print(i);
      Serial.print(",");
      Serial.print("1");
      Serial.print(",");
      Serial.println(sensor1[i]);

      Serial.print(j);
      Serial.print(",");
      Serial.print(i);
      Serial.print(",");
      Serial.print("2");
      Serial.print(",");
      Serial.println(sensor2[i]);

      Serial.print(j);
      Serial.print(",");
      Serial.print(i);
      Serial.print(",");
      Serial.print("3");
      Serial.print(",");
      Serial.println(sensor3[i]);

      Serial.print(j);
      Serial.print(",");
      Serial.print(i);
      Serial.print(",");
      Serial.print("4");
      Serial.print(",");
      Serial.println(sensor4[i]);

      Serial.print(j);
      Serial.print(",");
      Serial.print(i);
      Serial.print(",");
      Serial.print("5");
      Serial.print(",");
      Serial.println(sensor5[i]);
    }

    delay(3000);
    
  }
  delay(4000);
  result_index = 0;
  // }
}

float lineSensors(int number) {
  if (number < 0) {
    return (float)number;
    Serial.println("there is a mistake number = ");
    Serial.println(number);
  }
  if (number > 4) {
    return (float)number;
    Serial.println("there is a mistake number = ");
    Serial.println(number);
  }

  pinMode(EMIT_PIN, OUTPUT);
  digitalWrite(EMIT_PIN, HIGH);


  pinMode(ls_pins[number], OUTPUT);
  digitalWrite(ls_pins[number], HIGH);
  delayMicroseconds(10);
  pinMode(ls_pins[number], INPUT);

  unsigned long start_time = micros();

  while (digitalRead(ls_pins[number]) == HIGH) {
    // Do nothing here (waiting).
  }

  unsigned long end_time = micros();

  pinMode(EMIT_PIN, INPUT);

  unsigned long elapsed_time = end_time - start_time;

  return (float)elapsed_time;
}