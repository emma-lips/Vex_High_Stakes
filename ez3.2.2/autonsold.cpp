//THIS WORKS 2025-02-19
void sigma_modeleftred5donuts() {
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
  
  chassis.pid_drive_set(21, DRIVE_SPEED); // move towards first donut
  chassis.pid_wait();
  
  //Picking up first donut
  
  setIntake(127);
  pros::delay(delay_2); // pick up first donut
  //setIntake(0);
  
  chassis.pid_turn_set(LEFTredturn3, TURN_SPEED); // turn to stack of 8 donuts
  chassis.pid_wait();
  
  //left red forward towards eight donuts
  
  chassis.pid_drive_set(10.5, DRIVE_SPEED); // move to second donut
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
  
  chassis.pid_turn_set(160, TURN_SPEED);//turn to third donut (beside second donut)
  chassis.pid_wait();
  
  chassis.pid_drive_set(4.5, DRIVE_SPEED);// move towards third donut
  chassis.pid_wait();
  pros::delay(300);
  setIntake(127);
  
  
  chassis.pid_drive_set(LEFTredback4, DRIVE_SPEED);// move away from auton line
  chassis.pid_wait();
  
  chassis.pid_turn_set(-55, TURN_SPEED);// turn to raised donut
  chassis.pid_wait();
  
  lifter.extend();
  chassis.pid_wait_until(32);
  
  chassis.pid_drive_set(35, FULL_SPEED);// go to raised donut
  chassis.pid_wait_quick_chain();
  
  chassis.pid_drive_set(11, slow_speed);
  chassis.pid_wait();
  
  
  lifter.retract();
  setIntake(127);
  pros::delay(600);
  setIntake(0);
  
  chassis.pid_drive_set(-6, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  
  setIntake(127);
  pros::delay(2000);
  
  
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
    chassis.pid_turn_set(360, TURN_SPEED);
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
    // pros::delay(450); // intake preload
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
    pros::delay(450); // intake the second donut
    // setIntake(0);
  
    chassis.pid_wait();
  
    chassis.pid_drive_set(RIGHTbluebyeautonline, DRIVE_SPEED); // move back to avoid autonomous line
    chassis.pid_wait();
  
    chassis.pid_turn_set(RIGHTblueturn4, TURN_SPEED);//turn to third donut (beside second donut)
    chassis.pid_wait();
  
    chassis.pid_drive_set(RIGHTblueforward4, DRIVE_SPEED);// move towards third donut
    chassis.pid_wait();
  
  
    chassis.pid_drive_set(RIGHTblueback4, DRIVE_SPEED);// move away from autn line
    chassis.pid_wait();
  
    chassis.pid_turn_set(RIGHTblueturn5, TURN_SPEED);// turn to negative corner
    chassis.pid_wait();
  
    chassis.pid_drive_set(RIGHTblueforward5, FULL_SPEED);// go to negative corner
    chassis.pid_wait();
  
    chassis.pid_turn_set(-80, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    pros::delay(delay_2);
    setIntake(0);
  
  }
  
  //THIS WORKS 2025-02-19
  void sigma_moderightblue5donuts() {
  
    
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
    // pros::delay(450); // intake preload
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
  
    chassis.pid_drive_set(8.5, DRIVE_SPEED); // move to second donut
      chassis.pid_wait_until(6_in);
    setIntake(127);
    pros::delay(450); // intake the second donut
    // setIntake(0);
  
    chassis.pid_wait();
  
    chassis.pid_drive_set(RIGHTbluebyeautonline, DRIVE_SPEED); // move back to avoid autonomous line
    chassis.pid_wait();
  
    chassis.pid_turn_set(RIGHTblueturn4, TURN_SPEED);//turn to third donut (beside second donut)
    chassis.pid_wait();
  
    chassis.pid_drive_set(5.5, DRIVE_SPEED);// move towards third donut
    chassis.pid_wait();
  
    chassis.pid_drive_set(RIGHTblueback4, DRIVE_SPEED);// move away from autn line
    chassis.pid_wait();
  
    chassis.pid_turn_set(55, TURN_SPEED);// turn to raised donut
    chassis.pid_wait();
  
    lifter.extend();
    chassis.pid_wait_until(37);
  
    chassis.pid_drive_set(37, FULL_SPEED);// go to negative corner
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(11, slow_speed);
    chassis.pid_wait();
  
    
    lifter.retract();
    setIntake(127);
    pros::delay(700);
    setIntake(0);
  
    chassis.pid_drive_set(-6, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
  
    setIntake(127);
    pros::delay(2000);
  
    // chassis.pid_turn_set(-80, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    // pros::delay(delay_2);
    // setIntake(0);
  
  }
  
  void lockedin_rightblue() {
  
    // THIS IS AN ATTEMPT ON 5 DONUT
  
  
    isRed = false;
    
    chassis.pid_drive_set(RIGHTblueback, DRIVE_SPEED); // move back towards mogo
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(RIGHTblueturn, TURN_SPEED); // turn toward mogo
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(RIGHTblueback2, slow_speed, true); // move slowly to clamp mogo
    chassis.pid_wait_quick_chain();
  
    clamp1.extend(); // clamp mogo
    chassis.pid_wait();
  
    setIntake(127);
    pros::delay(delay_1); // intake preload
    // setIntake(0);
  
    chassis.pid_turn_set(RIGHTblueturn2, TURN_SPEED); // turn to first donut
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(RIGHTblueforward, DRIVE_SPEED); // move to first donut
    chassis.pid_wait_quick_chain();
  
  //Picking up first donut
  
    setIntake(127);
    pros::delay(delay_2); // intake first donut
    // setIntake(0);
  
    chassis.pid_turn_set(RIGHTblueturn3, TURN_SPEED); // turn to stack of 8 donuts
    chassis.pid_wait_quick_chain();
  
  //Right blue forward towards eight donuts
  
    chassis.pid_drive_set(RIGHTblueforward2, DRIVE_SPEED); // move to second donut
      chassis.pid_wait_until(6_in);
    setIntake(127);
    pros::delay(delay_2); // intake the second donut
    // setIntake(0);
  
    chassis.pid_wait();
  
    chassis.pid_drive_set(RIGHTbluebyeautonline, DRIVE_SPEED); // move back to avoid autonomous line
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(RIGHTblueturn4, TURN_SPEED);//turn to third donut (beside second donut)
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(RIGHTblueforward4, DRIVE_SPEED);// move towards third donut
    chassis.pid_wait_until(1_in);
    setIntake(127);
  
  
    chassis.pid_drive_set(RIGHTblueback4, DRIVE_SPEED);// move away from auton line
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(50, TURN_SPEED);
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(56, DRIVE_SPEED);
    chassis.pid_wait_until(40);
    lifter.extend();
    chassis.pid_wait_until(55);
    lifter.retract();
    setIntake(127);
    pros::delay(600);
    setIntake(0);
  
    chassis.pid_drive_set(-6, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
  
    setIntake(127);
  
  
  
  }
  // WORKING FEB 20
  void leftbluealliancestakeladder() {
    chassis.opcontrol_drive_activebrake_set(0.0);   
  
    isRed = false;
    chassis.drive_angle_set(-90_deg);  // Start the robot facing 90 degrees
  
  
    lifter.extend();
    chassis.pid_turn_set(-130, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(9, slow_speed);
    chassis.pid_wait_quick_chain();
  
    lifter.retract();
    setIntake(127);
    pros::delay(555);
    setIntake(0);
  
    chassis.pid_drive_set(-1, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(-372, TURN_SPEED);
    chassis.pid_wait();
    // chassis.pid_turn_set(2.5, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(9.5, slow_speed);
  
    // chassis.pid_turn_set(355, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    // chassis.pid_drive_set(4, DRIVE_SPEED);
  
    chassis.pid_wait();
    target = 3000;
    lift_wait();
    chassis.pid_drive_set(-7, slow_speed);
    chassis.pid_wait_quick_chain();
    // liftPID.target_set(0);
    // lift_wait();
  
  
    chassis.pid_turn_set(-26.5, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-27.5, slow_speed);
    chassis.pid_wait_quick_chain();
    clamp1.extend();
    chassis.pid_wait();
    setIntake(127);
  
    chassis.pid_turn_set(90, TURN_SPEED2);
    chassis.pid_wait();
  
    chassis.pid_drive_set(16, DRIVE_SPEED);
    chassis.pid_wait();
  
    pros::delay(300);
  
    chassis.pid_turn_set(-90, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(13, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(4, 127);
  
  
  }
  // WORKING FEB 20
  void leftredalliancestakeladder() {
    chassis.opcontrol_drive_activebrake_set(0.0);   
  
    isRed = true;
    chassis.drive_angle_set(-90_deg);  // Start the robot facing 90 degrees
  
  
    lifter.extend();
    chassis.pid_turn_set(-130, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(9, slow_speed);
    chassis.pid_wait_quick_chain();
  
    lifter.retract();
    setIntake(127);
    pros::delay(525);
    setIntake(0);
  
    chassis.pid_drive_set(-1, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(-372, TURN_SPEED);
    chassis.pid_wait();
    // chassis.pid_turn_set(2.5, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(9.5, slow_speed);
  
    // chassis.pid_turn_set(355, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    // chassis.pid_drive_set(4, DRIVE_SPEED);
  
    chassis.pid_wait();
    target = 3000;
    lift_wait();
    chassis.pid_drive_set(-7, slow_speed);
    chassis.pid_wait_quick_chain();
    // liftPID.target_set(0);
    // lift_wait();
  
  
    chassis.pid_turn_set(-26.5, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-27.5, slow_speed);
    chassis.pid_wait_quick_chain();
    clamp1.extend();
    chassis.pid_wait();
    setIntake(127);
  
    chassis.pid_turn_set(90, TURN_SPEED2);
    chassis.pid_wait();
  
    chassis.pid_drive_set(16, DRIVE_SPEED);
    chassis.pid_wait();
  
    pros::delay(300);
  
    chassis.pid_turn_set(-90, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(13, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(4, 127);
  
  
  }
  // THESE WORK FEB 20
  void rightbluealliancestakeladder() {
  
    chassis.opcontrol_drive_activebrake_set(0.0);   
  
    isRed = false;
    chassis.drive_angle_set(90_deg);  // Start the robot facing 90 degrees
  
  
    lifter.extend();
    chassis.pid_turn_set(130, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(7, slow_speed);
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(1, slow_speed);
    chassis.pid_wait_quick_chain();
    lifter.retract();
    setIntake(127);
    pros::delay(525);
    setIntake(0);
  
    chassis.pid_drive_set(-2, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(375.5, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    // chassis.pid_turn_set(2.5, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(8, slow_speed);
  
    // chassis.pid_turn_set(355, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    // chassis.pid_drive_set(4, DRIVE_SPEED);
    // setIntake(127);
    // pros::delay(400);
    // setIntake(0);
    chassis.pid_wait();
    target = 3000;
    lift_wait();
    chassis.pid_drive_set(-5, slow_speed);
    chassis.pid_wait_quick_chain();
    // liftPID.target_set(0);
    // lift_wait();
  
  
    chassis.pid_turn_set(28, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-31, slow_speed);
    chassis.pid_wait_quick_chain();
    clamp1.extend();
    chassis.pid_wait();
    setIntake(127);
  
    chassis.pid_turn_set(-90, TURN_SPEED2);
    chassis.pid_wait();
  
    chassis.pid_drive_set(16, DRIVE_SPEED);
    chassis.pid_wait();
    setIntake(127);
    pros::delay(450);
  
  
    chassis.pid_turn_set(90, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(13, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(1, DRIVE_SPEED);
  
  }
  // WORKS FEB 20
  void rightredalliancestakeladder() {
  
    chassis.opcontrol_drive_activebrake_set(0.0);   
  
    isRed = true;
    chassis.drive_angle_set(90_deg);  // Start the robot facing 90 degrees
  
  
    lifter.extend();
    chassis.pid_turn_set(130, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(7, slow_speed);
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(1, slow_speed);
    chassis.pid_wait_quick_chain();
    lifter.retract();
    setIntake(127);
    pros::delay(525);
    setIntake(0);
  
    chassis.pid_drive_set(-2, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(375.5, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    // chassis.pid_turn_set(2.5, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(8, slow_speed);
  
    // chassis.pid_turn_set(355, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    // chassis.pid_drive_set(4, DRIVE_SPEED);
    // setIntake(127);
    // pros::delay(400);
    // setIntake(0);
    chassis.pid_wait();
    target = 3000;
    lift_wait();
    chassis.pid_drive_set(-5, slow_speed);
    chassis.pid_wait_quick_chain();
    // liftPID.target_set(0);
    // lift_wait();
  
  
    chassis.pid_turn_set(28, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-31, slow_speed);
    chassis.pid_wait_quick_chain();
    clamp1.extend();
    chassis.pid_wait();
    setIntake(127);
  
    chassis.pid_turn_set(-90, TURN_SPEED2);
    chassis.pid_wait();
  
    chassis.pid_drive_set(16, DRIVE_SPEED);
    chassis.pid_wait();
    setIntake(127);
    pros::delay(450);
  
  
    chassis.pid_turn_set(90, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(13, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(1, DRIVE_SPEED);
  
  }
  
  
  // THIS WORKS!! NINE POINTS FEB 20
  void soloawprightblue() {
  
    chassis.opcontrol_drive_activebrake_set(2.0);   
  
    isRed = false;
    chassis.drive_angle_set(90_deg);  // Start the robot facing 90 degrees
  
  
    lifter.extend();
    chassis.pid_turn_set(130, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(7, slow_speed);
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(1, slow_speed);
    chassis.pid_wait_quick_chain();
    lifter.retract();
    setIntake(127);
    pros::delay(525);
    setIntake(0);
  
    chassis.pid_drive_set(-2, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(375.5, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    // chassis.pid_turn_set(2.5, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(8, slow_speed);
  
    // chassis.pid_turn_set(355, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    // chassis.pid_drive_set(4, DRIVE_SPEED);
    // setIntake(127);
    // pros::delay(400);
    // setIntake(0);
    chassis.pid_wait();
    target = 3000;
    lift_wait();
    chassis.pid_drive_set(-5, slow_speed);
    chassis.pid_wait_quick_chain();
    // liftPID.target_set(0);
    // lift_wait();
  
  
    chassis.pid_turn_set(28, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-31, slow_speed);
    chassis.pid_wait_quick_chain();
    clamp1.extend();
    chassis.pid_wait();
    setIntake(127);
  
    chassis.pid_turn_set(-90, TURN_SPEED2);
    chassis.pid_wait();
  
    chassis.pid_drive_set(18, DRIVE_SPEED);
    chassis.pid_wait();
    setIntake(127);
    pros::delay(450);
  
  
    chassis.pid_turn_set(-177, TURN_SPEED); // turn to stack of 8 donuts
    chassis.pid_wait_quick_chain();
  
  //Right blue forward towards eight donuts
  
    chassis.pid_drive_set(9, DRIVE_SPEED); // move to second donut
      chassis.pid_wait();
    pros::delay(450); // intake the second donut
    // setIntake(0);
  
    chassis.pid_wait();
  
    chassis.pid_drive_set(RIGHTbluebyeautonline, DRIVE_SPEED); // move back to avoid autonomous line
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(-158, TURN_SPEED);//turn to third donut (beside second donut)
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(8.5, DRIVE_SPEED);// move towards third donut
    chassis.pid_wait();
    
    pros::delay(350);
  
    chassis.pid_drive_set(RIGHTblueback4, DRIVE_SPEED);// move away from auton line
    chassis.pid_wait_quick_chain();
  
    pros::delay(2000);
    setIntake(0);
  
    // chassis.pid_turn_set(50, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
  
    // chassis.pid_drive_set(56, DRIVE_SPEED);
    // chassis.pid_wait_until(40);
    // lifter.extend();
    // chassis.pid_wait_until(55);
    // lifter.retract();
    // setIntake(127);
    // pros::delay(600);
    // setIntake(0);
  
    // chassis.pid_drive_set(-6, DRIVE_SPEED);
    // chassis.pid_wait_quick_chain();
  
    // setIntake(127);
  
  }
  //WORKING feb 20
  void soloawpleftred() { 
  
    chassis.opcontrol_drive_activebrake_set(2.0);   
  
    wrongcolour = false;
    isRed = true;
    chassis.drive_angle_set(-90_deg);  // Start the robot facing 90 degrees
  
  
    lifter.extend();
    chassis.pid_turn_set(-130, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(9, slow_speed);
    chassis.pid_wait_quick_chain();
  
    lifter.retract();
    setIntake(127);
    pros::delay(525);
    setIntake(0);
  
    chassis.pid_drive_set(-1, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(-375, TURN_SPEED);
    chassis.pid_wait();
    // chassis.pid_turn_set(2.5, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(9.5, slow_speed);
  
    // chassis.pid_turn_set(355, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    // chassis.pid_drive_set(4, DRIVE_SPEED);
  
    chassis.pid_wait();
    
    target = 3000;
    lift_wait();
    chassis.pid_drive_set(-7, slow_speed);
    chassis.pid_wait_quick_chain();
    // liftPID.target_set(0);
    // lift_wait();
  
  
    chassis.pid_turn_set(-28, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-26.5, slow_speed);
    chassis.pid_wait_quick_chain();
    clamp1.extend();
    chassis.pid_wait();
    setIntake(127);
  
    chassis.pid_turn_set(90, TURN_SPEED2);
    chassis.pid_wait();
  
    chassis.pid_drive_set(22, DRIVE_SPEED);
    chassis.pid_wait();
  
    pros::delay(300);
  
  
    chassis.pid_turn_set(185, TURN_SPEED); // turn to stack of 8 donuts
    chassis.pid_wait_quick_chain();
  
  //Right blue forward towards eight donuts
  
    chassis.pid_drive_set(9, DRIVE_SPEED); // move to second donut
      chassis.pid_wait();
    pros::delay(250); // intake the second donut
    // setIntake(0);
  
    chassis.pid_wait();
  
  
  
    chassis.pid_drive_set(RIGHTbluebyeautonline, DRIVE_SPEED); // move back to avoid autonomous line
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(153, TURN_SPEED);//turn to third donut (beside second donut)
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(8.5, DRIVE_SPEED);// move towards third donut
    chassis.pid_wait();
    
  
  
    chassis.pid_drive_set(RIGHTblueback4, DRIVE_SPEED);// move away from auton line
    chassis.pid_wait_quick_chain();
  
    pros::delay(2000);
    setIntake(0);
  
    // chassis.pid_turn_set(50, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
  
    // chassis.pid_drive_set(56, DRIVE_SPEED);
    // chassis.pid_wait_until(40);
    // lifter.extend();
    // chassis.pid_wait_until(55);
    // lifter.retract();
    // setIntake(127);
    // pros::delay(600);
    // setIntake(0);
  
    // chassis.pid_drive_set(-6, DRIVE_SPEED);
    // chassis.pid_wait_quick_chain();
  
    // setIntake(127);
  
  }
  
  void goalrushleftblue() {
  
    chassis.opcontrol_drive_activebrake_set(2.0);  
  
    chassis.drive_angle_set(-21.04);//setting starting position so its ez as in ez template HAHAHAAHAH
  
    isRed = false;
  
    setIntake(127); //setting the intake just cause tahaha
    chassis.pid_drive_set(41, DRIVE_SPEED); // driving forward because it needs to drive forward
    chassis.pid_wait(); 
    pros::delay(550); //picking up blue donut. and red donut :(
    setIntake(0);
  
    setDoinker(-70); // putting down doinker and getting that goal because its a goal rush
    pros::delay(450);
    
    chassis.pid_wait();
  
    setIntake(-60); // ejecting the red that we probably picked up
  
    chassis.pid_drive_set(-15, slow_speed); // moving back that goal because its a goal rush
    chassis.pid_wait_until(-8);
    setIntake(0); // dont let that blue donut get out
  
    setDoinker(70); // bring the doinker up 
    pros::delay(500);
    setDoinker(0);
  
    chassis.pid_drive_set(-3, slow_speed); // moving back for positioning to clamp goal
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(176, TURN_SPEED); // turning backwards to get that goal
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(-19, slow_speed); // driving into goal to clamp
    chassis.pid_wait_quick_chain();
  
    clamp1.extend(); // clamp obviously
  
    setIntake(127); // put that blue donut on
    pros::delay(1000);
    setIntake(0);
  
  
  
    chassis.pid_drive_set(3, slow_speed); // idk prolly positioning to get other stake
    chassis.pid_wait_quick_chain();
  
    clamp1.retract(); // let go of that stake to get another one
  
    chassis.pid_turn_set(-90, TURN_SPEED); // turning to other stake
    chassis.pid_wait();
  
    chassis.pid_drive_set(-23, slow_speed); // moving to clamp stake
    chassis.pid_wait();
  
    clamp1.extend(); // also obviously a clamp
    chassis.pid_wait();
  
    setIntake(127); // lowk just wanted to turn on the intake but it works because it should
    chassis.pid_drive_set(24, DRIVE_SPEED); // moving forward for positioning to donut preload
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(170, TURN_SPEED); // turning to preload
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(30, DRIVE_SPEED); // moving to preload and getting it at the end of auton
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(-95, TURN_SPEED); // turning to clear positive corner
    chassis.pid_wait_quick_chain();
  
    setDoinker(-70); // getting ready to clear in driver control
    pros::delay(500);
    setDoinker(0);
  
    pros::delay(5000);
  
  }
  
  
  void goalrushrightred() {
  
    chassis.opcontrol_drive_activebrake_set(2.0);  
  
    chassis.drive_angle_set(-21.04);//setting starting position so its ez as in ez template HAHAHAAHAH
  
    isRed = true;
  
    setIntake(127); //setting the intake just cause tahaha
    chassis.pid_drive_set(41, DRIVE_SPEED); // driving forward because it needs to drive forward
    chassis.pid_wait(); 
    pros::delay(550); //picking up red donut. and blue donut :(
    setIntake(0);
  
    setDoinker(-70); // putting down doinker and getting that goal because its a goal rush
    pros::delay(450);
    
    chassis.pid_wait();
  
    setIntake(-60); // ejecting the blue that we probably picked up
  
    chassis.pid_drive_set(-15, slow_speed); // moving back that goal because its a goal rush
    chassis.pid_wait_until(-8);
    setIntake(0); // dont let that red donut get out
  
    setDoinker(70); // bring the doinker up 
    pros::delay(500);
    setDoinker(0);
  
    chassis.pid_drive_set(-3, slow_speed); // moving back for positioning to clamp goal
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(176, TURN_SPEED); // turning backwards to get that goal
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(-18, slow_speed); // driving into goal to clamp
    chassis.pid_wait_quick_chain();
  
    clamp1.extend(); // clamp obviously
  
    setIntake(127); // put that red donut on
    pros::delay(1000);
    setIntake(0);
  
    clamp1.retract(); // let go of that stake to get another one
  
    chassis.pid_drive_set(3, slow_speed); // idk prolly positioning to get other stake
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(90, TURN_SPEED); // turning to other stake
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(-27, slow_speed); // moving to clamp stake
    chassis.pid_wait_quick_chain();
  
    clamp1.extend(); // also obviously a clamp
  
    chassis.pid_wait_quick_chain();
    setIntake(127); // lowk just wanted to turn on the intake but it works because it should
    chassis.pid_drive_set(24, DRIVE_SPEED); // moving forward for positioning to donut preload
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(180, TURN_SPEED); // turning to preload
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(28, DRIVE_SPEED); // moving to preload and getting it at the end of auton
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(95, TURN_SPEED); // turning to clear positive corner
    chassis.pid_wait_quick_chain();
  
    setDoinker(-70); // getting ready to clear in driver control
    pros::delay(500);
    setDoinker(0);
  
    pros::delay(2500);
  
  
    // setIntake(127);
    // pros::delay(300);
    // setIntake(0);
  
    // chassis.pid_turn_set(135, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
  
    // chassis.pid_drive_set(-18, DRIVE_SPEED);
    // chassis.pid_wait_quick_chain();
  
  
  
    // pros::delay(3000);
    // setIntake(0);
  
  
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
  
  
    chassis.pid_turn_set(RIGHTblueturn2, TURN_SPEED); // turn to first donut
    chassis.pid_wait();
  
    chassis.pid_drive_set(RIGHTblueforward, DRIVE_SPEED);// move to first donut
    chassis.pid_wait();
  
  //Pick up first floor donut
  
    // setIntake(127);
    pros::delay(delay_2); // intake first donut
    // setIntake(0);
  
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
  
    chassis.pid_drive_set(21, DRIVE_SPEED); // move towards first donut
    chassis.pid_wait();
  
  //Picking up first donut
  
    setIntake(127);
    pros::delay(delay_2); // pick up first donut
    //setIntake(0);
  
    chassis.pid_turn_set(LEFTredturn3, TURN_SPEED); // turn to stack of 8 donuts
    chassis.pid_wait();
  
  //left red forward towards eight donuts
  
    chassis.pid_drive_set(10, DRIVE_SPEED); // move to second donut
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
  
    chassis.pid_turn_set(160, TURN_SPEED);//turn to third donut (beside second donut)
    chassis.pid_wait();
  
    // chassis.pid_drive_set(5, DRIVE_SPEED);// move towards third donut
    // chassis.pid_wait();
    // pros::delay(200);
    // setIntake(127);
  
    
    // chassis.pid_drive_set(LEFTredback4, DRIVE_SPEED);// move away from auton line
    // chassis.pid_wait();
  
    chassis.pid_turn_set(LEFTredturn5, TURN_SPEED);// turn to negatives
    chassis.pid_wait();
  
    chassis.pid_drive_set(LEFTredforward5, FULL_SPEED);// go to negatives
    chassis.pid_wait();
  
    pros::delay(delay_3);
    setIntake(0);
  }
  
  void robotskillsv2() { //drop preload //THIS WORKS ONE SIDE 2025-02-19
    setIntake(127);
    pros::delay(1500);
    
    chassis.pid_drive_set(8, slow_speed);
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(90, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-18, slow_speed);
    chassis.pid_wait_quick_chain();
    clamp1.extend();
    chassis.pid_wait();
    chassis.pid_turn_set(-5, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(12, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(-45, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(29_in, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(-90, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(6, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-3, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(178, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(47, 40);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(-55, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(10, slow_speed);
    chassis.pid_wait();
    chassis.pid_turn_set(30, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-1, slow_speed);
    chassis.pid_wait_quick_chain();
    setIntake(-127);
    pros::delay(300);
    setIntake(127);
    pros::delay(2000);
    setIntake(-100);
    pros::delay(400);
    setIntake(0);
    clamp1.retract();
  
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(10, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(90, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(48, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
  
  }
  
  void robotskillsv2sides() { //WORKING VERY SIGMA february 20th
    setIntake(127);
    pros::delay(1500);
    
    chassis.pid_drive_set(8, slow_speed);
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(90, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-18, slow_speed);
    chassis.pid_wait_quick_chain();
    clamp1.extend();
    chassis.pid_wait();
    chassis.pid_turn_set(-5, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(14, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(-45, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(30.5_in, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(-95, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(6, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-3, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(178, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(50, 40); //Going in a straight line SLOWLY
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(-55, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(10, slow_speed);
    chassis.pid_wait();
    chassis.pid_turn_set(30, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-5, slow_speed);
    chassis.pid_wait_quick_chain();
    // pros::delay(700);
    // setIntake(-127);
    // pros::delay(300);
    // setIntake(127);
    pros::delay(2000);
    setIntake(-100);
    pros::delay(400);
    setIntake(0);
    clamp1.retract();
  
    chassis.pid_wait_quick_chain();
  
    pros::delay(45);
  
    chassis.pid_drive_set(6, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(90, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(38, slow_speed);
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(-90, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-31, slow_speed); //back into second clamp
    chassis.pid_wait();
    clamp1.extend();
    chassis.pid_wait();
  
    setIntake(127);
  
    chassis.pid_turn_set(5, slow_speed);// turn to first donut
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(14, slow_speed);//go to first donut
    chassis.pid_wait_quick_chain();
    pros::delay(500);//wait because it wont work
    chassis.pid_turn_set(40, TURN_SPEED); // turn to position to far donut
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(33_in, slow_speed); // move to positioning for far donut
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(87, TURN_SPEED); // turn to far donut
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(6, slow_speed); // get far donut
    chassis.pid_wait_quick_chain();
    pros::delay(450);
    chassis.pid_drive_set(-4, slow_speed);// position to drive in straight line to get lots of donuts
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(-178, TURN_SPEED); // turn to line of donuts
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(49, 40); //Going in a straight line SLOWLY
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(55, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(10, slow_speed);
    chassis.pid_wait();
    chassis.pid_turn_set(-30, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-6, slow_speed);
    chassis.pid_wait_quick_chain();
    // pros::delay(300);
    // setIntake(-127);
    // pros::delay(300);
    // setIntake(127);
    pros::delay(2000);
    setIntake(-100);
    pros::delay(400);
    setIntake(0);
    clamp1.retract();
    chassis.pid_drive_set(9, slow_speed);
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
    pros::delay(1500); // intake first donut
    // setIntake(0);
  
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
  
  
    // Pick up second raised donut
    // setIntake(127);
    // pros::delay(delay_3b);
    // setIntake(0);
  
    chassis.pid_drive_set(LEFTredback3b, DRIVE_SPEED); // move back and avoid picking up red donut
    chassis.pid_wait_quick_chain();
  
    setIntake(127);
    pros::delay(300); // load second donut onto stake
  
  
    chassis.pid_drive_set(-10, slow_speed); // shake second donut onto stake just in case
    chassis.pid_wait();
  
    chassis.pid_turn_set(90, TURN_SPEED);
    chassis.pid_wait_quick_chain();
  
    chassis.pid_drive_set(27, DRIVE_SPEED);
    chassis.pid_wait_quick_chain();
  
    chassis.pid_turn_set(5, TURN_SPEED);
    chassis.pid_wait_quick_chain();
  
    setDoinker(-100);
    pros::delay(400);
  
    // chassis.pid_drive_set(14, DRIVE_SPEED);
    // chassis.pid_wait_quick_chain();
  
    // chassis.pid_turn_set(-90, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
  
    setIntake(0);
  
  
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
  
  // void sigma_robotskills() {
  
  //   isRed = true; //Team RED
  
  //   //Starting (backing up)
  //   chassis.pid_drive_set(robotskillsback, DRIVE_SPEED);
  //   chassis.pid_wait();
  
  //   //Turn towards stake
  //   chassis.pid_turn_set(robotskillsturn, TURN_SPEED);
  //   chassis.pid_wait();
  
  //   //Slowly move towards stake
  //   chassis.pid_drive_set(robotskillsback2, slow_speed);
  //   // chassis.pid_wait_until(18);
  //   //Secure stake
  //   clamp1.extend();
  //   chassis.pid_wait();
  
  
  //   //Turning towards 1st donut
  //   chassis.pid_turn_set(robotskillsturn2, TURN_SPEED);
  //   chassis.pid_wait();
  
  //   //Drives towards 1st donut and secures preload and 1st donut
  //   chassis.pid_drive_set(robotskillsforward, DRIVE_SPEED);
  //   // chassis.pid_wait_until(16);
  //   setIntake(127);
  //   //pros::delay(delay_3c);
  //   chassis.pid_wait();
  //   pros::delay(delay_3c);
    
  //   //Turn towards 2nd donut
  //   chassis.pid_turn_relative_set(robotskillsturnb, TURN_SPEED);
  //   chassis.pid_wait();
  
  //   //Forward towards 2nd donut
  //   chassis.pid_drive_set(robotskillsforward, DRIVE_SPEED);
  //   // chassis.pid_wait_until(16);
  //   //setIntake(127);
  //   //pros::delay(delay_3c);
  //   chassis.pid_wait();
  //   pros::delay(delay_3c);
  
  //   //Turn towards 3rd donut
  //   chassis.pid_turn_set(robotskillsturn3, TURN_SPEED);
  //   chassis.pid_wait();
  
  //   //Drive forward to 3rd and 4th donut
  //   chassis.pid_drive_set(robotskillsforward, DRIVE_SPEED1);
  //   // chassis.pid_wait_until(16);
  //   //setIntake(127);
  //   //pros::delay(delay_3c);
  //   chassis.pid_wait();
  
  //   //Moving to 4th donut
  //   chassis.pid_drive_set(robotskillsforward2, DRIVE_SPEED1);
  //   chassis.pid_wait();
  
  //   // go backwards to not hit the wall
  //   chassis.pid_drive_set(robotskillsback3, slow_speed);
  
  //   //Turn to 5th donut
  //   chassis.pid_turn_set(robotskillsturn4, TURN_SPEED);
  //   chassis.pid_wait();
  
  //   //Drive forward and secures 5th donut
  //   chassis.pid_drive_set(robotskillsforward3, DRIVE_SPEED1);
  //   // chassis.pid_wait_until(10);
  //   //pros::delay(delay_3c);
  //   chassis.pid_wait();
  //   pros::delay(delay_3c);
  
  //   setIntake(0);
  //   chassis.pid_wait();
  
  //   // roll intake back so we dont hook onto donut on stake
  //   setIntake(robotskillsintakeback);
  //   pros::delay(500);
  //   setIntake(0);
  
  //   // turn before backing up into corner
  //   chassis.pid_turn_set(robotskillsturn5, TURN_SPEED);
  //   chassis.pid_wait();
  
  //   // back into corner
  //   chassis.pid_drive_set(robotskillsback4, DRIVE_SPEED);
  //   chassis.pid_wait();
  
  //   // let it go
  //   clamp1.retract();
  //   pros::delay(1000);
  
  //   // move forward after backing into corner
  //   chassis.pid_drive_set(robotskillsforward4, DRIVE_SPEED);
  //   chassis.pid_wait();
  
  // }
  
  
  void skibidi_rizz() {
    chassis.pid_odom_set(24, 100, true);
  
  }