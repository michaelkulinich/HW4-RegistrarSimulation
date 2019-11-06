#include<iostream>
#include "Student.h"

using namespace std;

class Window
{
  public:
    Window(int numWindows);
    ~Window();

    int getOpenWindows();
    void fillWindow(Student *s);

    int idleTime;
    int arrSize;
    int *windowArray;
};
