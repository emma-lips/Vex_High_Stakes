#include "main.h"

//for motors
extern pros::Motor intake11W(8,pros::v5::MotorGears::green);
//extern pros::MotorGroup intake5W({7,-9}, pros::v5::MotorGears::blue);

//penumatics
pros::adi::Pneumatics clamp1('A', false);

//clamp1.extend();
//clamp1.retract();
//clamp1.toggle();
//clamp1.is_extended();