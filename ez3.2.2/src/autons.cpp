
#include "main.h"
#include "globals.hpp"
/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////


bool isRed = true;
// These are out of 127
const int DRIVE_SPEED = 110;
const int FULL_SPEED = 127;
const int TURN_SPEED = 70;
const int TURN_SPEED2 = 60;
const int SWING_SPEED = 90;
const int DRIVE_SPEED1 = 90;
//ALSO FOR RIGHT RED move to mogo
const int slow_speed = 60; // speed for clamping mogo
const int superslow_speed = 20;
const int delay_1 = 870; //While dropping preload

const double RIGHTblueback = -22.75;// move backwards to mogo 
const double RIGHTblueturn = -30; // turn towards mogo 
const double RIGHTblueback2 = -15; // / move to mogo (group of 8)
const double RIGHTblueturn2 = -95; //Turning to direction of first donut (preload does not count)
const double RIGHTblueforward = 23; // move to first donut
const int delay_2 = 2000; // intaking and dropping first donut

//For donut side(right blue(stack of 8 donuts)) 
const double RIGHTblueturn3 = -175; // turn towards second donut
const double RIGHTblueforward2 = 9; // move towards second donut
const int delay_3 = 1500; // intake second donut

//Add on for mogo side(right red(donut in middle of spawn))
const double RIGHTblueturn3b = 65; // turn to second donut
const double RIGHTblueforward2b = 50; // move to second donut
const double RIGHTblueback3b = -6; // move back after intaking second donut
const int delay_3b = 350; // intake at first to intake second donut
const int delay_3c = 2500; // drop second donut on stake

//continue RIGHTblue
const double RIGHTbluebyeautonline = -2; //move away from auton line after second donut
const double RIGHTblueturn4 = -205; //turn to third donut (beside second donut)
const double RIGHTblueforward4 = 5; // move towards third donut
const double RIGHTblueback4 = -5; // move away from auton line
const double RIGHTblueturn5 = 11; // turn to negative corner
const double RIGHTblueforward5 = 38; // go to negative corner

//LEFT RED AND ALSO FOR LEFT BLUE

const double LEFTredback = -22.75; // move backwards to mogo
const double LEFTredturn = 30; // turn to mogo
const double LEFTredback2 = -15; // pick up and clamp mogo
//const int slow_speed = 60;
//const int delay_1 = 800;
const double LEFTredturn2 = 90; // turn to first donut (preload does not count)
const double LEFTredforward = 23; // move to first donut
//const int delay_2 = 1800;

// donut side

const double LEFTredturn3 = 175; //turn towards stack of 8 donuts on left red
const double LEFTredforward2 = 11; // move to second donut on left red

//mogo side aka LEFT blue

const double LEFTredturn3b = -68; //Turn towards second donut on left blue
const double LEFTredforward2b = 50; // move to second donut on left blue
const double LEFTredback3b = -6; // move back as to not pick up red donut on left blue
//const int delay_3 = 2500;

//continue LEFTred
const double LEFTredbyeautonline = -2; //move away from auton line after second donut
const double LEFTredturn4 = 195; //turn to third donut (beside second donut)
const double LEFTredforward4 = 6.5; // move towards third donut
const double LEFTredback4 = -5; // move away from auton line
const double LEFTredturn5 = 11; // turn to negative corner
const double LEFTredforward5 = 35; // go to negative corner

//Version 2 Left Blue


///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(20.0, 0.0, 100.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(3.0, 0.05, 20.0, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions

  // Exit conditions
  // chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  // chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  // chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 150_ms, 150_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 150_ms, 150_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 150_ms, 150_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

// IT WORKSS AAHAHH
void worldssixdonutsrightrednoalliance() {
  isRed = true;
  chassis.drive_angle_set(31.89);
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);

  chassis.pid_turn_set(26, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-23, 70);//CHANGE IF SWING NO HIT
  chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();
  pros::delay(300);
  clamp1.extend(); //Clamp stake
  chassis.pid_wait_quick_chain();
  setIntake(127);

  chassis.pid_swing_set(ez::LEFT_SWING, 96_deg, 127, 45);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(1, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  pros::delay(200);

  chassis.pid_turn_set(-108, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(43, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0, slow_speed);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(29, FULL_SPEED);
  chassis.pid_wait_until(13);
  setIntake(-127);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-0.4, 40);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_turn_set(-45, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  setIntake(127); //Intake donut 5
  chassis.pid_drive_set(19.5, 100); //Drive into corner
  chassis.pid_wait_quick_chain();
  setIntake(127); //Intake donut 5
  pros::delay(250);

  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(750);
  chassis.pid_drive_set(5, 100); //Get 6 donut
  chassis.pid_wait_quick_chain();

  pros::delay(240);

  chassis.pid_turn_set(120, 100); //Turn to ladder
  chassis.pid_wait();


  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  chassis.pid_drive_set(50, FULL_SPEED); //Drive to ladder
  chassis.pid_wait();


}

void worldssixdonutsrightredalliance() {
  isRed = true;
  chassis.drive_angle_set(31.89);
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  liftPID.constants_set(0.06, 0, 0.06);
  // ez::PID liftPID{0.1, 0, 0.1, 0, "Lift"}; //Put donut (preload) on allince stake
  chassis.pid_drive_set(2, 60);
  chassis.pid_wait_quick_chain();

  target = 1500;
  pros::delay(700);
  chassis.pid_drive_set(-2, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  liftPID.constants_set(0.2, 0, 0.2);

  chassis.pid_turn_set(26, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-23, 70);//CHANGE IF SWING NO HIT
  chassis.pid_wait_until(21);
  clamp1.extend();
  target = 725;
  chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();

  setIntake(127);

  chassis.pid_swing_set(ez::LEFT_SWING, 96_deg, 127, 45);
  target = -270;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(1, FULL_SPEED);
  lb.tare_position();
  target = 0;
  chassis.pid_wait_quick_chain();

  pros::delay(200);

  chassis.pid_turn_set(-111, 80);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(43, FULL_SPEED, true);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0, slow_speed);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(23.75, FULL_SPEED);
  chassis.pid_wait_until(13);
  setIntake(-127);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-1, 40);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(8, FULL_SPEED); //Drive into corner
  chassis.pid_wait_quick_chain();

  setIntake(127); //Intake donut 5

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 600_ms, 600_ms);
  chassis.pid_drive_set(11.5, 110);
  chassis.pid_wait_quick_chain();
  pros::delay(700);

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 300_ms, 300_ms);
  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(750);
  chassis.pid_drive_set(5, 100); //Get 6 donut
  chassis.pid_wait_quick_chain();

  pros::delay(240);

  chassis.pid_turn_set(120, 80); //Turn to ladder
  chassis.pid_wait();


  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  chassis.pid_drive_set(46, FULL_SPEED); //Drive to ladder
  chassis.pid_wait();

  target = 1400;


}

void worldssixdonutsrightredelims() {
  isRed = true;
  chassis.drive_angle_set(31.89);
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  liftPID.constants_set(0.06, 0, 0.06);
  // ez::PID liftPID{0.1, 0, 0.1, 0, "Lift"}; //Put donut (preload) on allince stake
  chassis.pid_drive_set(2, 60);
  chassis.pid_wait_quick_chain();

  target = 1500;
  pros::delay(700);
  chassis.pid_drive_set(-2, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  liftPID.constants_set(0.2, 0, 0.2);

  chassis.pid_turn_set(26, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-23, 70);//CHANGE IF SWING NO HIT
  chassis.pid_wait_until(21);
  clamp1.extend();
  target = 725;
  chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();

  setIntake(127);

  chassis.pid_swing_set(ez::LEFT_SWING, 96_deg, 127, 45);
  target = -270;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(1, FULL_SPEED);
  lb.tare_position();
  target = 0;
  chassis.pid_wait_quick_chain();

  pros::delay(200);

  chassis.pid_turn_set(-111, 80);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(43, FULL_SPEED, true);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0, slow_speed);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(23.75, FULL_SPEED);
  chassis.pid_wait_until(13);
  setIntake(-127);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-1, 40);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(8, FULL_SPEED); //Drive into corner
  chassis.pid_wait_quick_chain();

  setIntake(127); //Intake donut 5

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 600_ms, 600_ms);
  chassis.pid_drive_set(11.5, 110);
  chassis.pid_wait_quick_chain();
  pros::delay(700);

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 300_ms, 300_ms);
  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(750);
  chassis.pid_drive_set(5, 100); //Get 6 donut
  chassis.pid_wait_quick_chain();

  doinkerright.extend();

  pros::delay(240);

  chassis.pid_turn_set(135, 80); //clear corner
  chassis.pid_wait_until(-100);
  doinkerright.retract();
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-4);
  chassis.pid_wait_quick_chain();

  clamp1.retract();







}

void worldssixdonutsleftblueelims() {
  isRed = false;
  chassis.drive_angle_set(-31.89);
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  liftPID.constants_set(0.06, 0, 0.06);
  // ez::PID liftPID{0.1, 0, 0.1, 0, "Lift"}; //Put donut (preload) on allince stake
  chassis.pid_drive_set(2, 60);
  chassis.pid_wait_quick_chain();

  target = 1500;
  pros::delay(700);
  chassis.pid_drive_set(-2, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  liftPID.constants_set(0.2, 0, 0.2);

  chassis.pid_turn_set(-26, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-23, 70);//CHANGE IF SWING NO HIT
  chassis.pid_wait_until(21);
  clamp1.extend();
  target = 725;
  chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();

  setIntake(127);

  chassis.pid_swing_set(ez::RIGHT_SWING, -96_deg, 127, 45);
  target = -270;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(1, FULL_SPEED);
  lb.tare_position();
  target = 0;
  chassis.pid_wait_quick_chain();

  pros::delay(200);

  chassis.pid_turn_set(111, 80);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(43, FULL_SPEED, true);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-0, slow_speed);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(24.25, FULL_SPEED);
  chassis.pid_wait_until(13);
  setIntake(-127);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-1, 40);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(45, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(8, FULL_SPEED); //Drive into corner
  chassis.pid_wait_quick_chain();

  setIntake(127); //Intake donut 5

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 600_ms, 600_ms);
  chassis.pid_drive_set(15, 110);
  chassis.pid_wait_quick_chain();
  pros::delay(700);

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 300_ms, 300_ms);
  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(750);
  chassis.pid_drive_set(5, 100); //Get 6 donut
  chassis.pid_wait_quick_chain();

  doinkerright.extend();

  pros::delay(240);

  chassis.pid_turn_set(-135, 80); //clear corner
  chassis.pid_wait_until(-90);
  doinkerright.retract();
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-4);
  chassis.pid_wait_quick_chain();

  clamp1.retract();


}

void worldssixdonutsleftbluealliancetransposed() {
  isRed = false;
  chassis.drive_angle_set(-31.89);
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  liftPID.constants_set(0.06, 0, 0.06);
  // ez::PID liftPID{0.1, 0, 0.1, 0, "Lift"}; //Put donut (preload) on allince stake
  chassis.pid_drive_set(2, 60);
  chassis.pid_wait_quick_chain();

  target = 1500;
  pros::delay(700);
  chassis.pid_drive_set(-2, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  liftPID.constants_set(0.2, 0, 0.2);

  chassis.pid_turn_set(-26, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-23, 70);//CHANGE IF SWING NO HIT
  chassis.pid_wait_until(21);
  clamp1.extend();
  target = 725;
  chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();

  setIntake(127);

  chassis.pid_swing_set(ez::RIGHT_SWING, -96_deg, 127, 45);
  target = -270;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(1, FULL_SPEED);
  lb.tare_position();
  target = 0;
  chassis.pid_wait_quick_chain();

  pros::delay(200);

  chassis.pid_turn_set(111, 80);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(43, FULL_SPEED, true);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-0, slow_speed);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(24.25, FULL_SPEED);
  chassis.pid_wait_until(13);
  setIntake(-127);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-1, 40);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(45, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(8, FULL_SPEED); //Drive into corner
  chassis.pid_wait_quick_chain();

  setIntake(127); //Intake donut 5

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 600_ms, 600_ms);
  chassis.pid_drive_set(15, 110);
  chassis.pid_wait_quick_chain();
  pros::delay(700);

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 300_ms, 300_ms);
  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(750);
  chassis.pid_drive_set(5, 100); //Get 6 donut
  chassis.pid_wait_quick_chain();

  pros::delay(240);

  chassis.pid_turn_set(-120, 80); //Turn to ladder
  chassis.pid_wait();


  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  chassis.pid_drive_set(46, FULL_SPEED); //Drive to ladder
  chassis.pid_wait();

  target = 1400;


}
// IT WORKSS AAHAHH
void worldssixdonutsleftbluenoalliance() {
  isRed = false;
  chassis.drive_angle_set(-31.89);
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);

  chassis.pid_turn_set(-26, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-23, 70);//CHANGE IF SWING NO HIT
  chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();
  pros::delay(300);
  clamp1.extend(); //Clamp stake
  chassis.pid_wait_quick_chain();
  setIntake(127);

  chassis.pid_swing_set(ez::RIGHT_SWING, -96_deg, 127, 45);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(1, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  pros::delay(200);

  chassis.pid_turn_set(108, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(43, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-0, slow_speed);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(28.5, FULL_SPEED);
  chassis.pid_wait_until(13);
  setIntake(-127);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-1.4, 40);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 600_ms, 600_ms);
  chassis.pid_turn_set(45, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  setIntake(127); //Intake donut 5
  chassis.pid_drive_set(24, 100); //Drive into corner
  chassis.pid_wait_quick_chain();
  setIntake(127); //Intake donut 5
  pros::delay(250);

  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(750);
  chassis.pid_drive_set(5, 100); //Get 6 donut
  chassis.pid_wait_quick_chain();

  pros::delay(240);

  chassis.pid_turn_set(-120, 100); //Turn to ladder
  chassis.pid_wait();


  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  chassis.pid_drive_set(50, FULL_SPEED); //Drive to ladder
  chassis.pid_wait();


}

void worldssixdonutsleftblue() {
  isRed = false;
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  chassis.drive_angle_set(-31.89);
  liftPID.constants_set(0.06, 0, 0.06);
  // ez::PID liftPID{0.1, 0, 0.1, 0, "Lift"}; //Put donut (preload) on allince stake
  chassis.pid_drive_set(2, 60);
  chassis.pid_wait_quick_chain();

  target = 1375;
  pros::delay(600);
  chassis.pid_drive_set(-4, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  liftPID.constants_set(0.2, 0, 0.2);



  chassis.pid_turn_set(-24, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-19, 70);
  target = 725;
  chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();
  pros::delay(300);
  clamp1.extend(); //Clamp stake
  chassis.pid_wait_quick_chain();

  setIntake(100);
}

void worldssixdonutsleftred() {
  isRed = true;
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  chassis.drive_angle_set(-31.89);
  liftPID.constants_set(0.06, 0, 0.06);
  // ez::PID liftPID{0.1, 0, 0.1, 0, "Lift"}; //Put donut (preload) on allince stake
  chassis.pid_drive_set(1.5, 60);
  chassis.pid_wait_quick_chain();

  target = 1400;
  pros::delay(700);
  chassis.pid_drive_set(-4, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  liftPID.constants_set(0.2, 0, 0.2);



  chassis.pid_turn_set(-23, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-22, 70);
  chassis.pid_wait_until(19);
  clamp1.extend();
  target = 725;
  chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();

  setIntake(127);

  chassis.pid_turn_set(135, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(16.5, FULL_SPEED); //Aquire 2 donut
  chassis.pid_wait_until(1);
  target = -170;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(4.5, slow_speed);
  lb.tare_position();
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(93, TURN_SPEED);
  target = 0;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(7, 90, true); // Get 3 donut (including preload)
  chassis.pid_wait_quick_chain();
  pros::delay(200);

  // chassis.pid_turn_set(135, TURN_SPEED);
  // chassis.pid_wait_quick_chain();

  chassis.pid_swing_set(ez::RIGHT_SWING, 135_deg, 127, 45);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(55, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  //Go towards 4th donut sole donut
  chassis.pid_drive_set(20, FULL_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-0, 85);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(18, FULL_SPEED);
  chassis.pid_wait_until(14);
  setIntake(0);
  chassis.pid_wait_quick_chain();


  chassis.pid_turn_set(46, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(8, FULL_SPEED); //Drive into corner
  chassis.pid_wait_quick_chain();

  setIntake(127); //Intake donut 5

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 600_ms, 600_ms);
  chassis.pid_drive_set(13, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  // chassis.pid_swing_set(ez::RIGHT_SWING, -50, 127, 0);
  // chassis.pid_wait();

  // chassis.pid_drive_set(5, slow_speed);
  // chassis.pid_wait();
  // // pros::delay(250);



  // pros::delay(3000);

  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(250);

  chassis.pid_drive_set(5, FULL_SPEED); //Get 6 donut
  chassis.pid_wait_quick_chain();

  pros::delay(240);

  chassis.pid_turn_set(-120, 100); //Turn to ladder
  chassis.pid_wait();

  chassis.pid_drive_set(50, FULL_SPEED); //Drive to ladder

  chassis.pid_wait();


  // rotationSensor.reset_position();
  lb.tare_position();
  target = 0;
}

void worldssixdonutsrightbluenoalliancefr() {
  isRed = false;
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  chassis.drive_angle_set(31.89);
  liftPID.constants_set(0.06, 0, 0.06);
  // ez::PID liftPID{0.1, 0, 0.1, 0, "Lift"}; //Put donut (preload) on allince stake
  chassis.pid_drive_set(1, 60);
  chassis.pid_wait_quick_chain();

  target = 900;
  pros::delay(300);
  chassis.pid_drive_set(-3, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  liftPID.constants_set(0.2, 0, 0.2);



  chassis.pid_turn_set(24, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-21.5, 70);
  chassis.pid_wait_until(-19);
  clamp1.extend(); //Clamp stake
  target = 725;
  chassis.pid_wait_quick_chain();
  pros::delay(300);
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();



  setIntake(127);

  chassis.pid_turn_set(-135, 70);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(19, FULL_SPEED); //Aquire 2 donut
  chassis.pid_wait_until(2);
  target = 0;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(4.5, slow_speed);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-93, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(7, 90, true); // Get 3 donut (including preload)
  chassis.pid_wait_quick_chain();
  pros::delay(200);

  // chassis.pid_turn_set(-135, TURN_SPEED);
  // chassis.pid_wait_quick_chain();

  chassis.pid_swing_set(ez::LEFT_SWING, -135_deg, 127, 45);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-5, 127);
  chassis.pid_wait_quick_chain();


  chassis.pid_turn_set(-85, 85);
  chassis.pid_wait_quick_chain();

  //Go towards 4th donut sole donut
  chassis.pid_drive_set(20, FULL_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0, 85);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(20.75, FULL_SPEED);
  chassis.pid_wait_until(14);
  setIntake(0);
  chassis.pid_wait_quick_chain();


  chassis.pid_turn_set(-46, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(8, FULL_SPEED); //Drive into corner
  chassis.pid_wait_quick_chain();

  setIntake(127); //Intake donut 5

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 600_ms, 600_ms);
  chassis.pid_drive_set(11.5, 110);
  chassis.pid_wait_quick_chain();

  // chassis.pid_swing_set(ez::RIGHT_SWING, -50, 127, 0);
  // chassis.pid_wait();

  // chassis.pid_drive_set(5, slow_speed);
  // chassis.pid_wait();
  // // pros::delay(250);



  // pros::delay(3000);

  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  pros::delay(500);

  chassis.pid_drive_set(5, FULL_SPEED); //Get 6 donut
  chassis.pid_wait_quick_chain();

  pros::delay(650);

  chassis.pid_turn_set(120, 100); //Turn to ladder
  chassis.pid_wait();

  chassis.pid_drive_set(50, FULL_SPEED); //Drive to ladder
  chassis.pid_wait_until(10);

  lb.tare_position();

}

void worldssixdonutsrightblue() {
  isRed = false;
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  chassis.drive_angle_set(31.89);
  liftPID.constants_set(0.06, 0, 0.06);
  // ez::PID liftPID{0.1, 0, 0.1, 0, "Lift"}; //Put donut (preload) on allince stake
  chassis.pid_drive_set(2, 60);
  chassis.pid_wait_quick_chain();

  target = 1500;
  pros::delay(700);
  chassis.pid_drive_set(-4, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  liftPID.constants_set(0.2, 0, 0.2);



  chassis.pid_turn_set(24, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-21.5, 70);
  chassis.pid_wait_until(-19);
  clamp1.extend(); //Clamp stake
  target = 725;
  chassis.pid_wait_quick_chain();
  pros::delay(300);
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();



  setIntake(127);

  chassis.pid_turn_set(-135, 85);
  target = -270;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(19, FULL_SPEED); //Aquire 2 donut
  chassis.pid_wait_until(2);
  lb.tare_position();
  target = 0;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(4.5, slow_speed);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-93, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(7, 90, true); // Get 3 donut (including preload)
  chassis.pid_wait_quick_chain();
  pros::delay(200);

  // chassis.pid_turn_set(-135, TURN_SPEED);
  // chassis.pid_wait_quick_chain();

  chassis.pid_swing_set(ez::LEFT_SWING, -135_deg, 127, 45);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-5, 127);
  chassis.pid_wait_quick_chain();


  chassis.pid_turn_set(-85, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  //Go towards 4th donut sole donut
  chassis.pid_drive_set(20, FULL_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0, 85);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(20.75, FULL_SPEED);
  chassis.pid_wait_until(14);
  setIntake(0);
  chassis.pid_wait_quick_chain();


  chassis.pid_turn_set(-46, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(8, FULL_SPEED); //Drive into corner
  chassis.pid_wait_quick_chain();

  setIntake(127); //Intake donut 5

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 600_ms, 600_ms);
  chassis.pid_drive_set(11.5, 110);
  chassis.pid_wait_quick_chain();

  // chassis.pid_swing_set(ez::RIGHT_SWING, -50, 127, 0);
  // chassis.pid_wait();

  // chassis.pid_drive_set(5, slow_speed);
  // chassis.pid_wait();
  // // pros::delay(250);



  // pros::delay(3000);

  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  pros::delay(500);

  chassis.pid_drive_set(5, FULL_SPEED); //Get 6 donut
  chassis.pid_wait_quick_chain();

  pros::delay(1000);

  chassis.pid_turn_set(120, 100); //Turn to ladder
  chassis.pid_wait();

  chassis.pid_drive_set(50, FULL_SPEED); //Drive to ladder
  chassis.pid_wait_until(10);

  lb.tare_position();
  target = 0;
  chassis.pid_wait();


  // rotationSensor.reset_position();


}

void worldssixdonutsrightblueelims() {
  isRed = false;
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  chassis.drive_angle_set(31.89);
  liftPID.constants_set(0.06, 0, 0.06);
  // ez::PID liftPID{0.1, 0, 0.1, 0, "Lift"}; //Put donut (preload) on allince stake
  chassis.pid_drive_set(2, 60);
  chassis.pid_wait_quick_chain();

  target = 1500;
  pros::delay(700);
  chassis.pid_drive_set(-4, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  liftPID.constants_set(0.2, 0, 0.2);



  chassis.pid_turn_set(24, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-21.5, 70);
  chassis.pid_wait_until(-19);
  clamp1.extend(); //Clamp stake
  target = 725;
  chassis.pid_wait_quick_chain();
  pros::delay(300);
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();



  setIntake(127);

  chassis.pid_turn_set(-135, 85);
  target = -270;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(19, FULL_SPEED); //Aquire 2 donut
  chassis.pid_wait_until(2);
  lb.tare_position();
  target = 0;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(4.5, 80);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-93, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(7, 100, true); // Get 3 donut (including preload)
  chassis.pid_wait_quick_chain();
  pros::delay(200);

  // chassis.pid_turn_set(-135, TURN_SPEED);
  // chassis.pid_wait_quick_chain();

  chassis.pid_swing_set(ez::LEFT_SWING, -135_deg, 127, 45);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-5, 127);
  chassis.pid_wait_quick_chain();


  chassis.pid_turn_set(-85, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  //Go towards 4th donut sole donut
  chassis.pid_drive_set(20, FULL_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0, 85);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(21.3, FULL_SPEED);
  chassis.pid_wait_until(14);
  setIntake(0);
  chassis.pid_wait_quick_chain();


  chassis.pid_turn_set(-46, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(8, FULL_SPEED); //Drive into corner
  chassis.pid_wait_quick_chain();

  setIntake(127); //Intake donut 5

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 600_ms, 600_ms);
  chassis.pid_drive_set(11.5, 110);
  chassis.pid_wait_quick_chain();

  // chassis.pid_swing_set(ez::RIGHT_SWING, -50, 127, 0);
  // chassis.pid_wait();

  // chassis.pid_drive_set(5, slow_speed);
  // chassis.pid_wait();
  // // pros::delay(250);



  // pros::delay(3000);

  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 200_ms, 200_ms);

  pros::delay(400);

  chassis.pid_drive_set(5, FULL_SPEED); //Get 6 donut
  chassis.pid_wait_quick_chain();

  pros::delay(600);

  chassis.pid_turn_set(103, 100); //Turn to ladder
  chassis.pid_wait();

  chassis.pid_drive_set(50, FULL_SPEED); //Drive to ladder
  chassis.pid_wait_until(10);

  lb.tare_position();
  target = 0;
  chassis.pid_wait();


  // rotationSensor.reset_position();


}



void worldssixdonutsleftredtransposed() {
  isRed = true;
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  chassis.drive_angle_set(-31.89);
  liftPID.constants_set(0.06, 0, 0.06);
  // ez::PID liftPID{0.1, 0, 0.1, 0, "Lift"}; //Put donut (preload) on allince stake
  chassis.pid_drive_set(2, 60);
  chassis.pid_wait_quick_chain();

  target = 1500;
  pros::delay(700);
  chassis.pid_drive_set(-4, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  liftPID.constants_set(0.2, 0, 0.2);



  chassis.pid_turn_set(-24, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-21.5, 70);
  chassis.pid_wait_until(-19);
  clamp1.extend(); //Clamp stake
  target = 725;
  chassis.pid_wait_quick_chain();
  pros::delay(300);
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();



  setIntake(127);

  chassis.pid_turn_set(135, 85);
  target = -270;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(19, FULL_SPEED); //Aquire 2 donut
  chassis.pid_wait_until(2);
  lb.tare_position();
  target = 0;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(4.5, slow_speed);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(93, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(7, 90, true); // Get 3 donut (including preload)
  chassis.pid_wait_quick_chain();
  pros::delay(200);

  // chassis.pid_turn_set(-135, TURN_SPEED);
  // chassis.pid_wait_quick_chain();

  chassis.pid_swing_set(ez::RIGHT_SWING, 135_deg, 127, 45);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-5, 127);
  chassis.pid_wait_quick_chain();


  chassis.pid_turn_set(85, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  //Go towards 4th donut sole donut
  chassis.pid_drive_set(20, FULL_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-0, 85);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(19.75, FULL_SPEED);
  chassis.pid_wait_until(14);
  setIntake(0);
  chassis.pid_wait_quick_chain();


  chassis.pid_turn_set(46, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(8, FULL_SPEED); //Drive into corner
  chassis.pid_wait_quick_chain();

  setIntake(127); //Intake donut 5

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 600_ms, 600_ms);
  chassis.pid_drive_set(13, 110);
  chassis.pid_wait_quick_chain();
  pros::delay(300);

  // chassis.pid_swing_set(ez::RIGHT_SWING, -50, 127, 0);
  // chassis.pid_wait();

  // chassis.pid_drive_set(5, slow_speed);
  // chassis.pid_wait();
  // // pros::delay(250);



  // pros::delay(3000);

  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  pros::delay(500);

  chassis.pid_drive_set(5, FULL_SPEED); //Get 6 donut
  chassis.pid_wait_quick_chain();

  pros::delay(650);

  chassis.pid_turn_set(-120, 100); //Turn to ladder
  chassis.pid_wait();

  chassis.pid_drive_set(50, FULL_SPEED); //Drive to ladder
  chassis.pid_wait_until(10);

  lb.tare_position();
  target = 0;
  chassis.pid_wait();


  // rotationSensor.reset_position();


}

void worldssixdonutsleftredelims() {
  isRed = true;
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  chassis.drive_angle_set(-31.89);
  liftPID.constants_set(0.06, 0, 0.06);
  // ez::PID liftPID{0.1, 0, 0.1, 0, "Lift"}; //Put donut (preload) on allince stake
  chassis.pid_drive_set(2, 60);
  chassis.pid_wait_quick_chain();

  target = 1500;
  pros::delay(700);
  chassis.pid_drive_set(-4, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  liftPID.constants_set(0.2, 0, 0.2);



  chassis.pid_turn_set(-24, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-21.5, 70);
  chassis.pid_wait_until(-19);
  clamp1.extend(); //Clamp stake
  target = 725;
  chassis.pid_wait_quick_chain();
  pros::delay(300);
  // chassis.pid_drive_set(-1.5, slow_speed);
  // chassis.pid_wait_quick_chain();



  setIntake(127);

  chassis.pid_turn_set(135, 85);
  target = -270;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(19, FULL_SPEED); //Aquire 2 donut
  chassis.pid_wait_until(2);
  lb.tare_position();
  target = 0;
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(4.5, slow_speed);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(93, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(7, 90, true); // Get 3 donut (including preload)
  chassis.pid_wait_quick_chain();
  pros::delay(200);

  // chassis.pid_turn_set(-135, TURN_SPEED);
  // chassis.pid_wait_quick_chain();

  chassis.pid_swing_set(ez::RIGHT_SWING, 135_deg, 127, 45);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-5, 127);
  chassis.pid_wait_quick_chain();


  chassis.pid_turn_set(85, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  //Go towards 4th donut sole donut
  chassis.pid_drive_set(20, FULL_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-0, 85);
  chassis.pid_wait_quick_chain();

  // Going straight towards corner
  chassis.pid_drive_set(19.75, FULL_SPEED);
  chassis.pid_wait_until(14);
  setIntake(0);
  chassis.pid_wait_quick_chain();


  chassis.pid_turn_set(46, FULL_SPEED); //Turn into corner
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(8, FULL_SPEED); //Drive into corner
  chassis.pid_wait_quick_chain();

  setIntake(127); //Intake donut 5

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 600_ms, 600_ms);
  chassis.pid_drive_set(13, 110);
  chassis.pid_wait_quick_chain();
  pros::delay(300);

  // chassis.pid_swing_set(ez::RIGHT_SWING, -50, 127, 0);
  // chassis.pid_wait();

  // chassis.pid_drive_set(5, slow_speed);
  // chassis.pid_wait();
  // // pros::delay(250);



  // pros::delay(3000);

  chassis.pid_drive_set(-10, FULL_SPEED);
  chassis.pid_wait_quick_chain();

  pros::delay(500);

  chassis.pid_drive_set(5, FULL_SPEED); //Get 6 donut
  chassis.pid_wait_quick_chain();

  pros::delay(650);

  chassis.pid_turn_set(-103, 100); //Turn to ladder
  chassis.pid_wait();

  chassis.pid_drive_set(50, FULL_SPEED); //Drive to ladder
  chassis.pid_wait_until(10);

  lb.tare_position();
  target = 0;
  chassis.pid_wait();


  // rotationSensor.reset_position();


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

///
// Odom Drive PID
///
void odom_drive_example() {
  // This works the same as pid_drive_set, but it uses odom instead!
  // You can replace pid_drive_set with pid_odom_set and your robot will
  // have better error correction.

  chassis.pid_odom_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit
///
void odom_pure_pursuit_example() {
  // Drive to 0, 30 and pass through 6, 10 and 0, 20 on the way, with slew
  chassis.pid_odom_set({{{6_in, 10_in}, fwd, DRIVE_SPEED},
                        {{0_in, 20_in}, fwd, DRIVE_SPEED},
                        {{0_in, 30_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait();

  // Drive to 0, 0 backwards
  chassis.pid_odom_set({{0_in, 0_in}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit Wait Until
///
void odom_pure_pursuit_wait_until_example() {
  chassis.pid_odom_set({{{0_in, 24_in}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait_until_index(1);  // Waits until the robot passes 12, 24
  // Intake.move(127);  // Set your intake to start moving once it passes through the second point in the index
  chassis.pid_wait();
  // Intake.move(0);  // Turn the intake off
}

///
// Odom Boomerang
///
void odom_boomerang_example() {
  chassis.pid_odom_set({{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                       true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Odom Boomerang Injected Pure Pursuit
///
void odom_boomerang_injected_pure_pursuit_example() {
  chassis.pid_odom_set({{{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Calculate the offsets of your tracking wheels
///
void measure_offsets() {
  // Number of times to test
  int iterations = 10;

  // Our final offsets
  double l_offset = 0.0, r_offset = 0.0, b_offset = 0.0, f_offset = 0.0;

  // Reset all trackers if they exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->reset();
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->reset();
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->reset();
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->reset();
  
  for (int i = 0; i < iterations; i++) {
    // Reset pid targets and get ready for running an auton
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    double imu_start = chassis.odom_theta_get();
    double target = i % 2 == 0 ? 90 : 270;  // Switch the turn target every run from 270 to 90

    // Turn to target at half power
    chassis.pid_turn_set(target, 63, ez::raw);
    chassis.pid_wait();
    pros::delay(250);

    // Calculate delta in angle
    double t_delta = util::to_rad(fabs(util::wrap_angle(chassis.odom_theta_get() - imu_start)));

    // Calculate delta in sensor values that exist
    double l_delta = chassis.odom_tracker_left != nullptr ? chassis.odom_tracker_left->get() : 0.0;
    double r_delta = chassis.odom_tracker_right != nullptr ? chassis.odom_tracker_right->get() : 0.0;
    double b_delta = chassis.odom_tracker_back != nullptr ? chassis.odom_tracker_back->get() : 0.0;
    double f_delta = chassis.odom_tracker_front != nullptr ? chassis.odom_tracker_front->get() : 0.0;

    // Calculate the radius that the robot traveled
    l_offset += l_delta / t_delta;
    r_offset += r_delta / t_delta;
    b_offset += b_delta / t_delta;
    f_offset += f_delta / t_delta;
  }

  // Average all offsets
  l_offset /= iterations;
  r_offset /= iterations;
  b_offset /= iterations;
  f_offset /= iterations;

  // Set new offsets to trackers that exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->distance_to_center_set(l_offset);
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->distance_to_center_set(r_offset);
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->distance_to_center_set(b_offset);
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->distance_to_center_set(f_offset);
}

// . . .
// Make your own autonomous functions here!
// . . .