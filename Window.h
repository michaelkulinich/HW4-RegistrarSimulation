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



    int idleTime;
    int *windowArray;
    int arrSize;

};
