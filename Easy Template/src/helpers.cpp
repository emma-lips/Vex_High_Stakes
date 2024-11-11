#include "main.h"

void setIntake(int intakePower){
    intake11W.move(intakePower);
}

void clampSwitch(){
    if(clamp1.is_extended()){
        clamp1.retract():
    }
        if(clamp1.is_retracted()){
        clamp1.extend():
    }
}

//setIntake(127);

//setIntake(0);