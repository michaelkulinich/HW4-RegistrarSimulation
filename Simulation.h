#include <iostream>
#include <fstream>

using namespace std;


class Simulation {
    public:
        //constructor
        Simulation();
        ~Simulation();

        //methods
        void run();
        void readFile()

        //variables
        ifstream inFile;
        string inputFile;
        int lineCount;
        int openWindows;


}
