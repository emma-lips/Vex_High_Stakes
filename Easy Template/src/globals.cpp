#include "main.h"

//for motors
extern pros::Motor intake11W(8,pros::v5::MotorGears::green);
//for doinker
extern pros::MotorGroup doinker5W({17}, pros::v5::MotorGears::red);

//penumatics
pros::adi::Pneumatics clamp1('A', false);

//clamp1.extend();
//clamp1.retract();
//clamp1.toggle();
//clamp1.is_extended();
