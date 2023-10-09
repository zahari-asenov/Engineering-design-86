#include <Servo.h> 

Servo servo; // servo object representing the MG 996R servo
int IRSensor = 9; // connect ir sensor module to Arduino pin 9
int LED = 13; // conect LED to Arduino pin 13
const int buttonPin = 2;  // the number of the pushbutton pin
int buttonState = 0;
const int ledPin = 13;    // the number of the LED pin
int timeSensor = 0;       // sensing time

void setup()
{
  Serial.begin(115200); // Init Serila at 115200 Baud
  Serial.println("Serial Working"); // Test to check if serial is working or not
  servo.attach(3); // servo is wired to Arduino on digital pin 3
  pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
  pinMode(LED, OUTPUT); // LED Pin Output
  pinMode(ledPin, OUTPUT); // initialize the LED pin as an output
  pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input
}

void loop()
{
  int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input
  buttonState = digitalRead(buttonPin); // read the state of the pushbutton value

  if (timeSensor == 10) // if it senses for more than 10 seconds
  {
    //lock the hooks
    servo.write(0); // move MG996R's shaft to angle 0°
    delay(1000); // wait for one second
    servo.write(45); // move MG996R's shaft to angle 45°
    delay(1000); // wait for one second 
    servo.write(90); // move MG996R's shaft to angle 90°
    delay(1000); // wait for one second
    servo.write(135); // move MG996R's shaft to angle 135°
    delay(1000); // wait for one second
    servo.write(180); // move MG996R's shaft to angle 180°
    delay(1000); // wait for one second
    timeSensor == 11; // stop adding
  }

  if (sensorStatus == 1) // Check if the pin high or not
  {
    //check if it senses something for a long time
    digitalWrite(LED, HIGH); // LED High
    if (timeSensor != 11) //check if it needs to stop adding
      timeSensor += 1;
  }
  delay(1000);

  if (buttonState == HIGH) // check if the pushbutton is pressed. If it is, the buttonState is HIGH
  {
    // unlock the hooks
    servo.write(0); // move MG996R's shaft to angle 0°
    delay(1000); // wait for one second
    servo.write(45); // move MG996R's shaft to angle 45°
    delay(1000); // wait for one second 
    servo.write(90); // move MG996R's shaft to angle 90°
    delay(1000); // wait for one second
    servo.write(135); // move MG996R's shaft to angle 135°
    delay(1000); // wait for one second
    servo.write(180); // move MG996R's shaft to angle 180°
    delay(1000); // wait for one second
    timeSensor == 0; // reset
  }
}
