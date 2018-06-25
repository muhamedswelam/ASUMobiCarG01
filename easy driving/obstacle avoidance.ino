
int motorA1 = 5; // Pin  2 of L293
int motorA2 = 9; // Pin  7 of L293
int motorB1 = 10; // Pin 10 of L293
int motorB2 = 11; // Pin 14 of L293
int vel = 150; // Speed Of Motors (0-255)
int state = '0'; // Initialise Motors
int distance_0;
int trigPin1 = 13;
int echoPin1 = 12;
int servposnum = 0;
int flag = 0;
long dist ;
long duration1 ;
void forward()
{  
    analogWrite(motorA1, vel); 
    analogWrite(motorA2, 0); 
    analogWrite(motorB1, vel); 
    analogWrite(motorB2, 0);
}
void backward ()
{ 
  analogWrite(motorA1, 0); 
  analogWrite(motorA2, vel);
  analogWrite(motorB1, 0); 
  analogWrite(motorB2, vel);
}

void Right () {
  analogWrite(motorA1, vel); 
  analogWrite(motorA2, 0); 
  analogWrite(motorB1, 0); 
  analogWrite(motorB2, vel);
}
void Left () {
  analogWrite(motorA1, 0); 
  analogWrite(motorA2, vel);
  analogWrite(motorB1, vel);
  analogWrite(motorB2, 0);
}
void Stop () {
  analogWrite(motorA1, 0); 
  analogWrite(motorA2, 0); 
  analogWrite(motorB1, 0); 
  analogWrite(motorB2, 0);
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
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);

} 


void loop() {
  if (Serial.available() > 0)
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

    Serial.println(state);
  }
}
