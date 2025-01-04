#include "main.h"

//for motors
extern pros::Motor intake11W(8,pros::v5::MotorGears::green);
// // for colour sorter
// extern pros::Optical colorDetector(18);
// // Vex V5 Distance Sensor (For detecting rings as they approach the top of the intake)
// //* Two sensors are being used due to the refresh rate on Vex V5 Optical Sensors.
// //* Optical sensors update at 100 Msec and Distance sensors update at ~50 msec
// extern pros::Distance ringDetector(4);
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
