j/* the tutorial code for 3x4 Matrix Keypad with Arduino is as
This code prints the key pressed on the keypad to the serial port*/

#include <Keypad.h>
#include <Wire.h>
#include <Servo.h>

Servo myservo; // Create Servo Object
int pos = 0; // Set Servo Position
char Data[20];
const byte Rows= 5; //number of rows on the keypad i.e. 4
const byte Cols= 3; //number of columns on the keypad i,e, 3
byte data_count = 0, master_count = 0;

char Master[2][7] = {
  "123456",
  "000123"
};

//char * User[Usercount] = {
//"Master","Andrew","INVALID"};
  
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
Keypad kpd= Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);

void setup()
{
     myservo.attach(9);
     Serial.begin(9600);  // initializing serail monitor
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
void loop()
{ 
    char keypressed = kpd.getKey();
    if (keypressed != NO_KEY)
     { 
          Serial.println(keypressed);
          Serial.println("Enter Password");
          Serial.println("Bloop");
     }
     if (keypressed == 'A')   
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
}


// Get rid of this shit after prototyping


