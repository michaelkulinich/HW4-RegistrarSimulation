/*Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu


Student.h
This is h file for Student class

In this class, a student is created with their necessary varibles
*/
#include <iostream>

using namespace std;

class Student
{
    public:
        Student(int timeNeeded, int arrivalTick);
        ~Student();

        // Variables
        int idleTime;
        int timeNeeded;
        int arrivalTick;
};
