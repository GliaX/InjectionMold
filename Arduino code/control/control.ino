int MinlimitSwitchPin=4;//Home limit switch
int MaxlimitSwitchPin=3;//End limit switch
int DCMOTORF=1;//Move DC motor CW
int DCMOTORB=0;//Move DC motor CCW
int RelayACMotorPin=2;//interrupt, signal for relay that control AC Motor


void setup(){
  pinMode(RelayACMotorPin,OUTPUT);
  pinMode(DCMOTORF,OUTPUT);
  pinMode(DCMOTORB,OUTPUT); 
  pinMode(MinlimitSwitchPin,INPUT);
  pinMode(MaxlimitSwitchPin,INPUT);
}
void loop(){
  digitalRead(MinlimitSwitchPin) == HIGH;
        if(digitalRead(MinlimitSwitchPin) == HIGH){
           MoveDCMotorF();
           digitalWrite(RelayACMotorPin, LOW);
           digitalRead(MinlimitSwitchPin) == LOW;
        }
        else if(digitalRead(MaxlimitSwitchPin) == HIGH){
          StopDCMotor();
          digitalWrite(RelayACMotorPin, HIGH);
          delay(20000);
          digitalWrite(RelayACMotorPin, LOW);
          delay(25000);
          MoveDCMotorB();
          delay(3000);  
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
