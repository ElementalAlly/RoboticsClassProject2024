#include <Stepper.h>

int num_steps = 2038;
int speed = 10;

Stepper my_stepper = Stepper(num_steps, 4, 6, 5, 7);

double max = 1023.0;

int current;
int target;

int max_tick = 450;

double get_potentiometer() {
  return analogRead(A0) / max;
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  current = 0;
  target = 0;
  pinMode(A0, INPUT);
  my_stepper.setSpeed(speed);
}

void loop() {
  target = (int)(get_potentiometer() * max_tick);

  if (current > target) {
    my_stepper.step(-1);
    current--;
  }
  
  if (current < target) {
    my_stepper.step(1);
    current++;
  }
}
