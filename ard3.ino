void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode(6,OUTPUT); //LED VERTE
  pinMode(9,OUTPUT); //LED ROUGE
}

void loop() {
  // put your main code here, to run repeatedly:
 // Mesure la tension sur la broche A0
  int valeur_brute=analogRead(A0) ;
  
  // Transforme la mesure (nombre entier) en température via un produit en croix
  float temperature_celcius = valeur_brute * (5.0 / 1023.0 * 100.0);
  
  // Envoi la mesure au PC pour affichage et attends 250ms
  Serial.println(temperature_celcius);
  delay(1000);
   if( temperature_celcius> 25)
  {
    digitalWrite(6,LOW); //  VERTE ETEINTE
    digitalWrite(9,HIGH); //  ROUGE ALLUMEE
    
  }
  
  else{
    digitalWrite(6,HIGH); // VERTE ALLUMEE
    digitalWrite(9,LOW); // ROUGE ETEINTE
   
  }
}
