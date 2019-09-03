unsigned char input0=14;
int dat[100];
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
      dat[ptr]=analogRead(input0);
      delayMicroseconds(timeBase);
  }
  timeoutStatus=true;
  while(timeoutStatus==true)
  {
      Serial.println("R?");
      serialRead=Serial.readString();
      if(serialRead=="K")
        timeoutStatus=false;
  }
  for(ptr=0; ptr<100; ptr++)
  {
    Serial.write(highByte(dat[ptr]<<6));
  }
}
