// Include servo header file to use output to the Talon SR
#include <Servo.h>

// init servo, which is actually a CIM motor
Servo act_1;

// init constants
int readPin = 2;
int led = 13;
int i = 0;

// Start file
void setup() {

  // Read Dig
  pinMode(readPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  // PWM
  act_1.attach(3);

  // additional serial for debug
  Serial.begin(9600);
}

void loop() {
  
  // if the button is pressed (signal of 1 from the pulldown), "runOnce" at 100% DS
  if(digitalRead(readPin) == 1) {
    Serial.println("ACTIVE!");
    Serial.println("Running Once at 100% DS");
    runOnce(100);
  } 
}

// set motor and PWM output
void set_motor_p(Servo m, int p) {
  p = constrain(p, -100, 100);
  int min = 1000;
  int max = 2000;
  int out = map(p, -100, 100, min, max); // (val, fmin, fmax) -> (tmin, tmax)
  m.writeMicroseconds(out);
}

// function for controlling a gradient output of the motor (now unused)
void ease_to(int percentage, int delayAmt) {
  while (i < percentage) {
    set_motor_p(act_1, i);
    i++;
    delay(delayAmt);
  }

  while (i > percentage) {
    set_motor_p(act_1, i);
    i--;
    delay(delayAmt);
  }
}

// major command: causes the bat to run at the specified DS, for the tuned constant randomized time period
void runOnce(int percentage) {

  // safety and state prints
  for (int j=3; j>0; j--) {
    Serial.println(String(j)+"...");
    digitalWrite(led, 1);
    delay(500);
    digitalWrite(led, 0);
    delay(500);
  }

  digitalWrite(led, 1);
  Serial.println("LAUNCHING T-BALL");
  set_motor_p(act_1, percentage);

  // since there is bias with using timing (no encoder present), add a randomness to the timing to compensate for drift
  long RandVal = random(700, 703);
  Serial.println(RandVal);
  delay(RandVal);
  
  set_motor_p(act_1, 0);
  digitalWrite(led,0);
  Serial.println("COMPLETED CYCLE");
}
