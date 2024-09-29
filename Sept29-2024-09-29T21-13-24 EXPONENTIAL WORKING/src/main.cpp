/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\emmal                                            */
/*    Created:      Sun Sep 29 2024                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"

using namespace vex;

// Define the motors
motor FrontLeftMotor(PORT1, gearSetting::ratio18_1, false);
motor BackLeftMotor(PORT10, gearSetting::ratio18_1, false);
motor FrontRightMotor(PORT11, gearSetting::ratio18_1, true);
motor BackRightMotor(PORT20, gearSetting::ratio18_1, true);
motor MiddleLeftMotor(PORT5, gearSetting::ratio18_1, false);
motor MiddleRightMotor(PORT15, gearSetting::ratio18_1, true);

// Define the controller
controller controller_1;

// Function to calculate velocity
double calculateVelocity(double axis2, double axis4) {
    double x = axis2 + axis4;
    return 0.0001 * (x * x * x);
}

// Function to calculate the motor velocities
void setMotorVelocities(double forward, double strafe, double turn) {
    // Calculate base velocities
    double velocity_x = calculateVelocity(forward, strafe);
    double velocity_x_neg = calculateVelocity(forward, -strafe);

    // Set velocities for each motor based on movement direction
    FrontLeftMotor.setVelocity(velocity_x_neg - turn, percentUnits::pct);
    BackLeftMotor.setVelocity(velocity_x_neg - turn, percentUnits::pct);
    FrontRightMotor.setVelocity(velocity_x + turn, percentUnits::pct);
    BackRightMotor.setVelocity(velocity_x + turn, percentUnits::pct);
    MiddleLeftMotor.setVelocity(velocity_x_neg - turn, percentUnits::pct);
    MiddleRightMotor.setVelocity(velocity_x + turn, percentUnits::pct);
}

int main() {
    while (true) {
        // Get the controller axis positions
        double axis2_position = controller_1.Axis2.position(percent);
        double axis4_position = controller_1.Axis4.position(percent);

        // Determine movement directions
        double forward = axis2_position;
        double strafe = axis4_position;
        double turn = (controller_1.Axis4.position(percent) / 100.0); // Assuming Axis4 is used for turning

        // Set velocities based on controller inputs
        setMotorVelocities(forward, strafe, turn);

        // Spin each motor according to its calculated velocity
        FrontLeftMotor.spin(directionType::fwd);
        BackLeftMotor.spin(directionType::fwd);
        FrontRightMotor.spin(directionType::fwd);
        BackRightMotor.spin(directionType::fwd);
        MiddleLeftMotor.spin(directionType::fwd);
        MiddleRightMotor.spin(directionType::fwd);

        // Allow time for the motors to update
        vex::task::sleep(20); // Sleep for 20 milliseconds
    }
}

