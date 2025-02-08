
#include "main.h"
#include "globals.hpp"
/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////


bool isRed = true;
// These are out of 127
const int DRIVE_SPEED = 100;
const int FULL_SPEED = 127;
const int TURN_SPEED = 70;
const int TURN_SPEED2 = 60;
const int SWING_SPEED = 90;
const int DRIVE_SPEED1 = 90;
//ALSO FOR RIGHT RED move to mogo
const int slow_speed = 60; // speed for clamping mogo
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
const double RIGHTblueturn4 = -215; //turn to third donut (beside second donut)
const double RIGHTblueforward4 = 5; // move towards third donut
const double RIGHTblueback4 = -5; // move away from auton line
const double RIGHTblueturn5 = 80; // turn to ladder
const double RIGHTblueforward5 = 35; // go to ladder

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
const double LEFTredforward2 = 12.5; // move to second donut on left red

//mogo side aka LEFT blue

const double LEFTredturn3b = -68; //Turn towards second donut on left blue
const double LEFTredforward2b = 50; // move to second donut on left blue
const double LEFTredback3b = -6; // move back as to not pick up red donut on left blue
//const int delay_3 = 2500;

//continue LEFTred
const double LEFTredbyeautonline = -2; //move away from auton line after second donut
const double LEFTredturn4 = 225; //turn to third donut (beside second donut)
const double LEFTredforward4 = 5; // move towards third donut
const double LEFTredback4 = -5; // move away from auton line
const double LEFTredturn5 = -80; // turn to ladder
const double LEFTredforward5 = 35; // go to ladder

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
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
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

void lowkcannotdoanythingbruhtheseteamscarryforrealsies() {
  chassis.pid_drive_set(20, 127);
  chassis.pid_wait();
}

void sigmasigma() {
  chassis.pid_drive_set(10, 110);
  chassis.pid_wait();
  liftPID.target_set(3000);
  lift_wait();
  liftPID.target_set(0);
  lift_wait();

}

void autonwinpointleftblue() {
  isRed = false;
  chassis.drive_angle_set(-90_deg);  // Start the robot facing 90 degrees


  lifter.extend();
  chassis.pid_turn_set(-130, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(7, slow_speed);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(3, slow_speed);
  chassis.pid_wait_quick_chain();
  lifter.retract();
  setIntake(127);
  pros::delay(300);
  setIntake(0);
  chassis.pid_turn_set(-362.5, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(2.5, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(10, slow_speed);
  setIntake(127);
  pros::delay(100);
  setIntake(0);
  liftPID.target_set(3200);
  lift_wait();
  chassis.pid_drive_set(-5, slow_speed);
  liftPID.target_set(0);
  lift_wait();


  chassis.pid_turn_set(-30, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-33, slow_speed);
  chassis.pid_wait_quick_chain();
  clamp1.extend();
  chassis.pid_wait();
  setIntake(127);

  chassis.pid_turn_set(90, TURN_SPEED2);
  chassis.pid_wait();
 
  chassis.pid_drive_set(16, DRIVE_SPEED);
  chassis.pid_wait();
  setIntake(127);
  pros::delay(2000);
  setIntake(0);

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(13, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(3, 127);
  }

void autonwinpointleftred() {
  isRed = true;
  chassis.drive_angle_set(-90_deg);  // Start the robot facing 90 degrees


  lifter.extend();
  chassis.pid_turn_set(-130, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(7, slow_speed);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(3, slow_speed);
  chassis.pid_wait_quick_chain();
  lifter.retract();
  setIntake(127);
  pros::delay(300);
  setIntake(0);
  chassis.pid_turn_set(-362.5, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(2.5, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(10, slow_speed);
  setIntake(127);
  pros::delay(100);
  setIntake(0);
  liftPID.target_set(3200);
  lift_wait();
  chassis.pid_drive_set(-5, slow_speed);
  liftPID.target_set(0);
  lift_wait();


  chassis.pid_turn_set(-30, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-33, slow_speed);
  chassis.pid_wait_quick_chain();
  clamp1.extend();
  chassis.pid_wait();
  setIntake(127);

  chassis.pid_turn_set(90, TURN_SPEED2);
  chassis.pid_wait();
  
  chassis.pid_drive_set(16, DRIVE_SPEED);
  chassis.pid_wait();
  setIntake(127);
  pros::delay(2000);
  setIntake(0);

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(13, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(3, 127);
  }

void autonwinpointrightred() {

  isRed = true;
  chassis.drive_angle_set(90_deg);  // Start the robot facing 90 degrees


  lifter.extend();
  chassis.pid_turn_set(130, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(7, slow_speed);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(2, slow_speed);
  chassis.pid_wait_quick_chain();
  lifter.retract();
  setIntake(127);
  pros::delay(275);
  setIntake(0);
  chassis.pid_turn_set(362.5, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(2.5, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(10, slow_speed);
  setIntake(127);
  pros::delay(400);
  setIntake(0);
  chassis.pid_wait();
  liftPID.target_set(3200);
  lift_wait();
  chassis.pid_drive_set(-5, slow_speed);
  chassis.pid_wait();
  liftPID.target_set(0);
  lift_wait();


  chassis.pid_turn_set(30, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-33, slow_speed);
  chassis.pid_wait_quick_chain();
  clamp1.extend();
  chassis.pid_wait();
  setIntake(127);

  chassis.pid_turn_set(-90, TURN_SPEED2);
  chassis.pid_wait();

  chassis.pid_drive_set(16, DRIVE_SPEED);
  chassis.pid_wait();
  setIntake(127);
  pros::delay(2000);
  setIntake(0);

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(13, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(3, DRIVE_SPEED);
  }

void autonwinpointrightblue() {

  isRed = false;
  chassis.drive_angle_set(90_deg);  // Start the robot facing 90 degrees


  lifter.extend();
  chassis.pid_turn_set(130, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(7, slow_speed);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(2, slow_speed);
  chassis.pid_wait_quick_chain();
  lifter.retract();
  setIntake(127);
  pros::delay(275);
  setIntake(0);
  chassis.pid_turn_set(362.5, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(2.5, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(10, slow_speed);
  setIntake(127);
  pros::delay(400);
  setIntake(0);
  chassis.pid_wait();
  liftPID.target_set(3200);
  lift_wait();
  chassis.pid_drive_set(-5, slow_speed);
  chassis.pid_wait();
  liftPID.target_set(0);
  lift_wait();


  chassis.pid_turn_set(30, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-33, slow_speed);
  chassis.pid_wait_quick_chain();
  clamp1.extend();
  chassis.pid_wait();
  setIntake(127);

  chassis.pid_turn_set(-90, TURN_SPEED2);
  chassis.pid_wait();

  chassis.pid_drive_set(16, DRIVE_SPEED);
  chassis.pid_wait();
  setIntake(127);
  pros::delay(2000);
  setIntake(0);

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(13, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(3, DRIVE_SPEED);
  }

//Nolanverysigma(right blue)

void sigma_moderightblue() {

  
  isRed = false;
  
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
  // setIntake(0);

  chassis.pid_turn_set(RIGHTblueturn2, TURN_SPEED); // turn to first donut
  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTblueforward, DRIVE_SPEED); // move to first donut
  chassis.pid_wait();

//Picking up first donut

  setIntake(127);
  pros::delay(delay_2); // intake first donut
  // setIntake(0);

  chassis.pid_turn_set(RIGHTblueturn3, TURN_SPEED); // turn to stack of 8 donuts
  chassis.pid_wait();

//Right blue forward towards eight donuts

  chassis.pid_drive_set(RIGHTblueforward2, DRIVE_SPEED); // move to second donut
    chassis.pid_wait_until(6_in);
  setIntake(127);
  pros::delay(delay_2); // intake the second donut
  // setIntake(0);

  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTbluebyeautonline, DRIVE_SPEED); // move back to avoid autonomous line
  chassis.pid_wait();

  chassis.pid_turn_set(RIGHTblueturn4, TURN_SPEED);//turn to third donut (beside second donut)
  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTblueforward4, DRIVE_SPEED);// move towards third donut
  chassis.pid_wait_until(1_in);
  setIntake(127);
  pros::delay(delay_3);
  setIntake(0);

  chassis.pid_drive_set(RIGHTblueback4, DRIVE_SPEED);// move away from auton line
  chassis.pid_wait();

  chassis.pid_turn_set(RIGHTblueturn5, TURN_SPEED);// turn to ladder
  chassis.pid_wait();

  chassis.pid_drive_set(RIGHTblueforward5, FULL_SPEED);// go to ladder
  chassis.pid_wait();


}


//Nolanverysigma(right red)

void sigma_moderightred() {

  isRed = true;

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
  chassis.pid_wait_until(5_in);
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

void skibidi_moderightredwithoutdonutinspawn() {

  isRed = true;

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



  
}

//Emmaverysigma(left red)

void sigma_modeleftred() {
    //   // Start the task only if it hasn't already been started
    // if (sigmarizztaskcolorsort == nullptr) {
    //     sigmarizztaskcolorsort = new pros::Task(sigmarizz_task_function);
    // }
  isRed = true;

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
  //setIntake(0);

  chassis.pid_turn_set(LEFTredturn2, TURN_SPEED); // turn towards first donut 
  chassis.pid_wait();

  chassis.pid_drive_set(LEFTredforward, DRIVE_SPEED); // move towards first donut
  chassis.pid_wait();

//Picking up first donut

  setIntake(127);
  pros::delay(delay_2); // pick up first donut
  //setIntake(0);

  chassis.pid_turn_set(LEFTredturn3, TURN_SPEED); // turn to stack of 8 donuts
  chassis.pid_wait();

//left red forward towards eight donuts

  chassis.pid_drive_set(LEFTredforward2, DRIVE_SPEED); // move to second donut
  chassis.pid_wait_until(6_in);
  setIntake(127); // intake second donut
  pros::delay(delay_2);
  //setIntake(0);

  chassis.pid_wait();

  // setIntake(127);
  // pros::delay(delay_3); // finish off second donut just in case
  // setIntake(0);

//move away from auton line
  chassis.pid_drive_set(LEFTredbyeautonline, DRIVE_SPEED);
  chassis.pid_wait();

  // setIntake(127);
  // pros::delay(500); // just in case again?
  // setIntake(0);

  chassis.pid_turn_set(LEFTredturn4, TURN_SPEED);//turn to third donut (beside second donut)
  chassis.pid_wait();

  chassis.pid_drive_set(LEFTredforward4, DRIVE_SPEED);// move towards third donut
  chassis.pid_wait_until(1_in);
  setIntake(127);
  pros::delay(delay_3);
  setIntake(0);
  
  chassis.pid_drive_set(LEFTredback4, DRIVE_SPEED);// move away from auton line
  chassis.pid_wait();

  chassis.pid_turn_set(LEFTredturn5, TURN_SPEED);// turn to ladder
  chassis.pid_wait();

  chassis.pid_drive_set(LEFTredforward5, FULL_SPEED);// go to ladder
  chassis.pid_wait();
}

//Emmaverysigma(left blue)

void sigma_modeleftblue() {

  isRed = false;

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
void weakahhblueleft() {

  isRed = false;

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

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(23, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(4, DRIVE_SPEED);

  
}



void Version3_LeftBlue() {

  isRed = false;

  // Drive forward to (0, 36) forward, end at 45 degrees
chassis.pid_odom_set(ez::odom{{0, 36, 45}, rev, 110});

chassis.pid_wait();

// Drive back to (0, 0) backward, end at 0 degrees
chassis.pid_odom_set(ez::odom{{0, 12, 0}, rev, 110});

chassis.pid_wait();

}

void Version2_LeftBlue() {

  isRed = false;

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
  chassis.pid_wait_until(1_in);
  lifter.extend(); // extend lifter to get over raised second donut
  chassis.pid_wait_until(45_in);
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

  // chassis.pid_drive_set(-10, slow_speed); // shake second donut onto stake just in case
  // chassis.pid_wait();

// Version 2 Left Blue
const double v2lbturn = 50; // Turn towards 2nd stake
const double v2lbbackward = -34; // Going to 2nd stake


  chassis.pid_turn_set(v2lbturn, TURN_SPEED); // Turn towards 2nd stake
  chassis.pid_wait();

  chassis.pid_drive_set(v2lbbackward, DRIVE_SPEED); // Going to 2nd stake
  chassis.pid_wait_until(1_in);
    setIntake(127);
  pros::delay(delay_3c); // load second donut onto stake
  setIntake(0);
  chassis.pid_wait();
}

const double robotskillsback = -13.5; // go backwards
const double robotskillsturn = -90; // turn to stake
const double robotskillsback2 = -20.5; // move to stake
const double robotskillsturn2 = -185; // turn to first donut
const double robotskillsforward = 23; // move to first/second/third donut
const double robotskillsturnb = -85; //turn to second donut relative turn
const double robotskillsturn3 = 5; //turn towards 3rd donut
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

  isRed = true; //Team RED

  //Starting (backing up)
  chassis.pid_drive_set(robotskillsback, DRIVE_SPEED);
  chassis.pid_wait();

  //Turn towards stake
  chassis.pid_turn_set(robotskillsturn, TURN_SPEED);
  chassis.pid_wait();

  //Slowly move towards stake
  chassis.pid_drive_set(robotskillsback2, slow_speed);
  // chassis.pid_wait_until(18);
  //Secure stake
  clamp1.extend();
  chassis.pid_wait();


  //Turning towards 1st donut
  chassis.pid_turn_set(robotskillsturn2, TURN_SPEED);
  chassis.pid_wait();

  //Drives towards 1st donut and secures preload and 1st donut
  chassis.pid_drive_set(robotskillsforward, DRIVE_SPEED);
  // chassis.pid_wait_until(16);
  setIntake(127);
  //pros::delay(delay_3c);
  chassis.pid_wait();
  pros::delay(delay_3c);
  
  //Turn towards 2nd donut
  chassis.pid_turn_relative_set(robotskillsturnb, TURN_SPEED);
  chassis.pid_wait();

  //Forward towards 2nd donut
  chassis.pid_drive_set(robotskillsforward, DRIVE_SPEED);
  // chassis.pid_wait_until(16);
  //setIntake(127);
  //pros::delay(delay_3c);
  chassis.pid_wait();
  pros::delay(delay_3c);

  //Turn towards 3rd donut
  chassis.pid_turn_set(robotskillsturn3, TURN_SPEED);
  chassis.pid_wait();

  //Drive forward to 3rd and 4th donut
  chassis.pid_drive_set(robotskillsforward, DRIVE_SPEED1);
  // chassis.pid_wait_until(16);
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
  // chassis.pid_wait_until(10);
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


void skibidi_rizz() {
  chassis.pid_odom_set(24, 100, true);

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