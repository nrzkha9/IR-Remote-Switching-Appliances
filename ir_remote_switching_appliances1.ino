#include <IRremote.h>                 //IR Remote library
#include <LiquidCrystal.h>            //LCD library

#define button1  16582903             // code button 1
#define button2  16615543             // code button 2
#define button3  16599223
#define button4  16591063
#define button5  16623703
#define button6  16607383
#define both     16580863             // code power button

LiquidCrystal lcd(12,10,7,6,5,4);

int irsensor = 11;                    //IR sensor output pin
IRrecv irrecv(irsensor);
decode_results results;

int kipas = 3;                        //fan pin
int lampu = 2;                        //bulb pin
int status[] = {0,0,0};               //initial state of appliances is OFF (zero) 

 
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);                    // Start the LCD
  irrecv.enableIRIn();               // Start the IR receiver
  
  pinMode(kipas, OUTPUT);
  pinMode(lampu, OUTPUT);
  
  lcd.setCursor(4,0);     
  lcd.print("EEED253");   
  lcd.setCursor(2,1);
  lcd.print("Class Project");
  delay(300);
  lcd.clear();
  
  lcd.setCursor(3,0);
  lcd.print("IR Remote");      
  lcd.setCursor(0,1);
  lcd.print("Switch Appliance");
  delay(200);
  lcd.clear();
  
  lcd.setCursor(3,0);
  lcd.print("Designed by");      
  lcd.setCursor(4,1);
  lcd.print("zulaikha");
  delay(200);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("fan:  OFF");             //intial condition
  lcd.setCursor(0,1);
  lcd.print("bulb: OFF");
}
 

void loop() 
{
  if (irrecv.decode(&results)) 
  {
    unsigned int value = results.value;
    switch(value) 
    {
      
      
    case button1:
       digitalWrite(kipas, HIGH);    // turn on when button is pressed
       digitalWrite(lampu, HIGH);
       status[1] = 1;                // set status as ON
       status[2] = 1;
       lcd.setCursor(6,0);          //display condition on LCD
       lcd.print("ON 10min"); 
       lcd.setCursor(6,1);          //display condition on LCD
       lcd.print("ON 10min");
       delay(600000);  
       digitalWrite(kipas, LOW);
       digitalWrite(lampu, LOW);
       status[1] = 0;
       status[2] = 0;
       lcd.setCursor(6,0);          
       lcd.print("OFF     "); 
       lcd.setCursor(6,1);          
       lcd.print("OFF     ");     
    break;
      
      
    case button2:
       digitalWrite(kipas, HIGH);    // turn on when button is pressed
       digitalWrite(lampu, HIGH);
       status[1] = 1;                // set status as ON
       status[2] = 1;
       lcd.setCursor(6,0);          //display condition on LCD
       lcd.print("ON 20min"); 
       lcd.setCursor(6,1);          //display condition on LCD
       lcd.print("ON 20min");
       delay(1200000);  
       digitalWrite(kipas, LOW);
       digitalWrite(lampu, LOW);
       status[1] = 0;
       status[2] = 0;
       lcd.setCursor(6,0);          
       lcd.print("OFF     "); 
       lcd.setCursor(6,1);          
       lcd.print("OFF     ");     
    break;  
      
      
    case button3:
       digitalWrite(kipas, HIGH);    // turn on when button is pressed
       digitalWrite(lampu, HIGH);
       status[1] = 1;                // set status as ON
       status[2] = 1;
       lcd.setCursor(6,0);          //display condition on LCD
       lcd.print("ON 30min"); 
       lcd.setCursor(6,1);          //display condition on LCD
       lcd.print("ON 30min");
       delay(1800000);  
       digitalWrite(kipas, LOW);
       digitalWrite(lampu, LOW);
       status[1] = 0;
       status[2] = 0;
       lcd.setCursor(6,0);          
       lcd.print("OFF     "); 
       lcd.setCursor(6,1);          
       lcd.print("OFF     ");    
    break; 
      
      
    case button4:
       digitalWrite(kipas, HIGH);    // turn on when button is pressed
       digitalWrite(lampu, HIGH);
       status[1] = 1;                // set status as ON
       status[2] = 1;
       lcd.setCursor(6,0);          //display condition on LCD
       lcd.print("ON 40min"); 
       lcd.setCursor(6,1);          //display condition on LCD
       lcd.print("ON 40min");
       delay(2400000);  
       digitalWrite(kipas, LOW);
       digitalWrite(lampu, LOW);
       status[1] = 0;
       status[2] = 0;
       lcd.setCursor(6,0);          
       lcd.print("OFF     "); 
       lcd.setCursor(6,1);          
       lcd.print("OFF     ");    
    break; 
      
      
    case button5:
       digitalWrite(kipas, HIGH);    // turn on when button is pressed
       digitalWrite(lampu, HIGH);
       status[1] = 1;                // set status as ON
       status[2] = 1;
       lcd.setCursor(6,0);          //display condition on LCD
       lcd.print("ON 50min"); 
       lcd.setCursor(6,1);          //display condition on LCD
       lcd.print("ON 50min");
       delay(3000000);  
       digitalWrite(kipas, LOW);
       digitalWrite(lampu, LOW);
       status[1] = 0;
       status[2] = 0;
       lcd.setCursor(6,0);          
       lcd.print("OFF     "); 
       lcd.setCursor(6,1);          
       lcd.print("OFF     ");    
    break; 
      
      
    case button6:
       digitalWrite(kipas, HIGH);    // turn on when button is pressed
       digitalWrite(lampu, HIGH);
       status[1] = 1;                // set status as ON
       status[2] = 1;
       lcd.setCursor(6,0);          //display condition on LCD
       lcd.print("ON 1hr"); 
       lcd.setCursor(6,1);          //display condition on LCD
       lcd.print("ON 1hr");
       delay(3600000);  
       digitalWrite(kipas, LOW);
       digitalWrite(lampu, LOW);
       status[1] = 0;
       status[2] = 0;
       lcd.setCursor(6,0);          
       lcd.print("OFF    "); 
       lcd.setCursor(6,1);          
       lcd.print("OFF    ");    
    break; 
      
      
    case both:
    if(status[1] == 1 && status[2] == 1) 
    {   digitalWrite(kipas, LOW);      
        status[1] = 0;              
        lcd.setCursor(6,0);      
        lcd.print("OFF     ");

        digitalWrite(lampu, LOW);
        status[2] = 0;
        lcd.setCursor(6,1);      
        lcd.print("OFF   ");        }
    else 
    {   digitalWrite(kipas, HIGH);   
        status[1] = 1;            
        lcd.setCursor(6,0);    
        lcd.print("ON      ");
        digitalWrite(lampu, HIGH);
        status[2] = 1;
        lcd.setCursor(6,1);    
        lcd.print("ON    ");        }
      
    }
    Serial.println(value);      
    irrecv.resume();                     // take next value
  }
}