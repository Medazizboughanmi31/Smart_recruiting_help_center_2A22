#define PIN_buzzer 11 //le numéro de la broche sur laquelle la lampe 2  est branchée led1
#define PIN_bouton 13 // Le numéro de la broche sur laquelle la lampe 1 led 2
//(par défaut intégrée dans la carte) est branchée 
#define pas  20 // incrément de l'intensité
char data; // variable contenant le caractère lu
int x; // variable contenant l'intensité de la deuxième lampe

void setup() {
  // Configure la broche 11 sur laquelle est reliée notre LED  en sortie
  pinMode(PIN_buzzer,OUTPUT);
//La LED reliée à la broche 11 est intialisé à l'état LOW
  digitalWrite(PIN_bouton,LOW);
  // Configure la broche 13 sur laquelle est reliée notre LED  en  
  pinMode(PIN_bouton,OUTPUT);
//La LED reliée à la broche 13 est intialisé à l'état LOW
pinMode(PIN_buzzer,OUTPUT);
  analogWrite(PIN_buzzer, 0);
  Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 
  x=0; // Intialiser l'intensité de la deuxième lampe 

}



void loop() {

  if (Serial.available())     {
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='1') //si le caractère lu est égale à 1
    {
      digitalWrite(PIN_bouton,HIGH); // alumer le bouton
      Serial.write('1'); //envoyer le nouvel état de la bouton 
     }  
     else if(data=='0') //si le caractère lu est égale à 0

     {
        digitalWrite(PIN_bouton,LOW); //éteindre la bouton
        Serial.write('0'); //envoyer le nouvel état de la bouton
     
     }   
  }
