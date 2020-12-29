void setup() {
  // put your setup code here, to run once:
  pinMode(26,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(26,HIGH);
  delay(3000);
  digitalWrite(26,LOW);
  delay(1000);
  digitalWrite(22,HIGH);
  delay(3000);
  digitalWrite(22,LOW);
  delay(1000);
digitalWrite(23,HIGH);
  delay(3000);
  digitalWrite(23,LOW);
  delay(1000);

}
