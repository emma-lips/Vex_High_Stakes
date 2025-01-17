#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

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
void autonomous() {}

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
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::MotorGroup left_mg({-5, -3});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
	pros::MotorGroup right_mg({15, 11});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6

      // Start the task only if it hasn't already been started
    if (sigmarizztaskcolorsort == nullptr) {
        sigmarizztaskcolorsort = new pros::Task(sigmarizz_task_function);
    }

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  // Prints status of the emulated screen LCDs

		// Arcade control scheme
		int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		left_mg.move(dir - turn);                      // Sets left motor voltage
		right_mg.move(dir + turn);                     // Sets right motor voltage


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

		pros::delay(20);                               // Run for 20 ms then update



	}


}