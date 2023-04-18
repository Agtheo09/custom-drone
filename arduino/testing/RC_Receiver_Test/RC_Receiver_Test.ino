#include <Serial.h>

// RC Reciever Pins
#define Thrust_Pin 36
#define Yaw_Pin 37
#define Pitch_Pin 38
#define Roll_Pin 39

double thrust_contr, yaw_contr, pitch_contr, roll_contr;

void setup() {
  Serial.begin(9600);
  // RC Reciever Inputs
  pinMode(Thrust_Pin, INPUT);
  pinMode(Yaw_Pin, INPUT);
  pinMode(Pitch_Pin, INPUT);
  pinMode(Roll_Pin, INPUT);
}

void loop() {
  // Read Controller Value hereeeee....
  thrust_contr = analogRead(Thrust_Pin);
  yaw_contr = analogRead(Yaw_Pin);
  pitch_contr = analogRead(Pitch_Pin);
  roll_contr = analogRead(Roll_Pin);

  Serial.print("Thrust: ");
  Serial.println(thrust_contr);
  Serial.print("Yaw: ");
  Serial.println(yaw_contr);
  Serial.print("Pitch: ");
  Serial.println(pitch_contr);
  Serial.print("Roll: ");
  Serial.println(roll_contr);
}
