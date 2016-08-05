#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Empty.h>
#include <race/drive_values.h>
ros::NodeHandle  nh;


boolean flagStop = false;
int pwm_center_value = 9830;  //  15% duty cycle
int pwm_lowerlimit = 6554;    //  10% duty cycle
int pwm_upperlimit = 13108;   //  20% duty cycle

std_msgs::Int32 str_msg;
ros::Publisher chatter("chatter", &str_msg);

int kill_pin = 2;
unsigned long duration = 0;

void messageDrive( const race::drive_values& pwm )
{
//  Serial.print("Pwm drive : ");
//  Serial.println(pwm.pwm_drive);
//  Serial.print("Pwm angle : ");
//  Serial.println(pwm.pwm_angle);
  
  if(flagStop == false)
  {
    str_msg.data = pwm.pwm_drive;
    chatter.publish( &str_msg );

    if(pwm.pwm_drive < pwm_lowerlimit)
    {
      analogWrite(5,pwm_lowerlimit);    //  Safety lower limit        
    }
    else if(pwm.pwm_drive > pwm_upperlimit)
    {
      analogWrite(5,pwm_upperlimit);    //  Safety upper limit
    }
    else
    {
      analogWrite(5,pwm.pwm_drive);     //  Incoming data                    
    }

    
    if(pwm.pwm_angle < pwm_lowerlimit)
    {
      analogWrite(6,pwm_lowerlimit);    //  Safety lower limit        
    }
    else if(pwm.pwm_angle > pwm_upperlimit)
    {
      analogWrite(6,pwm_upperlimit);    //  Safety upper limit
    }
    else
    {
      analogWrite(6,pwm.pwm_angle);     //  Incoming data                    
    }

  }
  else
  {
    analogWrite(5,pwm_center_value);
    analogWrite(6,pwm_center_value);    
  }
}

void messageEmergencyStop( const std_msgs::Bool& flag )
{
  flagStop = flag.data;
  if(flagStop == true)
  {
    analogWrite(5,pwm_center_value);
    analogWrite(6,pwm_center_value);    
  }
}


ros::Subscriber<race::drive_values> sub_drive("drive_pwm", &messageDrive );
ros::Subscriber<std_msgs::Bool> sub_stop("eStop", &messageEmergencyStop );


void setup() {
  
  analogWriteFrequency(5, 100);
  analogWriteFrequency(6, 100);
  analogWriteResolution(16);
  analogWrite(5,pwm_center_value);
  analogWrite(6,pwm_center_value);
  pinMode(13,OUTPUT); 
  digitalWrite(13,HIGH);
  pinMode(2,INPUT); 
//  digitalWrite(2,LOW);

  nh.initNode();
  nh.subscribe(sub_drive);
  nh.subscribe(sub_stop);

  nh.advertise(chatter);
}

void loop() {
  nh.spinOnce();
  duration = pulseIn(kill_pin, HIGH, 30000);
  while(duration > 1900)
  {
    duration = pulseIn(kill_pin, HIGH, 30000);
    analogWrite(5,pwm_center_value);
    analogWrite(6,pwm_center_value);        
  }
  // put your main code here, to run repeatedly:
  /*
  if(Serial.available())
  {
    int spd = Serial.read();
    if(spd>127) {
      spd = spd-128;
      spd = map(spd,0,100,410,820);
      analogWrite(5,spd);  
    }
    else {
      //angle servo
      spd = map(spd,0,100,410,820);
      analogWrite(6,spd);
    }
    
  } 
  */ 
}

