#include "main.h"


extern pros::Rotation rotationSensor(15);
extern pros::Motor lb(5);

void set_lift(int input) {
  lb.move(input);
}

ez::PID liftPID{0.5, 0, 0.5, 0, "Lift"};

void lift_task() {
  pros::delay(2000);  // Set EZ-Template calibrate before this function starts running
  while (true) {
    set_lift(liftPID.compute(lb.get_position()));

    pros::delay(ez::util::DELAY_TIME);
  }
}



void lift_wait() {
  while (liftPID.exit_condition({lb}, true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
}


//for motors
extern pros::Motor intake11W(8,pros::v5::MotorGears::green);
// // for colour sorter
// extern pros::Optical colorDetector(18);
// // Vex V5 Distance Sensor (For detecting rings as they approach the top of the intake)
// //* Two sensors are being used due to the refresh rate on Vex V5 Optical Sensors.
// //* Optical sensors update at 100 Msec and Distance sensors update at ~50 msec
// extern pros::Distance ringDetector(4);
//for doinker
extern pros::MotorGroup doinker5W({17}, pros::v5::MotorGears::green);

//pneumatics
pros::adi::Pneumatics clamp1('A', false);

//pneumatics intake lift
pros::adi::Pneumatics lifter('H', false);

//clamp1.extend();
//clamp1.retract();
//clamp1.toggle();
//clamp1.is_extended();
