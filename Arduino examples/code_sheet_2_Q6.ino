const int D1=13;
const int D2=12;
const int D3=11;
const int LDR1=A0;
const int LDR2=A1;
const int LDR3=A2;
int tourch1,tourch2,tourch3;

void setup(){
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
}

void loop(){
  tourch1 = analogRead(LDR1);
  tourch2 = analogRead(LDR2);
  tourch3 = analogRead(LDR3);

  if(tourch1>tourch2 && tourch1>tourch3){
    digitalWrite(D1,HIGH);
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
  }
   else if(tourch2>tourch1 && tourch2>tourch3){
    digitalWrite(D1,LOW);
    digitalWrite(D2,HIGH);
    digitalWrite(D3,LOW);
  }
   else if(tourch3>tourch2 && tourch3>tourch1){
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D3,HIGH);
  }
}

