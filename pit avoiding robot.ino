int ls;// LEFT SENSOR
int cs;// CENTER SENSOR
int rs;// RIGHT SENSOR
int lmt1=5;// LEFT MOTOR 1
int lmt2=3;// LEFT MOTOR 2
int rmt1=6;// RIGHT MOTOR 1
int rmt2=11;// RIGHT MOTOR 2

void setup() {
  // put your setup code here, to run once:
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(lmt1,OUTPUT);
pinMode(lmt2,OUTPUT);
pinMode(rmt1,OUTPUT);
pinMode(rmt2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
rs=digitalRead(9);
  cs=digitalRead(8);
  ls=digitalRead(7);
  if (ls==LOW&&cs==LOW&&rs==LOW)
  {
   forward();
  }
  else if (ls==LOW&&cs==HIGH&&rs==LOW)
  {
  backward();
  delay(200);
  left();
  delay(200);
    
  }
   else if (ls==HIGH&&cs==LOW&&rs==LOW)
   {
    right();
   }
   else if (ls==LOW&&cs==LOW&&rs==HIGH)
   {
    left();
   }
   else if(ls==HIGH&&cs==LOW&&rs==HIGH)
   {
    backward();
    delay(200);
    left();
    delay(200);
   }
   else if (ls==HIGH&&cs==HIGH&&rs==LOW)
   {
    backward();
    delay(200);
    right();
    delay(200);
   }
   else if (ls==LOW&& cs==HIGH&& rs==HIGH)
   {
    backward();
    delay(200);
    left();
    delay(200);
   }
    else if(ls==HIGH&&cs==HIGH&&rs==HIGH)
    {
      backward();
      delay(200);
      left();
      delay(200);
    }
}
void forward(){
  analogWrite(lmt1,150);
  analogWrite(lmt2,0);
  analogWrite(rmt1,150);
  analogWrite(rmt2,0);
  
}
void backward(){
  analogWrite(lmt1,0);
  analogWrite(lmt2,150);
  analogWrite(rmt1,0);
  analogWrite(rmt2,150);
}
void left (){
analogWrite(lmt1,0);
analogWrite(lmt2,150);
analogWrite(rmt1,150);
analogWrite(rmt2,0);
}
void right(){
  analogWrite(lmt1,150);
  analogWrite(lmt2,0);
  analogWrite(rmt1,0);
  analogWrite(rmt2,150);
}
void stp(){
 analogWrite(lmt1,0);
  analogWrite(lmt2,0);
  analogWrite(rmt1,0);
  analogWrite(rmt2,0); 
}
void stpright(){
analogWrite(lmt1,150);
  analogWrite(lmt2,0);
  analogWrite(rmt1,0);
  analogWrite(rmt2,0); 
}
void stpleft(){
analogWrite(lmt1,0);
  analogWrite(lmt2,0);
  analogWrite(rmt1,150);
  analogWrite(rmt2,0);   
}