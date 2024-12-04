#include "main.h"

//for motors
extern pros::Motor intake11W(8,pros::v5::MotorGears::green);
//for doinker
extern pros::MotorGroup doinker5W({17}, pros::v5::MotorGears::red);

//pneumatics
pros::adi::Pneumatics clamp1('A', false);

//pneumatics intake lift
pros::adi::Pneumatics lifter('H', false);

//clamp1.extend();
//clamp1.retract();
//clamp1.toggle();
//clamp1.is_extended();
