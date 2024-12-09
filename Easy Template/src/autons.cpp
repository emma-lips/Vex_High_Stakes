#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 70;
const int SWING_SPEED = 90;

//ALSO FOR RIGHT RED

const double RIGHTblueback = -24.5;
const double RIGHTblueturn = -30;
const double RIGHTblueback2 = -15;
const int slow_speed = 60;
const int delay_1 = 800; //While dropping preload
const double RIGHTblueturn2 = -90; //Turning to direction of first donut
const double RIGHTblueforward = 20;
const int delay_2 = 1000;
//For donut side
const double RIGHTblueturn3 = -170;
const double RIGHTblueforward2 = 14;
const int delay_3 = 2500;
const int delay_3b = 500;
const int delay_3c = 2500;
//Add on for mogo side
const double RIGHTblueturn3b = 63.43;
const double RIGHTblueforward2b = 53;
const double RIGHTblueback3b = -6;

//ALSO FOR LEFT BLUE

const double LEFTredback = -25;
const double LEFTredturn = 30;
const double LEFTredback2 = -15;
//const int slow_speed = 60;
//const int delay_1 = 800;
const double LEFTredturn2 = 90;
const double LEFTredforward = 20;
//const int delay_2 = 1800;
const double LEFTredturn3 = 170; //turn towards stack of 8 donuts
const double LEFTredforward2 = 14;
const double LEFTredturn3b = -66; //Turn towards second donut
const double LEFTredforward2b = 53;
const double LEFTredback3b = -6;
//const int delay_3 = 2500;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(20, 0, 100);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}

//Nolanverysigma(right blue)

void sigma_moderightblue() {

  chassis.pid_drive_set(RIGHTblueback, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(RIGHTblueturn, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTblueback2, slow_speed, true);
  chassis.pid_wait();

  clamp1.extend();
  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_1);
  setIntake(0);

  chassis.pid_turn_set(RIGHTblueturn2, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTblueforward, DRIVE_SPEED);
  chassis.pid_wait();

//Picking up first donut

  setIntake(127);
  pros::delay(delay_2);
  setIntake(0);

  chassis.pid_turn_set(RIGHTblueturn3, TURN_SPEED);
  chassis.pid_wait();

//Right blue forward towards four donuts

  chassis.pid_drive_set(RIGHTblueforward2, DRIVE_SPEED);
    chassis.pid_wait_until(6_in);
  setIntake(127);
  pros::delay(delay_2);
  setIntake(0);

  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_3);
  setIntake(0);

  chassis.pid_drive_set(RIGHTblueback2, DRIVE_SPEED);
  chassis.pid_wait();
}


//Nolanverysigma(right red)

void sigma_moderightred() {

  chassis.pid_drive_set(RIGHTblueback, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(RIGHTblueturn, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTblueback2, slow_speed, true);
  chassis.pid_wait();

  clamp1.extend();
  chassis.pid_wait();

//Drop Preload

  setIntake(127);
  pros::delay(delay_1);
  setIntake(0);

  chassis.pid_turn_set(RIGHTblueturn2, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTblueforward, DRIVE_SPEED);
  chassis.pid_wait();

//Pick up first floor donut

  setIntake(127);
  pros::delay(delay_2);
  setIntake(0);

//Add on
  chassis.pid_turn_set(RIGHTblueturn3b, TURN_SPEED);
  
  lifter.extend();

  chassis.pid_drive_set(RIGHTblueforward2b, DRIVE_SPEED);
  chassis.pid_wait_until(6_in);
  setIntake(127);
  pros::delay(delay_2);
  setIntake(0);

  chassis.pid_wait();

  lifter.retract();

  //Pick up second raised donut

  setIntake(127);
  pros::delay(delay_3b);
  setIntake(0);

//Move back to avoid picking BLUE

  chassis.pid_drive_set(RIGHTblueback3b, DRIVE_SPEED);
  chassis.pid_wait();

//Continue Intake

  setIntake(127);
  pros::delay(delay_3c);
  setIntake(0);

  
}



//Emmaverysigma(left red)

void sigma_modeleftred() {

    chassis.pid_drive_set(LEFTredback, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(LEFTredturn, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(LEFTredback2, slow_speed, true);
  chassis.pid_wait();

  clamp1.extend();
  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_1);
  setIntake(0);

  chassis.pid_turn_set(LEFTredturn2, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(LEFTredforward, DRIVE_SPEED);
  chassis.pid_wait();

//Picking up first donut

  setIntake(127);
  pros::delay(delay_2);
  setIntake(0);

  chassis.pid_turn_set(LEFTredturn3, TURN_SPEED);
  chassis.pid_wait();

//Right blue forward towards four donuts

  chassis.pid_drive_set(LEFTredforward2, DRIVE_SPEED);;
    chassis.pid_wait_until(6_in);
  setIntake(127);
  pros::delay(delay_2);
  setIntake(0);

  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_3);
  setIntake(0);

//move away from auton line
  chassis.pid_drive_set(LEFTredback2, DRIVE_SPEED);
}

//Emmaverysigma(left blue)

void sigma_modeleftblue() {

    chassis.pid_drive_set(LEFTredback, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(LEFTredturn, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(LEFTredback2, slow_speed, true);
  chassis.pid_wait();

  clamp1.extend();
  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_1);
  setIntake(0);

  chassis.pid_turn_set(LEFTredturn2, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(LEFTredforward, DRIVE_SPEED);
  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_2);
  setIntake(0);

//Add on
  chassis.pid_turn_set(LEFTredturn3b, TURN_SPEED);
  
  lifter.extend();

  chassis.pid_drive_set(LEFTredforward2b, DRIVE_SPEED);
  chassis.pid_wait_until(6_in);
  setIntake(127);
  pros::delay(delay_2);
  setIntake(0);

  chassis.pid_wait();

  lifter.retract();

  //Pick up second raised donut
  setIntake(127);
  pros::delay(delay_3b);
  setIntake(0);

  chassis.pid_drive_set(LEFTredback3b, DRIVE_SPEED);
  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_3c);
  setIntake(0);

  
}


///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater than the slew distance + a few inches

  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Turn Example
///
void turn_example() {
  // The first parameter is the target in degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(24_in, 30, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(-24_in, 30, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is the target in degrees
  // The third parameter is the speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Motion Chaining
///
void motion_chaining() {
  // Motion chaining is where motions all try to blend together instead of individual movements.
  // This works by exiting while the robot is still moving a little bit.
  // To use this, replace pid_wait with pid_wait_quick_chain.
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // Your final motion should still be a normal pid_wait
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backward
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If the robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, the robot will drive forward and turn 90 degrees.
// If interfered, the robot will drive forward and then attempt to drive backward.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

// . . .
// Make your own autonomous functions here!
// . . .