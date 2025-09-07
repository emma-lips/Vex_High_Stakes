#include "main.h"

// Intake (hold down button to spin motor)
void refreshIntake() {
	if (intakeLock == false) {
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			intake.move_voltage(12000);
		} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			intake.move_voltage(-12000);
		} else {
			intake.move_voltage(0);
		}
	}
}

bool isResetting = false;
void refreshWallstakes() {
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		wallStake.move_voltage(12000);
		intake.move_voltage(-1000);
	} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		wallStake.move_voltage(-12000);
	} else if (isResetting == false) {
		wallStake.brake();
	}

	if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
		resetWallstakes();
	}
}

bool clampToggle = false;
void refreshClamp() {
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    	clampToggle = !clampToggle;
		clampPiston.set_value(clampToggle);
    }
}

bool doinkerToggle = false;
bool descoreToggle = false;
void refreshDoinker() {
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    	doinkerToggle = !doinkerToggle;
		// if (alliance == "blue") {
			rightDoinkerPiston.set_value(doinkerToggle);
		// } else {
		// 	leftDoinkerPiston.set_value(doinkerToggle);
		// }
    }
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
    	descoreToggle = !descoreToggle;
		descorePiston.set_value(descoreToggle);
    }
}

void hangSequeunce() {
	
}

