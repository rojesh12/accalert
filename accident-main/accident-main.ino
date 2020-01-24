#include<SoftwareSerial.h>
SoftwareSerial Serial1(2,3); 
SoftwareSerial gps(10,11);
#include<LiquidCrystal.h>
LiquidCrystal lcd(4,5,6,7,8,9);

#define x A1
#define y A2
#define z A3

int xsample=0;
int ysample=0;
int zsample=0;

#define samples 10

#define minVal -40
#define MaxVal 40

int i=0,k=0;
int  gps_status=0;
float latitude=0; 
float logitude=0;                       
String Speed="";
String gpsString="";
char *test="$GPRMC";

void initModule(String cmd, char *res, int t)
{
  while(1)
  {
    Serial.println(cmd);
    Serial1.println(cmd);
    delay(100);
    while(Serial1.available()>0)
    {
       if(Serial1.find(res))
       {
        Serial.println(res);
        delay(t);
        return;
       }

       else
       {
        Serial.println("Error");
       }
    }
    delay(t);
  }
}
