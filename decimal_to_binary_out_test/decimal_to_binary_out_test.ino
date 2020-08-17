//13/06/18 - Test code for converting decimal to 4 bit binary output for 7-seg decoder/driver
//Test circuit setup with Arduino Uno, 4511 decoder driver, 7 seg display.

int var = 0;    //Variable between 0 to 9

int bit_[4];   //Array for storing 4 bit number
const int D[] = {2,3,4,5};  //array of output pins D0, D1, D2, D3
const int Hold = 6;   //Hold data pin, 'LE' on the 4511 decoder

void setup() 
{
  Serial.begin(9600);   //For debugging
  
  //Set the outputs to the decoder/driver
  pinMode(D[0], OUTPUT);
  pinMode(D[1], OUTPUT);
  pinMode(D[2], OUTPUT);
  pinMode(D[3], OUTPUT);
  pinMode(Hold, OUTPUT);
  digitalWrite(Hold, LOW);  //Make low so that the display is constantly updated
}

void loop() 
{
  //Convert the integer to 4 bit binary value by masking
  bit_[3] = (1&&(var & B1000));
  bit_[2] = (1&&(var & B0100));
  bit_[1] = (1&&(var & B0010));
  bit_[0] = (1&&(var & B0001));

  //Loop through each bit
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(D[i], bit_[i]);  //Write each output state
  }
  
  Serial.print(var);  //print var
  Serial.print(' ');  //Space
  for(int i = 3; i > -1; i--)
  {
    Serial.print(bit_[i]);    //print the binary outputs
  }
  Serial.println(); //start new line
  
  var ++;    //incriment variable
  if (var > 9) var = 0;    //Cannot display more than 9 so wrap around to 0

  delay(1000);   //Wait
}

//End of program
