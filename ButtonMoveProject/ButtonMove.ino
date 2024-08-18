#include <Stepper.h>

int num_steps = 2038;
int speed = 10;

Stepper my_stepper = Stepper(num_steps, 4, 6, 5, 7);

int max_step = 500;
int min_step = 0;
int current_step;

bool button_down() {
  return (digitalRead(3) == LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {};
  Serial.println("Setup Starting");

  my_stepper.setSpeed(speed);

  pinMode(3, INPUT_PULLUP);

  current_step = 0;

  Serial.println("Setup Done");
}

void loop() {
  // put your main code here, to run repeatedly:  
  if (button_down()) {
    if (current_step < max_step) {
      my_stepper.step(1);
      current_step++;
    }
  }
  else {
    if (current_step > min_step) {
      my_stepper.step(-1);
      current_step--;
    }
  }
}
