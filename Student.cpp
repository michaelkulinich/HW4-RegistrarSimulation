/*Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu


Student.cpp
This is cpp file for Student class

In this class, a student is created with their necessary varibles
*/
#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(int timeNeeded, int arrivalTick)
{
    this->timeNeeded = timeNeeded;
    this->arrivalTick = arrivalTick;
    idleTime = 0;
}

Student::~Student()
{

}
