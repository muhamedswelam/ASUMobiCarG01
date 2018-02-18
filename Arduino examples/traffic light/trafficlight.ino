int led_yellow =10;
int led_green =11;
int led_red =12;

void setup() {
  
pinMode (led_yellow,OUTPUT );
pinMode (led_green,OUTPUT );
pinMode (led_red,OUTPUT );

}

void loop() {
  digitalWrite (led_yellow ,HIGH );
  digitalWrite (led_green, LOW );
  digitalWrite (led_red, LOW );
delay (3000);

digitalWrite (led_red, LOW );
digitalWrite (led_yellow ,LOW);
digitalWrite (led_green, HIGH);
delay (5000);

digitalWrite (led_yellow ,LOW);
digitalWrite (led_green, LOW );
digitalWrite (led_red, HIGH );
delay (3000);

}
