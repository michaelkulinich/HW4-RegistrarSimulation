#include "Student.h"
#include <iostream>
using namespace std;

// Student::Student(){
//
// }
Student::Student(int timeNeeded, int arrivalTick){
    this->timeNeeded = timeNeeded;
    this->arrivalTick = arrivalTick;
    idleTime = 0;
}

Student::~Student(){

}
