unsigned char input0=14; //may use int as well, no visible effect on performance
int dat[100]; //stores the input voltage values
unsigned char ptr;
int timeBase;
bool timeoutStatus;
String serialRead;

void setup() 
{
 Serial.begin(115200); //standard baud rate 
 Serial.setTimeout(20);
 pinMode(input0, INPUT);
 timeBase=100;
}
void loop() 
{
  for(ptr=0; ptr<100; ptr++)
  {
      dat[ptr]=analogRead(input0); //store 100 values in the array
      delayMicroseconds(timeBase); //wait for some time for stability in case the signal frequency is very low.
  }
  timeoutStatus=true;
  while(timeoutStatus==true)
  {
      Serial.println("R?"); //check if the python script is ready for taking new values
      serialRead=Serial.readString();
      if(serialRead=="K")
        timeoutStatus=false;
  }
  for(ptr=0; ptr<100; ptr++)
  {
    Serial.write(highByte(dat[ptr]<<6)); //send the values one by one, scaled by a conversion factor of 2^6, calculated via experimental observation
  }
}
