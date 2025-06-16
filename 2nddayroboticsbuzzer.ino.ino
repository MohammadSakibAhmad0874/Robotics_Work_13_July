void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3,OUTPUT);//when we connect any port then we write the prot number like 2 3 
  // put your setup code here, to run once:

}

void loop() {
  int signal = digitalRead(2);

  if (signal == 0){
    digitalWrite(3, HIGH);
    Serial.println(signal);
  }
  else{
    digitalWrite(3, LOW);
    Serial.println(signal);
  }
  // put your main code here, to run repeatedly:

}
