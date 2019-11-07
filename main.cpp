#include "Simulation.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Simulation mySim(argv[1]);
    mySim.run();
    return 0;
}
