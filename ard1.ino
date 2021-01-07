#include <Keypad.h>
#define pin_led1 12
#define pin_led2 13
char data;
int x;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] ={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS]= {5,4,3,2};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String s="    ";
char key=' ';
int i=-1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pin_led1,OUTPUT);
digitalWrite(pin_led2,LOW);
pinMode(pin_led2,OUTPUT);
pinMode(pin_led1,OUTPUT);
analogWrite(pin_led1,0);
x=0;
}

void loop() {
 if(Serial.available())
{
  data=Serial.read();
  if(data=='1')
  {
    digitalWrite(pin_led2,HIGH);
    delay(500);
     digitalWrite(pin_led2,LOW);
  }
  else if(data=='0')
  {
    digitalWrite(pin_led1,HIGH);
     delay(500);
     digitalWrite(pin_led1,LOW);
  }  
}
  // put your main code here, to run repeatedly:
char key = keypad.getKey();
if (key){
 
 if(key!='#')
  {
    i=i+1;
    s[i]=key;
  }
  else
  {
    Serial.println(s);
    s="    ";
    key=' ';
    i=-1;
  }
  }
}
