int MinlimitSwitchPin=4;//Home limit switch
int MaxlimitSwitchPin=3;//End limit switch
int DCMOTORF=1;//Move DC motor CW
int DCMOTORB=0;//Move DC motor CCW
int RelayACMotorPin=2;//interrupt, signal for relay that control AC Motor
int dely0=5;
int dely1=6;
int dely2=7;
int dely3=8;
int dely4=9;

void setup(){
  pinMode(RelayACMotorPin,OUTPUT);
  pinMode(DCMOTORF,OUTPUT);
  pinMode(DCMOTORB,OUTPUT); 
  pinMode(MinlimitSwitchPin,INPUT);
  pinMode(MaxlimitSwitchPin,INPUT);
  pinMode(dely0,INPUT);
  pinMode(dely1,INPUT);
  pinMode(dely2,INPUT);
  pinMode(dely3,INPUT);
  pinMode(dely4,INPUT);

}
void loop(){
  digitalWrite(dely0,LOW);
  digitalWrite(dely1,LOW);
  digitalWrite(dely2,LOW);
  digitalWrite(dely3,LOW);
  digitalWrite(dely4,LOW);
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
          if(digitalRead(dely0)==HIGH){
                      delay(18000);
          }
          if(digitalRead(dely1)==HIGH){
                      delay(25000);
          }
          if(digitalRead(dely2)==HIGH){
                      delay(30000);
          }
          if(digitalRead(dely3)==HIGH){
                      delay(35000);
          }
          if(digitalRead(dely4)==HIGH){
                      delay(40000);
          }
          digitalWrite(RelayACMotorPin, LOW);
          delay(25000);
          MoveDCMotorB();
          delay(3000);
          MoveDCMotorB();
          digitalRead(MaxlimitSwitchPin) == LOW;      
       }
       
}


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
}
