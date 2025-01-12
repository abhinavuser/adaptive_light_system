int echoPin1=11;
int trigPin1=12;
int echoPin2=2;
int trigPin2=3;
int pingTravelTime1;
float distInCms1;
int pingTravelTime2;
float distInCms2;
int led1=6;
int led2=8;
int led3=4;
int led4=5;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin1,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);
  
  pingTravelTime1=pulseIn(echoPin1,HIGH);
  //Serial.print(pingTravelTime1);
  //Serial.print("-");
  distInCms1=3.5+(11./700. *(pingTravelTime1-200));
  //Serial.println("d1:"distInCms1);
  delay(500);
  if(distInCms1<=15 && distInCms1>=2)
    {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);

    }
  digitalWrite(trigPin2,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  pingTravelTime2=pulseIn(echoPin2,HIGH);
  //Serial.print(pingTravelTime2);
  //Serial.print("-");
  distInCms2=3.5+(11./700. *(pingTravelTime2-200));
  Serial.print(distInCms1 );
  Serial.print( " - ");
  Serial.println(distInCms2);
  delay(500);
  if(distInCms2<=15 && distInCms2>=2)
{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    delay(3000);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
}
