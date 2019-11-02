#include<iostream>

using namespace std;

class Window
{
  public:
    Window(int numWindows);
    ~Window();

    int getOpenWindows();

    int idleTime;
    int arrSize;
    int *windowArray;
};
