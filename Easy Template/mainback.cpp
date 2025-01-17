#include "main.h"
// #include "globals.hpp"
/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-5, -3},     // Left Chassis Ports (negative port will reverse it!)
    {15, 11},  // Right Chassis Ports (negative port will reverse it!)

    7,      // IMU Port
    2.75,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    450);   // Wheel RPM

    // right motors are 15, 14, 11
    // left motors are 2, 5, 3
    // intake is 8
    // imu is 7
    // distance sensor(ring detector) is 4
    // colour sensor is 18
    // mogo mech is A
    // lifter is H
    // radio is 12

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Print our branding over your terminal :D
  ez::ez_template_print();

  pros::delay(500);  // Stop the user from doing anything while legacy ports configure

  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(true);  // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(0);    // Sets the active brake kP. We recommend ~2.  0 will disable.
  chassis.opcontrol_curve_default_set(3/5, 3.5);     // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to your own constants from autons.cpp
  default_constants();

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.opcontrol_curve_buttons_left_set(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);  // If using tank, only the left side is used.
  // chassis.opcontrol_curve_buttons_right_set(pros::E_CONTROLLER_DIGITAL_Y, pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.autons_add({
      Auton("robotskills\n\nyes", sigma_robotskills),
      Auton("rightblue\n\nyes", sigma_moderightblue),
      Auton("leftred\n\nyes", sigma_modeleftred),
      Auton("rightred\n\nyes", sigma_moderightred),
      Auton("leftblue\n\nyes", sigma_modeleftblue),
      Auton("Example Drive\n\nDrive forward and come back.", drive_example),
      Auton("Example Turn\n\nTurn 3 times.", turn_example),
      Auton("Drive and Turn\n\nDrive forward, turn, come back. ", drive_and_turn),
      Auton("Drive and Turn\n\nSlow down during drive.", wait_until_change_speed),
      Auton("Swing Example\n\nSwing in an 'S' curve", swing_example),
      Auton("Motion Chaining\n\nDrive forward, turn, and come back, but blend everything together :D", motion_chaining),
      Auton("Combine all 3 movements", combining_movements),
      Auton("Interference\n\nAfter driving forward, robot performs differently if interfered or not.", interfered_example),
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
  master.rumble(".");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 *
void competition_initialize() {
  // . . .
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

// bool isRed = true;

void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
// ring detector
pros::Distance ringDetector(4);
pros::Optical colorDetector(18);
bool button_enabled = true;
bool wrongcolour = false;
bool toggleRingSort = true;
  

// pros::Task sigmarizztaskcolorsort([]() {
//     while (true) {
//         // if (toggleRingSort && colorDetector.get_hue() < 20) {
//         colorDetector.set_led_pwm(100);
//         if (toggleRingSort) {

//           if (isRed) {

//             if(colorDetector.get_hue() > 200 && colorDetector.get_hue() < 260 && colorDetector.get_proximity() > 45){
//           wrongcolour = true;
//          pros::delay(20);  // Add a delay to prevent excessive CPU usage
//           }

//           }
          
//           if (!isRed) {

//             if(colorDetector.get_hue() < 20 && colorDetector.get_proximity() > 45){
//           wrongcolour = true;
//          pros::delay(20);  // Add a delay to prevent excessive CPU usage
//           }
//           }


//           if (wrongcolour && ringDetector.get() < 50) {
//             // Automatically trigger the behavior if the ring color is wrong
//             button_enabled = false;
//             setIntake(127);
//             pros::delay(240);
//             setIntake(-100);
//             pros::delay(1000);
//             setIntake(0);

//             button_enabled = true;
//             wrongcolour = false;
//             pros::delay(20);
//         }

//     }
// }});

// //void opcontrol() {

  


//   // This is preference to what you like to drive on
//   pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_COAST;

//   chassis.drive_brake_set(driver_preference_brake);

// // colour detector
// // pros::Task colordetectortask([&]() {
// //     while (true) {
// //         if (colorDetector.get_hue() < 20) {
// //             wrongcolour = true;
// //         }
// //         pros::delay(20);  // Add a delay to prevent excessive CPU usage
// //     }
// // });



 


//   while (true) {
//     // PID Tuner
//     // After you find values that you're happy with, you'll have to set them in auton.cpp
//     if (!pros::competition::is_connected()) {
//       // Enable / Disable PID Tuner
//       //  When enabled:
//       //  * use A and Y to increment / decrement the constants
//       //  * use the arrow keys to navigate the constants
//       if (master.get_digital_new_press(DIGITAL_X))
//         chassis.pid_tuner_toggle();

//       // Trigger the selected autonomous routine
//       if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
//         autonomous();
//         chassis.drive_brake_set(driver_preference_brake);
//       }

//       chassis.pid_tuner_iterate();  // Allow PID Tuner to iterate
//     }

//     // chassis.opcontrol_tank();  // Tank control
//     chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
//     // chassis.opcontrol_arcade_standard(ez::SINGLE);  // Standard single arcade
//     //chassis.opcontrol_arcade_flipped(ez::SPLIT);    // Flipped split arcade
//     // chassis.opcontrol_arcade_flipped(ez::SINGLE);   // Flipped single arcade

//     // . . .
//     // Put more user control code here!
//     // . . .
// // pros::v5::Controller master(CONTROLLER_MASTER);

//         // if(!toggleRingSort){
//         //   colorDetector.set_led_pwm(0);
//         // }
//         // else if(toggleRingSort){
//         //   colorDetector.set_led_pwm(100);
//         // }
// // pros::v5::Controller.master.clearScreen();
// //  pros::v5::Controller.master.setCursor(1,1);
// //  pros::v5::Controller.master.print("Hello World");

//     if(master.get_digital(DIGITAL_UP)){
//         toggleRingSort = !toggleRingSort;
//         pros::delay(300);
//     }

//     if(toggleRingSort){
//        if(button_enabled && master.get_digital(DIGITAL_R1)){
//       setIntake(127);
//     }
//       else if(button_enabled && master.get_digital(DIGITAL_X)){
//       setIntake(-127);
//     }
//       else if(!wrongcolour){
//       setIntake(0);
//     }
//     }
//     if(!toggleRingSort){
    
//     if(master.get_digital(DIGITAL_R1)){
//       setIntake(127);
//     }
//     else if(master.get_digital(DIGITAL_X)){
//       setIntake(-127);
//     }
//     else {
//       setIntake(0);
//     }
    
//     };

//     //setIntake((master.get_digital(DIGITAL_L1)-master.get_difital(DIGITAL_L2))*127);

//     if(master.get_digital_new_press(DIGITAL_L2)){
//         clamp1.toggle();

//     }

//         if(master.get_digital_new_press(DIGITAL_R2)){
//         lifter.toggle();
//     }




//     if(master.get_digital(DIGITAL_Y)){
//         setDoinker(60);
//     }
//     else if(master.get_digital(DIGITAL_L1)){
//         setDoinker(-60);
//     }
//     else {
//       setDoinker(0);
//     }

//     pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
//   }
// }


// pros::Task sigmarizztaskcolorsort([]() {
//     while (true) {
//         // if (toggleRingSort && colorDetector.get_hue() < 20) {
//         colorDetector.set_led_pwm(100);
//         if (toggleRingSort) {

//           if (isRed) {

//             if(colorDetector.get_hue() > 200 && colorDetector.get_hue() < 260 && colorDetector.get_proximity() > 45){
//           wrongcolour = true;
//          pros::delay(20);  // Add a delay to prevent excessive CPU usage
//           }

//           }
          
//           if (!isRed) {

//             if(colorDetector.get_hue() < 20 && colorDetector.get_proximity() > 45){
//           wrongcolour = true;
//          pros::delay(20);  // Add a delay to prevent excessive CPU usage
//           }
//           }


//           if (wrongcolour && ringDetector.get() < 50) {
//             // Automatically trigger the behavior if the ring color is wrong
//             button_enabled = false;
//             setIntake(127);
//             pros::delay(240);
//             setIntake(-100);
//             pros::delay(1000);
//             setIntake(0);

//             button_enabled = true;
//             wrongcolour = false;
//             pros::delay(20);
//         }

//     }
// }});

// Declare the task globally but do not start it here
pros::Task* sigmarizztaskcolorsort = nullptr;

// The task logic
void sigmarizz_task_function() {
    while (true) {
        if (toggleRingSort) {
            colorDetector.set_led_pwm(100);

            if (isRed) {
                if (colorDetector.get_hue() > 200 && colorDetector.get_hue() < 260 && colorDetector.get_proximity() > 45) {
                    wrongcolour = true;
                }
            } else {
                if (colorDetector.get_hue() < 20 && colorDetector.get_proximity() > 45) {
                    wrongcolour = true;
                }
            }

            if (wrongcolour && ringDetector.get() < 50) {
                button_enabled = false;
                setIntake(127);
                pros::delay(235);
                setIntake(-100);
                pros::delay(1000);
                setIntake(0);
                button_enabled = true;
                wrongcolour = false;
            }
        }
        pros::delay(20);  // Allow other tasks to run
    }
}

// opcontrol() function
void opcontrol() {

    // Start the task only if it hasn't already been started
    if (sigmarizztaskcolorsort == nullptr) {
        sigmarizztaskcolorsort = new pros::Task(sigmarizz_task_function);
    }

    pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_COAST;
    chassis.drive_brake_set(driver_preference_brake);

      while (true) {
    // PID Tuner
    // After you find values that you're happy with, you'll have to set them in auton.cpp
    if (!pros::competition::is_connected()) {
      // Enable / Disable PID Tuner
      //  When enabled:
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(DIGITAL_X))
        chassis.pid_tuner_toggle();

      // Trigger the selected autonomous routine
      if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
        autonomous();
        chassis.drive_brake_set(driver_preference_brake);
      }

      chassis.pid_tuner_iterate();  // Allow PID Tuner to iterate
    }

    // chassis.opcontrol_tank();  // Tank control
    chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
    // chassis.opcontrol_arcade_standard(ez::SINGLE);  // Standard single arcade
    //chassis.opcontrol_arcade_flipped(ez::SPLIT);    // Flipped split arcade
    // chassis.opcontrol_arcade_flipped(ez::SINGLE);   // Flipped single arcade

    // . . .
    // Put more user control code here!
    // . . .
// pros::v5::Controller master(CONTROLLER_MASTER);

        // if(!toggleRingSort){
        //   colorDetector.set_led_pwm(0);
        // }
        // else if(toggleRingSort){
        //   colorDetector.set_led_pwm(100);
        // }
// pros::v5::Controller.master.clearScreen();
//  pros::v5::Controller.master.setCursor(1,1);
//  pros::v5::Controller.master.print("Hello World");

    if(master.get_digital(DIGITAL_UP)){
        toggleRingSort = !toggleRingSort;
        pros::delay(300);
    }

    if(toggleRingSort){
       if(button_enabled && master.get_digital(DIGITAL_R1)){
      setIntake(127);
    }
      else if(button_enabled && master.get_digital(DIGITAL_X)){
      setIntake(-127);
    }
      else if(!wrongcolour){
      setIntake(0);
    }
    }
    if(!toggleRingSort){
    
    if(master.get_digital(DIGITAL_R1)){
      setIntake(127);
    }
    else if(master.get_digital(DIGITAL_X)){
      setIntake(-127);
    }
    else {
      setIntake(0);
    }
    
    };

    //setIntake((master.get_digital(DIGITAL_L1)-master.get_difital(DIGITAL_L2))*127);

    if(master.get_digital_new_press(DIGITAL_L2)){
        clamp1.toggle();

    }

        if(master.get_digital_new_press(DIGITAL_R2)){
        lifter.toggle();
    }




    if(master.get_digital(DIGITAL_Y)){
        setDoinker(60);
    }
    else if(master.get_digital(DIGITAL_L1)){
        setDoinker(-60);
    }
    else {
      setDoinker(0);
    }

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
