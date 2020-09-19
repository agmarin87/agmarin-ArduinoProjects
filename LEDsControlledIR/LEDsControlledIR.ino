// Several LEDs controlled remotely by an IR remote controlled   
// CREATED BY AGM


#include <IRremote.h>

int RECV_PIN = 2;   //Infrared sensor pin
IRrecv irrecv(RECV_PIN);
decode_results results;
int pinLed1 = 12;
int pinLed2 = 11;
int pinLed3 = 10;
int pinLed4 = 6;
int pinLed5 = 5;
int pinLed6 = 4;


void setup()
{
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);
  pinMode(pinLed6, OUTPUT);
  
  
  // The program will start with all the LEDs off
        digitalWrite(pinLed1, LOW);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, LOW);
        digitalWrite(pinLed4, LOW);
        digitalWrite(pinLed5, LOW);
        digitalWrite(pinLed6, LOW);
        
  
  irrecv.enableIRIn(); // Start the receiver
  
}

void loop() {
  if (irrecv.decode(&results)) {
    switch (results.value)  {
      case 0xFF6897: //botón 0
        digitalWrite(pinLed1, LOW);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, LOW);
        digitalWrite(pinLed4, LOW);
        digitalWrite(pinLed5, LOW);
        digitalWrite(pinLed6, LOW);
        
        break;
      case 0xFF30CF: //botón 1
        digitalWrite(pinLed1, HIGH);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, LOW);
        digitalWrite(pinLed4, LOW);
        digitalWrite(pinLed5, LOW);
        digitalWrite(pinLed6, LOW);
        
        break;
      case 0xFF18E7: //botón 2
        digitalWrite(pinLed1, LOW);
        digitalWrite(pinLed2, HIGH);
        digitalWrite(pinLed3, HIGH);
        digitalWrite(pinLed4, LOW);
        digitalWrite(pinLed5, LOW);
        digitalWrite(pinLed6, LOW);
        
        break;
      case 0xFF7A85: //botón 3
        digitalWrite(pinLed1, LOW);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, LOW);
        digitalWrite(pinLed4, HIGH);
        digitalWrite(pinLed5, LOW);
        digitalWrite(pinLed6, LOW);
        
        break;
      case 0xFF10EF:  //botón 4
        digitalWrite(pinLed1, LOW);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, LOW);
        digitalWrite(pinLed4, LOW);
        digitalWrite(pinLed5, HIGH);
        digitalWrite(pinLed6, LOW);
        
        break;
      case 0xFF38C7:  //botón 5
        digitalWrite(pinLed1, LOW);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, LOW);
        digitalWrite(pinLed4, LOW);
        digitalWrite(pinLed5, LOW);
        digitalWrite(pinLed6, HIGH);
        
        break;
      case 0xFF5AA5:  //botón 6  (For colour blinded xD)
        digitalWrite(pinLed1, LOW);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, LOW);
        digitalWrite(pinLed4, HIGH);
        digitalWrite(pinLed5, HIGH);
        digitalWrite(pinLed6, LOW);
        
        break;
      case 0xFFA25D:  // boton encendido
        digitalWrite(pinLed1, HIGH);
        digitalWrite(pinLed2, HIGH);
        digitalWrite(pinLed3, HIGH);
        digitalWrite(pinLed4, HIGH);
        digitalWrite(pinLed5, HIGH);
        digitalWrite(pinLed6, HIGH);
        break;
        
     }
     
     
  irrecv.resume();
  }
}
