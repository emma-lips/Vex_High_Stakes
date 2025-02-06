#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');

inline pros::Rotation rotationSensor(15);
inline pros::Motor lb(5);


inline void set_lift(int input) {
  lb.move(input);
}

inline ez::PID liftPID{0.5, 0, 0.5, 0, "Lift"};

inline void lift_wait() {
  while (liftPID.exit_condition({lb}, true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
}