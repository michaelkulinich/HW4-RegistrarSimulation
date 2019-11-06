#include "Student.h"
#include <iostream>
using namespace std;

// Student::Student(){
//
// }
Student::Student(int timeNeeded, int arrivalClick){
    this->timeNeeded = timeNeeded;
    this->arrivalClick = arrivalClick;
    idleTime = 0;
}

Student::~Student(){

}
