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
    bool windowsEmpty(); //used at the end of the program to make sure all windows are empty, allows for window calculations to run smoothly



    int idleTime;
    int *windowArray;
    int arrSize;

};
