int MinlimitSwitchPin=4;//Home limit switch
int MaxlimitSwitchPin=3;//End limit switch
int DCMOTORF=1;//Move DC motor CW
int DCMOTORB=0;//Move DC motor CCW
int RelayACMotorPin=2;//interrupt, signal for relay that control AC Motor
int bot0=5;
int bot1=6;
int bot2=7;
int bot3=8;
int bot4=9;

void setup() {
  pinMode(RelayACMotorPin,OUTPUT);
  pinMode(DCMOTORF,OUTPUT);
  pinMode(DCMOTORB,OUTPUT); 
  pinMode(MinlimitSwitchPin,INPUT);
  pinMode(MaxlimitSwitchPin,INPUT);
  pinMode(bot0,INPUT);
  pinMode(bot1,INPUT);
  pinMode(bot2,INPUT);
  pinMode(bot3,INPUT);
  pinMode(bot4,INPUT);
}

void loop() {
int count1=0;
int count2=0;
int count3=0;
int count4=0;
int count5=0;
if(digitalRead(MinlimitSwitchPin) == HIGH){
   MoveDCMotorF();
   delay(3000);
   MoveDCMotorB();
   delay(3000);
   MoveDCMotorF();
   digitalWrite(RelayACMotorPin, LOW);
   digitalRead(MinlimitSwitchPin) == LOW;
}
else if(digitalRead(MaxlimitSwitchPin) == HIGH){
  StopDCMotor();
  digitalWrite(RelayACMotorPin, HIGH);
  int D = 0;
  if(digitalRead(bot0)==HIGH){
    count1=2000;
  }
  if(digitalRead(bot1)==HIGH){
    count2=5000;
  }
  if(digitalRead(bot2)==HIGH){
    count3=8000;
  }
  if(digitalRead(bot3)==HIGH){
    count4=11000;
  }
  if(digitalRead(bot4)==HIGH){
    count5=15000;
  }
D=count1+count2+count3+count4+count5;
delay(15000);
delay(D);
D = 0;
digitalWrite(RelayACMotorPin, LOW);
delay(25000);
MoveDCMotorB();
delay(3000);
MoveDCMotorB();
digitalRead(MaxlimitSwitchPin) == LOW;
}
}

//******************************

//This function is used for move DC motor to CW
   int MoveDCMotorF (){
  analogWrite(DCMOTORF,254);
  digitalWrite(DCMOTORB, LOW);
}
//This function is used for move DC motor to CCW
int MoveDCMotorB(){
  analogWrite(DCMOTORB,254);
  digitalWrite(DCMOTORF, LOW);
}
//This function is used for Stop DC motor
int StopDCMotor(){
  analogWrite(DCMOTORF,LOW);
  digitalWrite(DCMOTORB, LOW);  
}//**************************************
