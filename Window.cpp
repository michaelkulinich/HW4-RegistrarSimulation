/*Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu


Window.cpp
This is cpp file for Window class

In this class, a window of type int is created to hold the current time needed for students.
*/
#include "Window.h"


using namespace std;

Window::Window(int numWindows)
{
    arrSize = numWindows;
    windowArray = new int[arrSize]; //creates array
    for (int i = 0; i < arrSize; ++i)
    {
        windowArray[i] = 0; //every value in array of windows starts as 0
    }
}

Window::~Window()
{
  delete windowArray;
}

// Checks to see how many windows are open. used as a check for stopping simulation and idleTime
int Window::getNumOpenWindows()
{
  int numOpen = 0;
  for (int i = 0; i < arrSize; ++i)
  {
    if (windowArray[i] == 0)
    {
      ++numOpen;
    }
  }
  return numOpen;
}

void Window::fillWindow(Student *S)
{ // Puts students (specifically timeNeeded @ window) into the windowArray
    for (int i = 0; i < arrSize; ++i)
    {
      if (windowArray[i] == 0)
      {
          windowArray[i] = S->timeNeeded;
          break;
      }
    }
}

void Window::printWindows()
{
    for (int i = 0; i < arrSize; ++i)
    {
        cout << "Window: " <<i+1 << " Time needed: " << windowArray[i] << endl;
    }
}

// Used when trying to complete simulation. When windows are empty and queue isEmpty
// The simulation can stop and data can be calculated
bool Window::windowsEmpty()
{
    for (int i = 0; i < arrSize; ++i)
    {
        if (windowArray[i] != 0)
        return false;
    }
    return false;
}
