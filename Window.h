/*Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu


Window.h
This is h file for Window class

In this class, a window of type int is created to hold the current time needed for students.
*/
#include<iostream>
#include "Student.h"

using namespace std;

class Window
{
  public:
    Window(int numWindows);
    ~Window();

    int getNumOpenWindows();
    void fillWindow(Student *s);
    void printWindows();
    bool windowsEmpty(); //used at the end of the program to make sure all windows are empty,
    // (cont) allows for window calculations to run smoothly

    int idleTime;
    int *windowArray;
    int arrSize;
};
