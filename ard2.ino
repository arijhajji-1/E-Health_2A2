
int ledPin = 13;                
int inputPin = 2;               
int pirState = LOW;             
int val = 0;                    

void setup() {
  // put your setup code here, to run once:
    pinMode(ledPin, OUTPUT);     
  pinMode(inputPin, INPUT);     
 
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available())
{
  


do 
{
 
val = digitalRead(inputPin);

  if (val == HIGH) {            
    digitalWrite(ledPin, HIGH);  
    if (pirState == LOW) {
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); 
    if (pirState == HIGH){
      pirState = LOW;
    }
  }
}while  (Serial.read()!='0');
   
          if (Serial.read()!='1')
{
 digitalWrite(ledPin, LOW);
 digitalWrite(inputPin,LOW);
 val=inputPin; 
}

    }
  

  

}
