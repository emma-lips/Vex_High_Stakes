#include "main.h"

extern bool isRed;

void lift_task();
void set_lift();
void lift_wait();

extern ez::PID liftPID;

extern pros::Rotation rotationSensor;
extern pros::Motor lb;

//for motors
extern pros::Motor intake11W;
extern pros::MotorGroup doinker5W;

//pneumatics
extern pros::adi::Pneumatics clamp1;

//pneumatics lifter
extern pros::adi::Pneumatics lifter;
