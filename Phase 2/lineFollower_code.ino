//sensor pins
const int IR0 = 2;
const int IR1 = 3;
const int IR2 = 4;
const int IR3 = 8;
const int IR4 = 6;

//Motor control pins- 
//left motor- MOT0 & MOT1
//right motor- MOT2 & MOT3
const int MOT0 = 5;
const int MOT1 = 9;
const int MOT2 = 10;
const int MOT3 = 11;
int state =0;
int s=180;
int s2=200;
void setup() {
      pinMode(MOT0,OUTPUT);
      pinMode(MOT1,OUTPUT);
      pinMode(MOT2,OUTPUT);
      pinMode(MOT3,OUTPUT);
      // initialize the serial communications:
      //Serial.begin(115200);
}

void loop() {
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
}
