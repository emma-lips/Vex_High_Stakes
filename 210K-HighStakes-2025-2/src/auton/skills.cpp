#include "main.h"

void skills() { /* NO COLOUR SORT */

     

       //old stuff
wallStake.move_voltage(12000);
intake.move_voltage(12000);
pros::delay(400);
wallStake.brake();
intake.move_voltage(0);
chassis.moveToPoint(0, 11, 800);
pros::delay(100);
chassis.turnToHeading(90, 500);
chassis.moveToPoint(-21 , 14, 1100, {.forwards = false, .maxSpeed = 60});
pros::Task([]{
       pros::delay(800);
       clampPiston.set_value(true);
       pros::delay(300);
       intake.move_voltage(12000);
       liftControl(0);
});
chassis.moveToPoint(-20, 36, 800);
pros::delay(200);
chassis.moveToPoint(-36, 47, 800);
chassis.moveToPoint(-47, 88, 1500);
pros::Task([]{
       pros::delay(350);
       liftControl(wallstakeStates[1]);
       pros::delay(2300);
       intake.move_voltage(-1000);
       liftControl(wallstakeStates[3]);
pros::delay(400);
});
chassis.moveToPoint(-40, 63, 1700);
chassis.turnToHeading(270, 700);
chassis.moveToPoint(-67, 63.9, 1000);
intake.move_voltage(6000);
chassis.turnToHeading(270, 400);
liftControl(wallstakeStates[2]);
chassis.moveToPoint(-48, 63, 1000, {.forwards = false});
intake.move_voltage(12000);
chassis.moveToPoint(-48, 2,2000, {.maxSpeed = 85});
chassis.moveToPoint(-44, 15, 700, {.forwards = false});
// pros::Task([]{
//        pros::delay(1800);
//        intake.move_voltage(-12000);
//        pros::delay(300);
//        intake.move_voltage(12000);
// });
chassis.moveToPoint(-62, 15, 1000);
pros::delay(600);
chassis.moveToPoint(-64, 0, 1000, {.forwards = false});
pros::delay(1400);
intake.move_voltage(-6000);
clampPiston.set_value(false);
pros::delay(200);



chassis.moveToPoint(-5, 14, 1500); // on way to second mogo intake facing mogo
pros::Task([] {
       liftControl(wallstakeStates[0]);
       pros::delay(100);
       intake.move_voltage(0);
});
// pros::delay(100);
chassis.turnToHeading(270, 700, {}, false);
// pros::delay(500);

// // pos reset - CLAMP MUST BE DOWN HERE!!! / do not run async / clamp should face the mogo and bot is parallel to field
// float absX = -((backwardDist.get_distance() / 25.4 + 3.9) - 72);
// float absY = leftDist.get_distance() / 25.4 + 6 - (6.2+3.9);
// chassis.setPose(absX, absY, inertial1.get_rotation());
// controller.rumble(".");

chassis.moveToPoint(27 , 6, 1100, {.forwards = false, .maxSpeed = 60});
pros::Task([]{
       pros::delay(800);
       clampPiston.set_value(true);
       intake.move_voltage(12000);
});
pros::delay(1100);

chassis.moveToPoint(25, 36, 900);
pros::delay(200);
chassis.moveToPoint(34, 42, 800);
chassis.moveToPoint(52, 81, 2000);
pros::delay(200);
pros::Task([]{
       pros::delay(650);
       liftControl(wallstakeStates[1]);
       pros::delay(2100);
       intake.move_voltage(-1500);
       liftControl(wallstakeStates[3]);
// pros::delay(400);
});
chassis.moveToPoint(45, 57.5, 2700);
chassis.turnToHeading(90, 700);
chassis.moveToPoint(72, 57.5, 1000);
intake.move_voltage(4000);
chassis.turnToHeading(90, 400);
liftControl(wallstakeStates[2]);
chassis.moveToPoint(50, 58, 1000, {.forwards = false});
intake.move_voltage(12000);
chassis.moveToPoint(47, -2, 2000, {.maxSpeed = 85});
chassis.moveToPoint(44, 7, 1000, {.forwards = false});
chassis.turnToHeading(90, 700);
chassis.moveToPoint(68, 7, 1000);
pros::delay(600);
chassis.moveToPoint(72, -6, 1000, {.forwards = false});
pros::delay(1200);
clampPiston.set_value(false);
pros::Task([]{
       intake.move_voltage(0);
       liftControl(0);
});
pros::delay(100);
chassis.moveToPoint(-25, 90, 3000);
pros::Task([]{
       pros::delay(800);
       intake.move_voltage(4000);
       pros::delay(1300);
       intake.move_voltage(0);
});
chassis.moveToPoint(-22, 117, 2300, {.forwards = false, .maxSpeed = 75});
pros::Task([]{
       pros::delay(1400);
       clampPiston.set_value(true);
       pros::delay(200);
       leftDoinkerPiston.set_value(true);
       pros::delay(200);
       leftDoinkerPiston.set_value(false);
       pros::delay(200);
       intake.move_voltage(12000);
});
chassis.moveToPoint(-42, 114, 2000);
chassis.turnToHeading(180, 600);
chassis.moveToPoint(-39, 102, 1000);
// chassis.moveToPoint(-56, 108, 2000);
// chassis.moveToPoint(-43, 108, 2000);
// chassis.moveToPoint(-59, 120, 2000, {.forwards = false});
 }

void skillsCS() { /* WITH COLOUR SORT */

alliance = "red";

}