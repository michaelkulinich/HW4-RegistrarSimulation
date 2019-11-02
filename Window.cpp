#include<iostream>
#include "Student.h"
#include "Window.h"

using namespace std;

Window::Window(int numWindows)
{
  int arrSize = numWindows;
  int windowArray[numWindows];
}

Window::~Window()
{

}

int Window::getOpenWindows()
{
  int numOpen;
  for (int i = 0; i < arrSize; ++i)
  {
    if (windowArray[i] == NULL)
    {
      ++numOpen;
    }
  }
  return numOpen;
}
