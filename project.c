#include<SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>    
LiquidCrystal_I2C lcd(0x27,16,2);
#include <SoftwareSerial.h>
 bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;
#include <TinyGPS.h>

TinyGPS gps;
SoftwareSerial ss(D6, D5);

 float flat, flon;
    unsigned long age;





int i=0,k=0;



void initModule(String cmd, char *res, int t)

{

  while(1)

  {

    Serial.println(cmd);

    Serial.println(cmd);

    delay(100);

    while(Serial.available()>0)

    {

       if(Serial.find(res))

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



void setup()

{
     lcd.init();      
   lcd.backlight();
pinMode(A0,INPUT_PULLUP);
  Serial.begin(9600);
 ss.begin(9600);
  Serial.begin(9600);

  //lcd.begin(16,2);  

  lcd.print("Women Safety  ");

  lcd.setCursor(0,1);

  lcd.print("     System     ");

  delay(2000);

  lcd.clear();

  lcd.print("Initializing");

  lcd.setCursor(0,1);

  lcd.print("Please Wait...");

  delay(1000);

 

  Serial.println("Initializing....");

  initModule("AT","OK",1000);

  initModule("ATE1","OK",1000);

  initModule("AT+CPIN?","READY",1000);  

  initModule("AT+CMGF=1","OK",1000);    

  initModule("AT+CNMI=2,2,0,0,0","OK",1000);  

  Serial.println("Initialized Successfully");

  lcd.clear();

  lcd.print("Initialized");

  lcd.setCursor(0,1);

  lcd.print("Successfully");

  delay(2000);

  lcd.clear();

 

  delay(1000);

 

  lcd.clear();

  lcd.print("Waiting For GPS");

  lcd.setCursor(0,1);

  lcd.print("     Signal    ");

  delay(2000);


  get_gps();

  delay(2000);

  lcd.clear();

  lcd.print("GPS is Ready");

  delay(1000);

  lcd.clear();

  lcd.print("System Ready");

  Serial.println("System Ready..");

}


void loop()

{

    int value1=analogRead(A0);
   

    Serial.print("x=");

    Serial.println(value1);

   

    if(value1>650)

    {

     get_gps();

 

      lcd.clear();

      lcd.print("Sending SMS ");

      Serial.println("Sending SMS");

      Send1();
      delay(1000);
      Send2();
     delay(1000);
     Send3();
     
 lcd.clear();
      Serial.println("SMS Sent");
       lcd.print("SMS Sent");
      delay(2000);

      lcd.clear();

      lcd.print("System Ready");

    }      

}



void get_gps()

{

 for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (ss.available())
    {
      char c = ss.read();
      // Serial.write(c); // uncomment this line if you want to see the GPS data flowing
      if (gps.encode(c)) // Did a new valid sentence come in?
        newData = true;
    }
  }

  if (newData)
  {
 
    gps.f_get_position(&flat, &flon, &age);
    Serial.print("LAT=");
    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Serial.print(" LON=");
    Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    Serial.print(" SAT=");
    Serial.print(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
    Serial.print(" PREC=");
    Serial.print(gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());
  }
}




void Send1()

{
  get_gps();
   Serial.println("AT");

   delay(500);

   serialPrint();

   Serial.println("AT+CMGF=1");

   delay(500);

   serialPrint();

   Serial.print("AT+CMGS=");

   Serial.print('"');

   Serial.print("+919830798713");    //mobile no. for SMS alert

   Serial.println('"');

   delay(500);

   serialPrint();

   Serial.print("Latitude:");

   Serial.println(flat,6);

   delay(500);

   serialPrint();

   Serial.print(" longitude:");

   Serial.println(flon,6);

   delay(500);

   serialPrint();

Serial.println("I am in Trouble");
   delay(500);

   serialPrint();

   Serial.print("http://maps.google.com/maps?&z=15&mrt=yp&t=k&q=");

   Serial.print(flat,6);

   Serial.print('+');              //28.612953, 77.231545   //28.612953,77.2293563

   Serial.println(flon,6);
 //  Serial.println(" ");

   Serial.write(26);

   delay(2000);

   serialPrint();

}
void Send2()

{
  get_gps();
   Serial.println("AT");

   delay(500);

   serialPrint();

   Serial.println("AT+CMGF=1");

   delay(500);

   serialPrint();

   Serial.print("AT+CMGS=");

   Serial.print('"');

   Serial.print("+918830870036");    //mobile no. for SMS alert

   Serial.println('"');

   delay(500);

   serialPrint();

   Serial.print("Latitude:");

   Serial.println(flat,6);

   delay(500);

   serialPrint();

   Serial.print(" longitude:");

   Serial.println(flon,6);

   delay(500);

   serialPrint();

Serial.println("I am in Trouble");
   delay(500);

   serialPrint();

   Serial.print("http://maps.google.com/maps?&z=15&mrt=yp&t=k&q=");

   Serial.print(flat,6);

   Serial.print('+');              //28.612953, 77.231545   //28.612953,77.2293563

   Serial.println(flon,6);
 //  Serial.println(" ");

   Serial.write(26);

   delay(2000);

   serialPrint();

}
void Send3()

{
  get_gps();
   Serial.println("AT");

   delay(500);

   serialPrint();

   Serial.println("AT+CMGF=1");

   delay(500);

   serialPrint();

   Serial.print("AT+CMGS=");

   Serial.print('"');

   Serial.print("+918208299455");    //mobile no. for SMS alert

   Serial.println('"');

   delay(500);

   serialPrint();

   Serial.print("Latitude:");

   Serial.println(flat,6);

   delay(500);

   serialPrint();

   Serial.print(" longitude:");

   Serial.println(flon,6);

   delay(500);

   serialPrint();

Serial.println("I am in Trouble");
   delay(500);

   serialPrint();

   Serial.print("http://maps.google.com/maps?&z=15&mrt=yp&t=k&q=");

   Serial.print(flat,6);

   Serial.print('+');              //28.612953, 77.231545   //28.612953,77.2293563

   Serial.println(flon,6);
 //  Serial.println(" ");

   Serial.write(26);

   delay(2000);

   serialPrint();

}
void serialPrint()

{
/*
  while(Serial.available()>0)

  {

    Serial.print(Serial.read());

  }
*/
}
