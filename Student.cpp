#include "Student.h"
#include <iostream>
using namespace std;

// Student::Student(){
//
// }
Student::Student(int d){
    id = d;
}

Student::~Student(){

}

int Student::getId(){
    return id;
}
