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
double calculateVelocity(double value) {
    return 0.0001 * (value * value * value);
}

// Function to set motor velocities
void setMotorVelocities(double forward, double strafe, double turn) {
    double velocity_x = calculateVelocity(forward);
    double velocity_y = calculateVelocity(strafe);

    // Calculate common velocities for motors
    double frontLeftVel = velocity_y - turn;
    double backLeftVel = velocity_y - turn;
    double frontRightVel = velocity_x + turn;
    double backRightVel = velocity_x + turn;
    
    // Set velocities for each motor based on calculated values
    FrontLeftMotor.setVelocity(frontLeftVel, percentUnits::pct);
    BackLeftMotor.setVelocity(backLeftVel, percentUnits::pct);
    FrontRightMotor.setVelocity(frontRightVel, percentUnits::pct);
    BackRightMotor.setVelocity(backRightVel, percentUnits::pct);
    
    MiddleLeftMotor.setVelocity(backLeftVel, percentUnits::pct);
    MiddleRightMotor.setVelocity(frontRightVel, percentUnits::pct);
}

int main() {
    while (true) {
        // Get the controller axis positions
        double axis2_position = controller_1.Axis2.position(percent);
        double axis4_position = controller_1.Axis4.position(percent);

        // Set velocities based on controller inputs
        setMotorVelocities(axis2_position, axis4_position, axis4_position / 100.0);

        // Spin each motor according to its calculated velocity
        FrontLeftMotor.spin(directionType::fwd);
        BackLeftMotor.spin(directionType::fwd);
        FrontRightMotor.spin(directionType::fwd);
        BackRightMotor.spin(directionType::fwd);
        MiddleLeftMotor.spin(directionType::fwd);
        MiddleRightMotor.spin(directionType::fwd);

        // Reduce sleep time for faster response
        vex::task::sleep(10); // Sleep for 10 milliseconds
    }
}
