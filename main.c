#include <Servo.h>
Servo myservo1;
Servo myservo2;

int trigPin = 13;
int echoPin = 12;
int pos1 = 0;    
int pos2 = 0;    
int dist = 0;
int header = 111;

void setup()
{
  Serial.begin(9600);
//      while (!Serial) {
//      ; // wait for serial port to connect. Needed for native USB port only
//    }
  myservo1.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(6);
}

void loop()
{
vSweep();  
}

void hSweep()
{
    for(pos2 = 0; pos2 <= 180; pos2 += 1) // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    vSweep();

    //dist = distPing();
    //senddata();
   
    delay(15);                       // waits 15ms for the servo to reach the position    
  }
  for(pos2 = 180; pos2>=0; pos2-=1)     // goes from 180 degrees to 0 degrees
  {    
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    vSweep();
    
    //dist = distPing();
    //senddata();
    
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void vSweep()
{
  for(pos1 = 0; pos1 <= 180; pos1 += 1) // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos
    dist = distPing();
    senddata();
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for(pos1 = 180; pos1>=0; pos1-=1)     // goes from 180 degrees to 0 degrees
  {
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    dist = distPing();
    senddata();
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

int distPing()
{
  int duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;  
  delay(100);
  return distance;
  }

void senddata()
{
    Serial.write(header);
    Serial.write(pos1);
    Serial.write(2);
    Serial.write(dist);
    }
