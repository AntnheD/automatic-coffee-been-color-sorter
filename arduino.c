#include <Servo.h>
Servo pickServo;
Servo dropServo;

#define S0 4 
#define S1 5
#define S2 7
#define S3 6
#define sensorOut 8    
int frequency = 0;
int color=0;

int detectColor() {
  // activating red photodiodes to read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  Serial.print("Red = ");
  Serial.print(frequency);//printing RED color frequency
  Serial.print("   ");
  delay(50);

   // activating blue photodiodes to read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  Serial.print("Blue = ");
  Serial.print(frequency);
  Serial.println("   ");
  
  // activating green photodiodes to read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  Serial.print("Green = ");
  Serial.print(frequency);
  Serial.print("   ");
  delay(50);

  delay(50);

//Readings are different for different setup
//change the readings according your project and readings detected
  if( R<435& R>420& G<440 & G>425 & B<360 & B>340){
    color = 1; // Red
    Serial.print("Detected Color is = Read");
    Serial.println("RED");
     dropServo.write(5);
  }
  if(G<280 & G>260 & B<215 &B>228){
 color = 1; // Red
      Serial.println("Orange  ");
      dropServo.write(10);
  }
  if(R<420 & R>410& G<437 & G>420 & B<349 & B>330){
    color = 3; // Green
      Serial.print("Detected Color is = Green");
    Serial.println("GREEN");
     dropServo.write(100); 
  }
  if(R<499& R>489 & G<510 & G>500){
    color = 3; // Yellow
       Serial.print("Detected Color is = ");
    Serial.println("YELLOW");
    dropServo.write(100);
  }
  if (G<57& G>53 & B<43 &B>39){
    color = 5; // Blue
     Serial.print("Detected Color is = ");
    Serial.println("BLUE");
  }
  return color;  
}

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  //frequency-scaling to 20% selected
  digitalWrite(S0, LOW);
  digitalWrite(S1, HIGH);

  
  dropServo.attach(10);

  Serial.begin(9600);
}

void loop() {
  if (color = 0);{
   color = detectColor();
  }
  color = detectColor();
  delay(100);  

  switch (color) {
    case 1:
    dropServo.write(10);
      
    break;

    case 2:
      
    dropServo.write(60);
    break;

    case 3:
    
    dropServo.write(180);
    break;

    case 4:
  
    dropServo.write(60);
    break;

    case 5:
     
    dropServo.write(50);
    break;
    
    case 0:
    break;
  }
   color=0;
}