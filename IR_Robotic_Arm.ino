//Code Written by RAJDEEP BARUAH

#include<Servo.h>
#include<IRremote.h>

Servo servo1,servo2,servo3,servo4;
int REC_PIN = 8;
int signal,pos1=0,pos2=0,pos3=0,pos4=140;
IRrecv irrecv(REC_PIN);
decode_results results;

void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
  irrecv.enableIRIn();
  Serial.begin(9600);

}
void loop() {
  if(irrecv.decode(&results))
  {
    signal=(results.value);
    Serial.println(signal);
    
    if(signal==14089||signal==23572||signal==8588||signal==1)
    {
      servo1.write(pos1);
      pos1+=20;
    }
    else if(signal==-22567||signal==31240||signal==23156||signal==2)
    { 
      servo1.write(pos1);
      pos1-=20;
    }

      if(signal==4||signal==22254||signal==-24713||signal==19854)
    {
      servo2.write(pos2);
      pos2+=20;
    }
    else if(signal==5||signal==7172||signal==9926||signal==-21610)
    { 
      servo2.write(pos2);
      pos2-=20;
    }
      if(signal==3020||signal==-7476||signal==7)
    {
      servo3.write(pos3);
      pos3+=20;
    }
    else if(signal==-3458||signal==3020||signal==8)
    { 
      servo3.write(pos3);
      pos3-=20;
    }
    else if(signal==-23776||signal==-32671||signal==3)
    {
      servo4.write(80);
    }
    else if(signal==1813||signal==6)
    {
      servo4.write(140);
    }
    else if(signal==21472||signal==132 ||signal==29985)
    {
      servo1.write(0);
      servo2.write(0);
      servo3.write(0);
      servo4.write(140);
    }
    else if(signal==-4866)
    {   
        servo3.write(30);
        delay(1000);
        servo2.write(30);
        delay(1000);
        servo1.write(15);
        delay(100);
        servo2.write(80);
        delay(1000);
        servo4.write(80);
        delay(500);
    }
    else if(signal==-15846)
    {
      servo3.write(30);
      delay(1000);
      servo2.write(20);
      delay(1000);
      servo1.write(150);
      delay(1000);
      servo2.write(80);
      delay(1000);
      servo4.write(60);
      delay(500);
    }

    irrecv.resume();
  }
}
