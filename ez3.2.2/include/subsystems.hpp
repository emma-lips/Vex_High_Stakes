#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');

inline pros::Rotation rotationSensor(15);
inline pros::Motor lb(5);


inline const int numStates = 4;
//These are in degrees
inline int states[numStates] = {0, 575, 575, 3400};
inline int currState = 0;
inline int target = 0;

inline void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    }
    // if (currState == 2) {
    //   setIntake(-50);
    //   pros::delay(75);
    //   setIntake(0);
    // }

    target = states[currState];
}

inline void set_lift(int input) {
  lb.move(input);
}

inline ez::PID liftPID{0.5, 0, 0.5, 0, "Lift"};

inline void lift_wait() {
  while (liftPID.exit_condition({lb}, true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
}