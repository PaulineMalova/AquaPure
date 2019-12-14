#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
#define echopin 9
#define trigpin 8

//int maximumRange = 50;
long Time, distance;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
 
}

void loop() {
  {
    digitalWrite(trigpin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigpin, HIGH);
    delayMicroseconds(10);
  
    digitalWrite(trigpin, LOW);
    Time=pulseIn(echopin,HIGH);
  
    distance = (0.0343*Time)/2;
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println("cm");
  
    Serial.println(" ");
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("water level: ");
    lcd.print(distance);
    delay(500);
  }

  if (distance <= 5){
    Serial.println("Time to pump now!");
    digitalWrite(13, HIGH);   //connect to relay 
    digitalWrite(7, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Water being pumped");
    delay(500);
  }
  else{
    Serial.println("More water needed before pumping can be done");
    digitalWrite(7, LOW);
    digitalWrite(13, LOW);
    lcd.setCursor(0,1);
    lcd.print("Pumping stopped");
    delay(500);
  }
  

  

}
