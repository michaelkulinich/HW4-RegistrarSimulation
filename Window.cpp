#include<iostream>
#include "Window.h"

using namespace std;

Window::Window(int numWindows)
{
  int arrSize = numWindows;
  windowArray = new int[numWindows];
  for (int i = 0; i < arrSize; ++i)
  {
    windowArray[i] = 0;
}
}

Window::~Window()
{

}

int Window::getOpenWindows()
{
  int numOpen;
  for (int i = 0; i < arrSize; ++i)
  {
    if (windowArray[i] == 0)
    {
      ++numOpen;
    }
  }
  return numOpen;
}

void Window::fillWindow(Student *S){ //put in the student into the window
    for (int i = 0; i < arrSize; ++i)
    {
      if (windowArray[i] == 0)
      {
          windowArray[i] = S->timeNeeded;
          break;
      }
    }
}
