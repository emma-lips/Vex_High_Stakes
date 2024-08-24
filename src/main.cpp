/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\emmal                                            */
/*    Created:      Tue Aug 13 2024                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 19, 15, 2    
// intake               motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----

// motor.spin(direction,speed,percent); 
// motor.stop();
// replace motor w/ motor name
// while(true){
// motor.spin(forward, 100, percent);

//(Controller1.Axis1.position());



#include "vex.h"

using namespace vex;

int main ()
{
  
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  motor FrontRight = motor (PORT2, true);
  motor FrontLeft = motor (PORT1, false);
  motor BackRight = motor (PORT15, true);
  motor BackLeft = motor (PORT19, false);


  while (true) {
    FrontRight.spin(forward, Controller1.Axis3.position() - Controller1.Axis1.position(), percent);
    FrontLeft.spin(forward, Controller1.Axis3.position() + Controller1.Axis1.position(), percent);
    BackRight.spin(forward, Controller1.Axis3.position() - Controller1.Axis1.position(), percent);
    BackLeft.spin(forward, Controller1.Axis3.position() + Controller1.Axis1.position(), percent);

    if(Controller1.ButtonL1.pressing()){
      intake.spin(forward, 100, percent);
    } else if(Controller1.ButtonL2.pressing()){
      intake.spin(reverse, 100, percent);
    } else {
      intake.stop();
    }

  }

  // while (true) {
  //       FrontLeft.spin(forward, Controller1.Axis1.position(), percent);
  //   BackLeft.spin(forward, Controller1.Axis1.position(), percent);

  // }

//  while (true) {

    // FrontLeft.spin(forward, Controller1.Axis1.position(), percent);
    // BackLeft.spin(forward, Controller1.Axis1.position(), percent);


  //}

    
    


  


  
  
  


}   












  


  /*if (Controller1.ButtonR2.pressing()) {
    FrontRight.spin(forward, 100, percent);
    FrontLeft.spin(forward, 100, percent);
    BackRight.spin(forward, 100, percent);
    BackLeft.spin(forward, 100, percent);

  }
  */


