/*This code is for our Graduation Project 2020
of Umm Al_Qura University,
Electrical Engineering Department
created by Abdulhameed Nahhas helping whith my team
Mohammed, Abdullah, Khalid and Raed
I hope you like it...^_^
 .
 .
 .
 .*/
/* No need for library*/
int MW = 3 ;  // Microwave sensor Input Pin
int P  = 4 ;  // PIR sensor Inpur Pin
int S  = A0;  // Sound sensor Input Pin
int R  = 7 ;  // Relay Output Pin 
int L  = 8 ;  // LED Output Pin 

int MWstate;  // Variable where reading of MW stored in
int Pstate ;  // Variable where reading of P  stored in
int Sstate ;  // Variable where reading of S  stored in
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // To make these Pin integers as an inputs or outputs:
  pinMode(MW, INPUT ); // Receive signal from Microwave sensor
  pinMode(P , INPUT ); // Receive signal from PIR sensor
  pinMode(S , INPUT ); // Receive signal from Sound sensor
  pinMode(R , OUTPUT); // transmit Signal to relay
  pinMode(L , OUTPUT); // transmit Signal to LED
}
void loop() {
  MWstate= digitalRead(MW); //Save the value of MW inside MWstate 
  Pstate = digitalRead(P) ; //Save the value of P  inside Pstate
  Sstate = analogRead(S)  ; //Save the value of S  inside Sstate

  if (MWstate==HIGH){ //If recived high value from Microwave do next
    for(int i = 0; i < 40; i++){ //"for" loop to adjust time duration
      digitalWrite(L,HIGH); //Light Up the LED
      digitalWrite(R,HIGH); //Connected the Relay
//----------------------------------------------------
      // **To see all Sensors's values in Serial Monitor
      MWstate= digitalRead(MW);
      Pstate = digitalRead(P) ;
      Sstate = analogRead(S)  ;
      Serial.print  ("senseMW="+String(MWstate));
      Serial.print  (",,P="    +String(Pstate)) ;
      Serial.println(",,S="    +String(Sstate)) ;
      delay(300); //Refresh Serial Monitor
//----------------------------------------------------
    } 
  }
  if (Pstate==HIGH){ //If recived high value from PIR do next
    for(int i = 0; i < 40; i++){
      digitalWrite(L,HIGH);
      digitalWrite(R,HIGH);
      MWstate= digitalRead(MW);
      Pstate = digitalRead(P) ;
      Sstate = analogRead(S)  ;
      Serial.print  ("MW="      +String(MWstate));
      Serial.print  (",,senseP="+String(Pstate)) ;
      Serial.println(",,S="     +String(Sstate)) ;
      delay(300);
    } 
  }
  //If recived high value of Sound do next
  if (Sstate>=100){ // the 100 is depend on your environament
    for(int i = 0; i < 40; i++){
      digitalWrite(L,HIGH);
      digitalWrite(R,HIGH);
      MWstate= digitalRead(MW);
      Pstate = digitalRead(P) ;
      Sstate = analogRead(S)  ;
      Serial.print  ("MW="      +String(MWstate));
      Serial.print  (",,P="     +String(Pstate)) ;
      Serial.println(",,senseS="+String(Sstate)) ;
      delay(300);
    }  
  }
  //If recived nothing and less sound do next
  if ((MWstate==LOW)&&(Pstate==LOW)&&(Sstate<=100)){
    digitalWrite(L,LOW); 
    digitalWrite(R,LOW);  
    delay(3000);
  }
}
