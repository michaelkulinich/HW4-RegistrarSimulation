//#include<iostream>
#include "Window.h"


using namespace std;

Window::Window(int numWindows)
{
    arrSize = numWindows;
    windowArray = new int[arrSize];
    for (int i = 0; i < arrSize; ++i)
    {
        windowArray[i] = 0;
        cout << windowArray[i] << endl;
    }
}

Window::~Window()
{

}

int Window::getNumOpenWindows()
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

void Window::printWindows(){
    for (int i = 0; i < arrSize; ++i)
    {
        cout << "Student: " <<i+1 << " Time needed: " << windowArray[i] << endl;
    }
}
