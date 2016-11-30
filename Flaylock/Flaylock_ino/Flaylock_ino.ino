//Test

/* the tutorial code for 3x4 Matrix Keypad with Arduino is as
This code prints the key pressed on the keypad to the serial port*/
  
#include "Keypad.h"
#include "Wire.h"
#include "Servo.h"
#include "Password.h"

Password password = Password( "1234
\" );
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 

char Data[20];
const byte Rows= 5; //number of rows on the keypad i.e. 4
const byte Cols= 3; //number of columns on the keypad i,e, 3
byte data_count = 0, master_count = 0;


//we will define the key map as on the key pad:
char keymap[Rows][Cols]=
{
{'4', '5', '6'},
{'1', '2', '3'},
{'A', 'B', 'C'},
{'7', '8', '9'},
{'*', '0', '#'}
};
  
//  a char array is defined as it can be seen on the above


//keypad connections to the arduino terminals is given as:

byte rPins[Rows]= {A3,A4,A5,A6,A7}; //Rows 0 to 3
byte cPins[Cols]= {A2,A1,A0}; //Columns 0 to 2

// command for library forkeypad
//initializes an instance of the Keypad class
Keypad keypad= Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);

void setup()
{
     Serial.begin(9600);  // initializing serail monitor
     myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
     keypad.addEventListener(keypadEvent); //add an event listener for this keypad

}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
void loop()
{ 
//    char keypressed = keypad.getKey();
//    if (keypressed != NO_KEY)
//     { 
//          Serial.println(keypressed);
//     }
//     if (keypressed == 'A')
//     {
//     Serial.println("Great success!");
//     for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
//  {                                  // in steps of 1 degree 
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(15);                       // waits 15ms for the servo to reach the position 
//  } 
//  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
//  {                                
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(15);                       // waits 15ms for the servo to reach the position 
//  }
//}
keypad.getKey();
}


//take care of some special events
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
	Serial.print("Pressed: ");
	Serial.println(eKey);
	switch (eKey){
	  case '#': checkPassword(); break;
	  case '*': password.reset(); break;
	  default: password.append(eKey);
     }
  }
}


void checkPassword(){
  if (password.evaluate()){
    Serial.println("Success");
    {
     Serial.println("Great success!");
     for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
              }
  }}else{
  {
    Serial.println("Wrong");
    //add code to run if it did not work
  }
}}
