# define EMIT_PIN    11    // Documentation says 11.
# define LS_LEFT_PIN 12   // Complete for DN1 pin
# define LS_MIDLEFT_PIN 18   // Complete for DN2 pin
# define LS_MIDDLE_PIN 20   // Complete for DN3 pin
# define LS_MIDRIGHT_PIN 21   // Complete for DN4 pin
# define LS_RIGHT_PIN 22   // Complete for DN5 pin


int ls_pins[5] = {LS_LEFT_PIN,
                  LS_MIDLEFT_PIN,
                  LS_MIDDLE_PIN,
                  LS_MIDRIGHT_PIN,
                  LS_RIGHT_PIN };


void setup() {

  // Set some initial pin modes and states
  pinMode( EMIT_PIN, INPUT ); // Set EMIT as an input (off)
  pinMode( LS_LEFT_PIN, INPUT );     // Set line sensor pin to input
  pinMode( LS_MIDLEFT_PIN, INPUT );
  pinMode( LS_MIDDLE_PIN, INPUT );
  pinMode( LS_MIDRIGHT_PIN, INPUT );
  pinMode( LS_RIGHT_PIN, INPUT );


  Serial.begin(9600);
  delay(1500);
  Serial.println("***RESET***");

}


void loop() {
  for(int i=1;i<6;i++){
    float result = lineSensors(i);
    Serial.println( result );
  }


}
  
void lineSensors(int number){
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