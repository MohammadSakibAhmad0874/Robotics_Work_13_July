void setup()
{
  Serial.begin(9600);
    pinMode(2,INPUT);
    pinMode(3,INPUT);
    pinMode(4,OUTPUT);
}

void loop(){
int signal1=digitalRead(2);
int signal2=digitalRead(3);
  if(signal1==0 && signal2==0){
   Serial.println("distance 1");
    }
  else if(signal1==0 && signal2==1){
    
   Serial.println("distance 2");
    }
  else if(signal1==1 && signal2==0){
    Serial.println("distance 3");
    digitalWrite(4, LOW);
    }
  
  else if(signal1==1 && signal2==1){
    Serial.println("distance 4");
    digitalWrite(4, HIGH);
    }

}