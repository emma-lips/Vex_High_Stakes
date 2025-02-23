#include "main.h"


extern int target;
extern bool isRed;
extern bool wrongcolour;
void lift_task();
void set_lift();
void lift_wait();

// void intakecoloursort_task();
// void set_intake();

extern ez::PID intakePID;

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
