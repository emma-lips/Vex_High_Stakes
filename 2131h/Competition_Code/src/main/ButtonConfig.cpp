#include "main/ButtonConfig.hpp"

#include "pros/misc.h"

namespace Buttons
{
ButtonDetector Intake(pros::E_CONTROLLER_DIGITAL_R1);   // Intake
ButtonDetector Outtake(pros::E_CONTROLLER_DIGITAL_X);  // Outtake

ButtonDetector ArmUp(pros::E_CONTROLLER_DIGITAL_L1);    // doinker Up
ButtonDetector ArmDown(pros::E_CONTROLLER_DIGITAL_Y);  // doinker Down
ButtonDetector lift(pros::E_CONTROLLER_DIGITAL_L2);  // intake lift

ButtonDetector ClampToggle(pros::E_CONTROLLER_DIGITAL_L2);  // Clamp

/**
 * @brief Update all Buttons
 *
 */
void update()
{
  Intake.update();
  Outtake.update();
  ArmUp.update();
  ArmDown.update();
  lift.update();
  ClampToggle.update();
}
}  // namespace Buttons