# define EMIT_PIN    11    // Documentation says 11.
# define LS_LEFT_PIN 12   // Complete for DN1 pin
# define LS_MIDLEFT_PIN 18   // Complete for DN2 pin
# define LS_MIDDLE_PIN 20   // Complete for DN3 pin
# define LS_MIDRIGHT_PIN 21   // Complete for DN4 pin
# define LS_RIGHT_PIN 22   // Complete for DN5 pin
# define MAX_SAMPLES 5

int ls_pins[5] = {LS_LEFT_PIN,
                  LS_MIDLEFT_PIN,
                  LS_MIDDLE_PIN,
                  LS_MIDRIGHT_PIN,
                  LS_RIGHT_PIN };
float results[ MAX_SAMPLES ];

float sensor1[100];
float sensor2[100];
float sensor3[100];
float sensor4[100];
float sensor5[100];

int result_index;

// FILE *fpt = fopen("SensorData.csv", "w+");

void setup() {

  // Set some initial pin modes and states
  pinMode( EMIT_PIN, INPUT ); // Set EMIT as an input (off)
  pinMode( LS_LEFT_PIN, INPUT );     // Set line sensor pin to input
  pinMode( LS_MIDLEFT_PIN, INPUT );
  pinMode( LS_MIDDLE_PIN, INPUT );
  pinMode( LS_MIDRIGHT_PIN, INPUT );
  pinMode( LS_RIGHT_PIN, INPUT );
  float lineSensors(int number);

  Serial.begin(9600);
  delay(1500);
  Serial.println("***RESET***");

  for( int i = 0; i < 100; i++ ) {
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
  for(int i=1;i<6;i++){
    results[i] = lineSensors(i);
  }
  // unsigned long trialTime = millis();
  // float trialTime_f = (float)trialTime;
  // for(int j = 0; j < 1000000; j++){
  // fprintf(fpt, "%f,%f,%f,%f,%f,%f\n", trialTime_f, results[1], results[2], results[3], results[4], results[5]);

  sensor1[ result_index ] = lineSensors(1);
  sensor2[ result_index ] = lineSensors(1);
  sensor3[ result_index ] = lineSensors(1);
  sensor4[ result_index ] = lineSensors(1);
  sensor5[ result_index ] = lineSensors(1);

  result_index += 1;

  if(  result_index >= 100 ) {
      reportResults();
  }
  

}

void reportResults() {

      // experiment is over.
      while(1) {
            //stop motors
            //motors.stop(0,0);

            // print results.
            for( int i = 0; i < 100; i++ ) {

              Serial.print(sensor1[i]);
              Serial.print(",");
              Serial.print(sensor2[i]);
              Serial.print(",");
              Serial.print(sensor3[i]);
              Serial.print(",");
              Serial.print(sensor4[i]);
              Serial.print(",");
              Serial.println(sensor5[i]);

            }

            delay(1000);

      }


}
  
float lineSensors(int number){
  if( number < 0 ) {
        return (float)number  ;
        Serial.println("there is a mistake number = ");
        Serial.println(number);
    }
    if( number > 4 ) {
        return (float)number  ;
        Serial.println("there is a mistake number = ");
        Serial.println(number);
    }
    
  pinMode( EMIT_PIN, OUTPUT );
  digitalWrite( EMIT_PIN, HIGH );


  pinMode( ls_pins[ number ], OUTPUT );
  digitalWrite( ls_pins[ number ], HIGH );
  delayMicroseconds( 10 );
  pinMode( ls_pins[ number ], INPUT );

  unsigned long start_time = micros();

  while( digitalRead( ls_pins[ number ] ) == HIGH ) {
      // Do nothing here (waiting).
  }

  unsigned long end_time = micros();

  pinMode( EMIT_PIN, INPUT );

  unsigned long elapsed_time = end_time - start_time;
  
  return (float)elapsed_time;


} 