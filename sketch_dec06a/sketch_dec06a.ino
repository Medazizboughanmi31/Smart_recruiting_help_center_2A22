
const int buzzer = 12; //buzzer to arduino pin 9
char data;


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  
  Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 


  
}

void loop(){

 int i =0;
  
  if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='1') //si le caractère lu est égale à 1
    {
      do {  
      i++;
      tone(buzzer, 1000); // Send 1KHz sound signal...
      delay(1000);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(1000);
    } while (i<3);
    }else
    {
      noTone(buzzer);
      }
    }
    }
    
     
