#include<IRremote.h>
int red=9;
int blue=10;
int green=12;
int RECV_PIN=11;
  
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
   
    if(results.value==0xFD08F7)
    {
      digitalWrite(red,HIGH);
      digitalWrite(green,LOW);
      digitalWrite(blue,LOW);
    }
       else if(results.value==0xFD48B7)
       {
      digitalWrite(red,LOW);
      digitalWrite(green,LOW);
      digitalWrite(blue,HIGH);
    }
       else if(results.value==0xFD8877)
       {
      digitalWrite(red,LOW);
      digitalWrite(green,HIGH);
      digitalWrite(blue,LOW);
    }
    else if(results.value==0xFD28D7)
       {
      digitalWrite(red,HIGH);
      digitalWrite(green,HIGH);
      digitalWrite(blue,LOW);
    }
    else if(results.value==0xFDA857)
       {
      digitalWrite(red,HIGH);
      digitalWrite(green,LOW);
      digitalWrite(blue,HIGH);
    }
    else if(results.value==0xFD6897)
       {
      digitalWrite(red,LOW);
      digitalWrite(green,HIGH);
      digitalWrite(blue,HIGH);
    }
   else if(results.value==0xFD30CF)
       {
      digitalWrite(red,HIGH);
      digitalWrite(green,HIGH);
      digitalWrite(blue,HIGH);
    }
  }
 
  delay(100);
}