#include "main.h"

void setIntake(int intakePower){
    intake11W.move(intakePower);
}

void set_lift(int input) {
  lb.move(input);

}

void setDoinker(int doinkerPower){
    doinker5W.move(doinkerPower);
}

// void distancify()

void setDoinkerPOS(int deg, int speed) {
    doinker5W.move_absolute(deg, speed);
}

//void clampSwitch(){
 //   if(clamp1.is_extended()){
 //       clamp1.retract():
 //   }
 //       if(clamp1.is_retracted()){
 //       clamp1.extend():
 //   }
//}

//setIntake(127);

//setIntake(0);