#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 70;
const int SWING_SPEED = 90;
const int DRIVE_SPEED1 = 90;
//ALSO FOR RIGHT RED

const double RIGHTblueback = -23.25;// move backwards to mogo 
const double RIGHTblueturn = -30; // turn towards mogo 
const double RIGHTblueback2 = -15; // move to mogo
const int slow_speed = 60; // speed for clamping mogo
const int delay_1 = 800; //While dropping preload
const double RIGHTblueturn2 = -90; //Turning to direction of first donut
const double RIGHTblueforward = 25; // move to first donut
const int delay_2 = 1500; // intaking and dropping first donut
//For donut side(right blue(stack of 8 donuts)) 
const double RIGHTblueturn3 = -170; // turn towards second donut
const double RIGHTblueforward2 = 14; // move to second donut
const int delay_3 = 2500; // intake second donut
//Add on for mogo side(right red(donut in middle of spawn))
const double RIGHTblueturn3b = 70; // turn to second donut
const double RIGHTblueforward2b = 52; // move to second donut
const double RIGHTblueback3b = -6; // move back after intaking second donut
const int delay_3b = 350; // intake at first to intake second donut
const int delay_3c = 2500; // drop second donut on stake

//ALSO FOR LEFT BLUE

const double LEFTredback = -23.75; // move backwards to mogo
const double LEFTredturn = 30; // turn to mogo
const double LEFTredback2 = -15; // pick up and clamp mogo
//const int slow_speed = 60;
//const int delay_1 = 800;
const double LEFTredturn2 = 90; // turn to first donut
const double LEFTredforward = 25; // move to first donut
//const int delay_2 = 1800;

// donut side

const double LEFTredturn3 = 180; //turn towards stack of 8 donuts on left red
const double LEFTredforward2 = 14; // move to second donut on left red

//mogo side

const double LEFTredturn3b = -70; //Turn towards second donut on left blue
const double LEFTredforward2b = 52; // move to second donut on left blue
const double LEFTredback3b = -6; // move back as to not pick up red donut on left blue
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

  chassis.pid_drive_set(RIGHTblueback, DRIVE_SPEED); // move back towards mogo
  chassis.pid_wait();

  chassis.pid_turn_set(RIGHTblueturn, TURN_SPEED); // turn toward mogo
  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTblueback2, slow_speed, true); // move slowly to clamp mogo
  chassis.pid_wait();

  clamp1.extend(); // clamp mogo
  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_1); // intake preload
  setIntake(0);

  chassis.pid_turn_set(RIGHTblueturn2, TURN_SPEED); // turn to first donut
  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTblueforward, DRIVE_SPEED); // move to first donut
  chassis.pid_wait();

//Picking up first donut

  setIntake(127);
  pros::delay(delay_2); // intake first donut
  setIntake(0);

  chassis.pid_turn_set(RIGHTblueturn3, TURN_SPEED); // turn to stack of 8 donuts
  chassis.pid_wait();

//Right blue forward towards eight donuts

  chassis.pid_drive_set(RIGHTblueforward2, DRIVE_SPEED); // move to second donut
    chassis.pid_wait_until(6_in);
  setIntake(127);
  pros::delay(delay_2); // intake the second donut
  setIntake(0);

  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_3); // continue intaking second donut?
  setIntake(0);

  chassis.pid_drive_set(RIGHTblueback2, DRIVE_SPEED); // move back to avoid autonomous line
  chassis.pid_wait();
}


//Nolanverysigma(right red)

void sigma_moderightred() {

  chassis.pid_drive_set(RIGHTblueback, DRIVE_SPEED); // move backwards to mogo
  chassis.pid_wait();

  chassis.pid_turn_set(RIGHTblueturn, TURN_SPEED); // turn to mogo
  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTblueback2, slow_speed, true); // go slow into mogo
  chassis.pid_wait();

  clamp1.extend(); // clamp mogo
  chassis.pid_wait();

//Drop Preload

  setIntake(127);
  pros::delay(delay_1); // load preload
  setIntake(0);

  chassis.pid_turn_set(RIGHTblueturn2, TURN_SPEED); // turn to first donut
  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTblueforward, DRIVE_SPEED);// move to first donut
  chassis.pid_wait();

//Pick up first floor donut

  setIntake(127);
  pros::delay(delay_2); // intake first donut
  setIntake(0);

//Add on
  chassis.pid_turn_set(RIGHTblueturn3b, TURN_SPEED); // turn to second donut in spawn
  
  // lifter.extend();

  chassis.pid_drive_set(RIGHTblueforward2b, DRIVE_SPEED); // move to second donut
  chassis.pid_wait_until(20_in);
  lifter.extend(); // extend lifter to get over tall donut
  chassis.pid_wait_until(47_in);
  lifter.retract(); // let down lifter to intake second donut
  setIntake(127); // pick up second donut
  pros::delay(600);
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

    chassis.pid_drive_set(LEFTredback, DRIVE_SPEED); // move back to mogo
  chassis.pid_wait();

  chassis.pid_turn_set(LEFTredturn, TURN_SPEED); // turn towards mogo
  chassis.pid_wait();

  chassis.pid_drive_set(LEFTredback2, slow_speed, true); // move to mogo slowly
  chassis.pid_wait();

  clamp1.extend(); // clamp mogo mech
  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_1); // load preload
  setIntake(0);

  chassis.pid_turn_set(LEFTredturn2, TURN_SPEED); // turn towards first donut 
  chassis.pid_wait();

  chassis.pid_drive_set(LEFTredforward, DRIVE_SPEED); // move towards first donut
  chassis.pid_wait();

//Picking up first donut

  setIntake(127);
  pros::delay(delay_2); // pick up first donut
  setIntake(0);

  chassis.pid_turn_set(LEFTredturn3, TURN_SPEED); // turn to stack of 8 donuts
  chassis.pid_wait();

//left red forward towards eight donuts

  chassis.pid_drive_set(LEFTredforward2, DRIVE_SPEED); // move to second donut
  chassis.pid_wait_until(6_in);
  setIntake(127); // intake second donut
  pros::delay(delay_2);
  setIntake(0);

  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_3); // finish off second donut just in case
  setIntake(0);

//move away from auton line
  chassis.pid_drive_set(LEFTredback2, DRIVE_SPEED);
  chassis.pid_wait();

  setIntake(127);
  pros::delay(500); // just in case again?
  setIntake(0);

}

//Emmaverysigma(left blue)

void sigma_modeleftblue() {

    chassis.pid_drive_set(LEFTredback, DRIVE_SPEED); // move to mogo 
  chassis.pid_wait();

  chassis.pid_turn_set(LEFTredturn, TURN_SPEED); // turn to mogo
  chassis.pid_wait();

  chassis.pid_drive_set(LEFTredback2, slow_speed, true); // move slowly to mogo
  chassis.pid_wait();

  clamp1.extend(); // clamp mogo mech
  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_1); // intake preload
  setIntake(0);

  chassis.pid_turn_set(LEFTredturn2, TURN_SPEED); // turn to first donut
  chassis.pid_wait();

  chassis.pid_drive_set(LEFTredforward, DRIVE_SPEED); // move to first donut
  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_2); // intake first donut
  setIntake(0);

//Add on
  chassis.pid_turn_set(LEFTredturn3b, TURN_SPEED); // turn to raised donut in spawn

  //lifter.extend();

  chassis.pid_drive_set(LEFTredforward2b, DRIVE_SPEED); // move towards raised second donut in spawn
  chassis.pid_wait_until(5_in);
  lifter.extend(); // extend lifter to get over raised second donut
  chassis.pid_wait_until(47_in);
  lifter.retract(); // let down lifter to intake raised second donut
  setIntake(127);
  pros::delay(600); // pick up second raised donut
  setIntake(0);
  chassis.pid_wait();

  // Pick up second raised donut
  // setIntake(127);
  // pros::delay(delay_3b);
  // setIntake(0);

  chassis.pid_drive_set(LEFTredback3b, DRIVE_SPEED); // move back and avoid picking up red donut
  chassis.pid_wait();

  setIntake(127);
  pros::delay(delay_3c); // load second donut onto stake
  setIntake(0);

  chassis.pid_drive_set(-10, slow_speed); // shake second donut onto stake just in case
  chassis.pid_wait();

  
}

const double robotskillsback = -13.5; // go backwards
const double robotskillsturn = -90; // turn to stake
const double robotskillsback2 = -20.5; // move to stake
const double robotskillsturn2 = -185; // turn to first donut
const double robotskillsforward = 23; // move to first/second/third donut
const double robotskillsturnb = -85; //turn to second donut relative turn
const double robotskillsturn3 = -0; //turn towards 3rd donut
const double robotskillsforward2 = 8; // move to 4th donut
const double robotskillsback3 = -3; // move back to not hit wall
const double robotskillsturn4 = 130; //turn to 5th donut
const double robotskillsforward3 = 11; // drive forward and secure 5th donut

const double robotskillsintakeback = -80; // move intake back as to not jam donut
const double robotskillsturn5 = -150; // turn to corner
const double robotskillsback4 = -11; // back into corner
const double robotskillsforward4 = 5; // get away from mogo

//nolansupersigmarobotautonskills

void sigma_robotskills() {

  //Starting (backing up)
  chassis.pid_drive_set(robotskillsback, DRIVE_SPEED);
  chassis.pid_wait();

  //Turn towards stake
  chassis.pid_turn_set(robotskillsturn, TURN_SPEED);
  chassis.pid_wait();

  //Slowly move towards stake
  chassis.pid_drive_set(robotskillsback2, slow_speed);
  chassis.pid_wait_until(18);
  //Secure stake
  clamp1.extend();
  chassis.pid_wait();


  //Turning towards 1st donut
  chassis.pid_turn_set(robotskillsturn2, TURN_SPEED);
  chassis.pid_wait();

  //Drives towards 1st donut and secures preload and 1st donut
  chassis.pid_drive_set(robotskillsforward, DRIVE_SPEED);
  chassis.pid_wait_until(16);
  setIntake(127);
  //pros::delay(delay_3c);
  chassis.pid_wait();
  pros::delay(delay_3c);
  
  //Turn towards 2nd donut
  chassis.pid_turn_relative_set(robotskillsturnb, TURN_SPEED);
  chassis.pid_wait();

  //Forward towards 2nd donut
  chassis.pid_drive_set(robotskillsforward, DRIVE_SPEED);
  chassis.pid_wait_until(16);
  //setIntake(127);
  //pros::delay(delay_3c);
  chassis.pid_wait();
  pros::delay(delay_3c);

  //Turn towards 3rd donut
  chassis.pid_turn_set(robotskillsturn3, TURN_SPEED);
  chassis.pid_wait();

  //Drive forward to 3rd and 4th donut
  chassis.pid_drive_set(robotskillsforward, DRIVE_SPEED1);
  chassis.pid_wait_until(16);
  //setIntake(127);
  //pros::delay(delay_3c);
  chassis.pid_wait();

  //Moving to 4th donut
  chassis.pid_drive_set(robotskillsforward2, DRIVE_SPEED1);
  chassis.pid_wait();

  // go backwards to not hit the wall
  chassis.pid_drive_set(robotskillsback3, slow_speed);

  //Turn to 5th donut
  chassis.pid_turn_set(robotskillsturn4, TURN_SPEED);
  chassis.pid_wait();

  //Drive forward and secures 5th donut
  chassis.pid_drive_set(robotskillsforward3, DRIVE_SPEED1);
  chassis.pid_wait_until(10);
  //pros::delay(delay_3c);
  chassis.pid_wait();
  pros::delay(delay_3c);

  setIntake(0);
  chassis.pid_wait();

  // roll intake back so we dont hook onto donut on stake
  setIntake(robotskillsintakeback);
  pros::delay(500);
  setIntake(0);

  // turn before backing up into corner
  chassis.pid_turn_set(robotskillsturn5, TURN_SPEED);
  chassis.pid_wait();

  // back into corner
  chassis.pid_drive_set(robotskillsback4, DRIVE_SPEED);
  chassis.pid_wait();

  // let it go
  clamp1.retract();
  pros::delay(1000);

  // move forward after backing into corner
  chassis.pid_drive_set(robotskillsforward4, DRIVE_SPEED);
  chassis.pid_wait();

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