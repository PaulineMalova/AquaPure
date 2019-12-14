int trig = 5;
int echo = 3;
float distance;
float Time;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  Serial.println("Water level sensor at work");
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  Time=pulseIn(echo,HIGH);
  distance = (0.0343*Time)/2;
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println("cm");

  Serial.println(" ");

  if (distance >= 18){
    Serial.println("Time to pump now!");
  }
  else{
    Serial.println("More water needed before pumping can be done");
  }

  Serial.println(" ");
  delay(5000);

}
