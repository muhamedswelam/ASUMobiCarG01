//sensor pins
const int IR0 = 2;
const int IR1 = 3;
const int IR2 = 4;
const int IR3 = 8;
const int IR4 = 6;
const int MOT0 = 5;
const int MOT1 = 9;
const int MOT2 = 10;
const int MOT3 = 11;
int vel = 130; // Speed Of Motors (0-255)
int state = '0'; // Initialise Motors
int distance_0;
int trigPin1 = 13;
int echoPin1 = 12;
int servposnum = 0;
int flag = 0;
long dist ;
long duration1 ;
int s=200;
int s2=200;
void forward()
{  
    analogWrite(MOT0, vel); 
    analogWrite(MOT1, 0); 
    analogWrite(MOT2, vel); 
    analogWrite(MOT3, 0);
}
void backward ()
{ 
  analogWrite(MOT0, 0); 
  analogWrite(MOT1, vel);
  analogWrite(MOT2, 0); 
  analogWrite(MOT3, vel);
}

void Right () {
  analogWrite(MOT0, vel); 
  analogWrite(MOT1, 0); 
  analogWrite(MOT2, 0); 
  analogWrite(MOT3, vel);
}
void Left () {
  analogWrite(MOT0, 0); 
  analogWrite(MOT1, vel);
  analogWrite(MOT2, vel);
  analogWrite(MOT3, 0);
}
void Stop () {
  analogWrite(MOT0, 0); 
  analogWrite(MOT1, 0); 
  analogWrite(MOT2, 0); 
  analogWrite(MOT3, 0);
}

 int obstacle() 
 {
  digitalWrite(trigPin1, LOW);

  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  pinMode(echoPin1, INPUT);

  duration1 = pulseIn(echoPin1, HIGH);
  dist  =(duration1 / 2) / 29.1;
   if ( dist < 30)
  { flag = 1;
  }
  else 
  {
    flag=0;
  }
}
void avoid()
{ backward ();
  delay(200);
 while (flag==1)
{
  obstacle();  
  Left();
  delay(50);
  }

}

void setup() { 
 
Serial.begin(9600); // Initialize serial communication at 9600 bits per second
   // Set pins as outputs
pinMode(MOT0, OUTPUT);
pinMode(MOT1, OUTPUT);
pinMode(MOT2, OUTPUT);
pinMode(MOT3, OUTPUT);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);

} 


void loop() {
  if (Serial.available() > 0)
  { 
    state  = Serial.read();
    if (state == 'W')
    {
    while (1)
    {
    obstacle ();
    state  = Serial.read(); // reading the data received from the bluetooth module
    if (state == 'F') {
      if (flag == 1)
        avoid();
      else
        forward();
      delay(10);
    }
    else if (state == 'B')
    {
      backward ();
      delay(10);
    }
   
    else if ( state == 'R') 
    {
      Right();
       delay(10);
    }
    else if (state == 'L')
    {
      Left ();
       delay(10);
    }
  
    else if (state == 'S')
    {
      Stop ();
      delay(10);
    }
     else if(state =='w')
    {
      break ;
    }
    }
  }
    
  if (state == 'U')
  {
    while (1)
    {
      int S0 = digitalRead(IR0);
      int S1 = digitalRead(IR1);
      int S2 = digitalRead(IR2);
      int S3 = digitalRead(IR3);
      int S4 = digitalRead(IR4);
      // print the sensor values:
  while (1){
      //Conditions to drive line folower appropriately
      if (S0==1 && S1==1 && S2==1 && S3==1 && S4==1) {
            //move
            analogWrite(MOT0,s);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,s);
            analogWrite(MOT3,LOW);
            state=2;
            break ;
             }
             else if (S2==1 && S0==0 && S1==1  && S3==1 && S4==0) {
            //if middle sensor at the center reads 1, go straight
            analogWrite(MOT0,s);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,s);
            analogWrite(MOT3,LOW);
            state=2;
            break ;      
      }
      
       else if (S2==1 && S0==0 && S1==0  && S3==0 && S4==0) {
            //if middle sensor at the center reads 1, go straight
            analogWrite(MOT0,s);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,s);
            analogWrite(MOT3,LOW);
            state=2;
            break ;      
      }
      
      else if (S2==1 && S0==0 && S1==1  && S3==0 && S4==0){
            //follower moving towads right, stop left motor
            //digitalWrite(MOT0,LOW);
            analogWrite(MOT0, LOW);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,s2);
            analogWrite(MOT3,LOW);
            state=3 ;
            break ;
      }
      else if (S2==0 && S0==1 && S1==1  && S3==0 && S4==0){
            //follower moving towads right, stop left motor
            //digitalWrite(MOT0,LOW);
            analogWrite(MOT0, LOW);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,s2);
            analogWrite(MOT3,LOW);
            state=3 ;
            break ;
      }
       else if (S2==1 && S0==1 && S1==1  && S3==0 && S4==0){
            //follower moving towads right, stop left motor
            //digitalWrite(MOT0,LOW);
            analogWrite(MOT0, LOW);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,s2);
            analogWrite(MOT3,LOW);
            state=3 ;
            break ;
      }
      else if (S1==1 && S0==0 && S2==0  && S3==0 && S4==0){
            //follower moving towads right, stop left motor
            //digitalWrite(MOT0,LOW);
            analogWrite(MOT0, LOW);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,s2);
            analogWrite(MOT3,LOW);
            state=3 ;
            break ;
      }
       else if (S0==1 && S1==0 &&  S2==0  && S3==0 && S4==0) {
            //follower moving towads right, stop left motor
            analogWrite(MOT0,LOW);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,s2);
            analogWrite(MOT3,LOW);
            state=3 ;
            break ;
      }
       else if (S3==1 && S0==0 && S1==0 &&  S2==0 && S4==1) {
            //follower moving towads left, stop right motor
            analogWrite(MOT0,s2);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,LOW);
            //digitalWrite(MOT3,LOW);
            analogWrite(MOT3, LOW);
            state=1 ;
            break ;
      }
        else if (S3==1 && S0==0 && S1==0 &&  S2==1 && S4==0) {
            //follower moving towads left, stop right motor
            analogWrite(MOT0,s2);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,LOW);
            //digitalWrite(MOT3,LOW);
            analogWrite(MOT3, LOW);
            state=1 ;
            break ;
      }
        else if (S3==1 && S0==0 && S1==0 &&  S2==1 && S4==1) {
            //follower moving towads left, stop right motor
            analogWrite(MOT0,s2);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,LOW);
            //digitalWrite(MOT3,LOW);
            analogWrite(MOT3, LOW);
            state=1 ;
            break ;
      }
       else if (S3==1 && S0==0 && S1==0 &&  S2==0 && S4==0) {
            //follower moving towads left, stop right motor
            analogWrite(MOT0,s2);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,LOW);
            //digitalWrite(MOT3,LOW);
            analogWrite(MOT3, LOW);
            state=1 ;
            break ;
      }
      else if (S4==1 && S3==0 && S0==0 && S1==0 &&  S2==0 ) {
            //follower moving towads left, stop right motor
            analogWrite(MOT0,s2);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,LOW);
            analogWrite(MOT3,LOW);
            state=1 ;
            break ;
      }
       else if (state ==1){
            //stop follower
            analogWrite(MOT0,s2);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,LOW);
            //digitalWrite(MOT3,LOW);
            analogWrite(MOT3, LOW);
            break ;
      }
      else if (state ==2){
            //stop follower
            analogWrite(MOT0,s);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,s);
            analogWrite(MOT3,LOW);
            break ;
      }
       else if (state ==3){
            //stop follower
            analogWrite(MOT0, LOW);
            analogWrite(MOT1,LOW);
            analogWrite(MOT2,s2);
            analogWrite(MOT3,LOW);
            break ;
      }
}
   if(state =='u')
    {
      break ;
    }
    }
  }
  }
  }
