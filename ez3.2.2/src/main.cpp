
#include "main.h"
#include "globals.hpp"
/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-2, -3},     // Left Chassis Ports (negative port will reverse it!)
    {14, 11},  // Right Chassis Ports (negative port will reverse it!)

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
    // lady brown is 5

// Uncomment the trackers you're using here!
// - `8` and `9` are smart ports (making these negative will reverse the sensor)
//  - you should get positive values on the encoders going FORWARD and RIGHT
// - `2.75` is the wheel diameter
// - `4.0` is the distance from the center of the wheel to the center of the robot
// ez::tracking_wheel horiz_tracker(8, 2.75, 4.0);  // This tracking wheel is perpendicular to the drive wheels
// ez::tracking_wheel vert_tracker(9, 2.75, 4.0);   // This tracking wheel is parallel to the drive wheels




const int numStates = 4;
//These are in degrees
int states[numStates] = {0, 625, 625, 3400};
int currState = 0;
int target = 0;

void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    }
    if (currState == 2) {
      setIntake(75);
      pros::delay(75);
       setIntake(-50);
       pros::delay(75);
       setIntake(0);
     }

    target = states[currState];
}



void liftControl(){
  liftPID.target_set(target);

}



// void liftControl() {
//     double kp = 0.5;
//     double error = target - rotationSensor.get_position();
//     double velocity = kp * error;
//     lb.move_absolute(target, velocity);
// }

// void liftControl() {
//     double kp = 1;    // Proportional gain (tune as needed)
//     double kd = 1;    // Derivative gain (tune as needed)
//     static double prevError = 0;
//     static uint32_t prevTime = pros::millis(); // Track time for accurate dt

//     uint32_t currentTime = pros::millis();
//     double dt = (currentTime - prevTime) / 1000.0; // Convert to seconds

//     // Handle edge cases for time calculation
//     if (dt <= 0) dt = 0.01; // Prevent division by zero

//     double error = target - rotationSensor.get_position();
//     double derivative = (error - prevError) / dt; // Calculate derivative

//     // Compute velocity with PD control
//     double velocity = kp * error + kd * derivative;

//     // Clamp velocity to valid motor range (-127 to 127)
//     velocity = (velocity > 127) ? 127 : (velocity < -127) ? -127 : velocity;

//     lb.move(velocity);

//     // Save previous error and time for next iteration
//     prevError = error;
//     prevTime = currentTime;
// }


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

   rotationSensor.reset_position();

    lb.tare_position();

    liftPID.exit_condition_set(80, 50, 300, 150, 500, 500);

  // Look at your horizontal tracking wheel and decide if it's in front of the midline of your robot or behind it
  //  - change `back` to `front` if the tracking wheel is in front of the midline
  //  - ignore this if you aren't using a horizontal tracker
  // chassis.odom_tracker_back_set(&horiz_tracker);
  // Look at your vertical tracking wheel and decide if it's to the left or right of the center of the robot
  //  - change `left` to `right` if the tracking wheel is to the right of the centerline
  //  - ignore this if you aren't using a vertical tracker
  // chassis.odom_tracker_left_set(&vert_tracker);

  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(true);   // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(0.0);   // Sets the active brake kP. We recommend ~2.  0 will disable.
  chassis.opcontrol_curve_default_set(3.8, 2.3);  // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to your own constants from autons.cpp!
  default_constants();

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.opcontrol_curve_buttons_left_set(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);  // If using tank, only the left side is used.
  // chassis.opcontrol_curve_buttons_right_set(pros::E_CONTROLLER_DIGITAL_Y, pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
ez::as::auton_selector.autons_add({

      Auton("tsissocookedletotherteamgetawponleftblue\n\nbruuuh", weakahhblueleft),
      Auton("gettingcarriedfrfr\n\nmaaaantheseteamsmakingtsboring", lowkcannotdoanythingbruhtheseteamscarryforrealsies), 
      Auton("rightredletotherteamgetawp\n\ntslowksoskibidi2donutsonstake", skibidi_moderightredwithoutdonutinspawn), 
      Auton("liftnotsigmafr\n\ntrollingcodedon'tuse", sigmasigma), 
      Auton("robotskills\n\nobviouslyrobotskills", sigma_robotskills),
      Auton("rightblue\n\nFOURDONUTSOMGOMG", sigma_moderightblue),
      Auton("rightbluealliancestake\n\nautonwinpointhopefullyrightblue", autonwinpointrightblue),
      Auton("leftbluealliancestake\n\nautonwinpointhopefullyleftblue", autonwinpointleftblue),
      Auton("leftred\n\nworkingleftred", sigma_modeleftred),
      Auton("leftredalliancestake\n\nautonwinpointhopefullyleftred", autonwinpointleftred),
      Auton("rightredalliancestake\n\nautonwinpointhopefullyrightred", autonwinpointrightred),
      Auton("rightred\n\nworkingrightred", sigma_moderightred),
      Auton("leftblue\n\nworkingleftblue", sigma_modeleftblue),
      Auton("skibiid\n\ntrash", skibidi_rizz),
      Auton("v2leftblue\n\ntryingtogettwostakesdoNOTuse", Version2_LeftBlue),
      Auton("v3leftblue\n\npoopoocodenotrealdoesntworkforrealsies", Version3_LeftBlue),
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
  master.rumble(chassis.drive_imu_calibrated() ? "." : "---");
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
 */
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


pros::Task Lift_Task(lift_task);  // Create the task, this will cause the function to start running

// ring detector
pros::Distance ringDetector(4);
pros::Optical colorDetector(18);
bool button_enabled = true;
bool wrongcolour = false;
bool toggleRingSort = true;
bool nextState1 = true;
// bool isRed;


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
                pros::delay(305);
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

void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);    // Set the current position, you can start at a specific position with this
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency
  chassis.opcontrol_speed_max_set(127);

      // Start the task only if it hasn't already been started
    // if (sigmarizztaskcolorsort == nullptr) {
    //     sigmarizztaskcolorsort = new pros::Task(sigmarizz_task_function);
    // }


  /*
  Odometry and Pure Pursuit are not magic

  It is possible to get perfectly consistent results without tracking wheels,
  but it is also possible to have extremely inconsistent results without tracking wheels.
  When you don't use tracking wheels, you need to:
   - avoid wheel slip
   - avoid wheelies
   - avoid throwing momentum around (super harsh turns, like in the example below)
  You can do cool curved motions, but you have to give your robot the best chance
  to be consistent
  */

  ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
}

/**
 * Simplifies printing tracker values to the brain screen
 */
void screen_print_tracker(ez::tracking_wheel *tracker, std::string name, int line) {
  std::string tracker_value = "", tracker_width = "";
  // Check if the tracker exists
  if (tracker != nullptr) {
    tracker_value = name + " tracker: " + util::to_string_with_precision(tracker->get());             // Make text for the tracker value
    tracker_width = "  width: " + util::to_string_with_precision(tracker->distance_to_center_get());  // Make text for the distance to center
  }
  ez::screen_print(tracker_value + tracker_width, line);  // Print final tracker text
}

/**
 * Ez screen task
 * Adding new pages here will let you view them during user control or autonomous
 * and will help you debug problems you're having
 */
void ez_screen_task() {
  while (true) {
    // Only run this when not connected to a competition switch
    if (!pros::competition::is_connected()) {
      // Blank page for odom debugging
      if (chassis.odom_enabled() && !chassis.pid_tuner_enabled()) {
        // If we're on the first blank page...
        if (ez::as::page_blank_is_on(0)) {
          // Display X, Y, and Theta
          ez::screen_print("x: " + util::to_string_with_precision(chassis.odom_x_get()) +
                               "\ny: " + util::to_string_with_precision(chassis.odom_y_get()) +
                               "\na: " + util::to_string_with_precision(chassis.odom_theta_get()),
                           1);  // Don't override the top Page line

          // Display all trackers that are being used
          screen_print_tracker(chassis.odom_tracker_left, "l", 4);
          screen_print_tracker(chassis.odom_tracker_right, "r", 5);
          screen_print_tracker(chassis.odom_tracker_back, "b", 6);
          screen_print_tracker(chassis.odom_tracker_front, "f", 7);
        }
      }
    }

    // Remove all blank pages when connected to a comp switch
    else {
      if (ez::as::page_blank_amount() > 0)
        ez::as::page_blank_remove_all();
    }

    pros::delay(ez::util::DELAY_TIME);
  }
}
pros::Task ezScreenTask(ez_screen_task);

/**
 * Gives you some extras to run in your opcontrol:
 * - run your autonomous routine in opcontrol by pressing DOWN and B
 *   - to prevent this from accidentally happening at a competition, this
 *     is only enabled when you're not connected to competition control.
 * - gives you a GUI to change your PID values live by pressing X
 */
void ez_template_extras() {
  // Only run this when not connected to a competition switch
  if (!pros::competition::is_connected()) {
    // PID Tuner
    // - after you find values that you're happy with, you'll have to set them in auton.cpp

    // Enable / Disable PID Tuner
    //  When enabled:
    //  * use A and Y to increment / decrement the constants
    //  * use the arrow keys to navigate the constants
    if (master.get_digital_new_press(DIGITAL_X))
      chassis.pid_tuner_toggle();

    // Trigger the selected autonomous routine
    if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
      pros::motor_brake_mode_e_t preference = chassis.drive_brake_get();
      autonomous();
      chassis.drive_brake_set(preference);
    }

    // Allow PID Tuner to iterate
    chassis.pid_tuner_iterate();
  }

  // Disable PID Tuner when connected to a comp switch
  else {
    if (chassis.pid_tuner_enabled())
      chassis.pid_tuner_disable();
  }
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



void opcontrol() {

        pros::Task liftControlTask([]{
        while (true) {
            liftControl();
            pros::delay(10);
        }
    });

    if (sigmarizztaskcolorsort == nullptr) {
      sigmarizztaskcolorsort = new pros::Task(sigmarizz_task_function);
  }
  chassis.opcontrol_speed_max_set(113);
      // Start the task only if it hasn't already been started

  // This is preference to what you like to drive on
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);

  while (true) {
    // Gives you some extras to make EZ-Template ezier
    ez_template_extras();

    // chassis.opcontrol_tank();  // Tank control
    chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
    // chassis.opcontrol_arcade_standard(ez::SINGLE);  // Standard single arcade
    // chassis.opcontrol_arcade_flipped(ez::SPLIT);    // Flipped split arcade
    // chassis.opcontrol_arcade_flipped(ez::SINGLE);   // Flipped single arcade

    // . . .
    // Put more user control code here!
    // . . .
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




// lady brown code
    //   if (master.get_digital(DIGITAL_LEFT)) {
    //   liftPID.target_set(0);
    // }

     if (master.get_digital_new_press(DIGITAL_LEFT)) {
     nextState();
    }
  

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
