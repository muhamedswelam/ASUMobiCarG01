byte data_pin =0;
byte latch_pin=7;
byte clock_pin=8;
byte bits[]={B0001,B0010,B0100,B1000,B0100,B0010,B0001};
void setup()
{
 pinMode(data_pin,OUTPUT);
 pinMode(latch_pin,OUTPUT);
 pinMode(clock_pin,OUTPUT);
}
void loop()
{
  for(int i=0;i<sizeof(bits);i++)
  {
    digitalWrite(latch_pin,LOW);
    shiftOut(data_pin,clock_pin,LSBFIRST,bits[i]);
    digitalWrite(latch_pin,HIGH);
    delay(400);
  }
}
