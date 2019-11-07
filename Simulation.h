/*Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu


Simulation.h
This is a header file that will simulate
the registrars office. This class will create Students,
queues, and windows to properly simulate the office and gather the necessary data
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "GenQueue.h"
#include "Window.h"

using namespace std;


class Simulation {
    public:
        //constructor
        Simulation(string inputFile);

        //destructor
        ~Simulation();

        //methods
        void run();

        //create a vector that is the same as the file for easier access later
        void readFile();

        //take in the vector(created from readFile()) to gather all the necessary information to create our students
        void analyzeFileInfo();

        //create a queue of students. After reading the file we know how many
        //students there are and what there info is so
        //we create a queue of all of them
        void createQueue();

        //create a window that will hold integers
        void createWindow();

        //helper methods to print info
        void printStudentTimeNeeded();
        void printStudentArrivalTime();



        //variables
        ifstream inFile;
        int lineCount;
        int openWindows;
    private:
        //variables to handle the student data we need to collect
        int totalStudentWaitTime;
        int tenMinuteWaitTime;
        int maxWaitTime;
        int medianStudentWaitTime;
        double meanStudentWaitTime;

        //variables to hadle the window data we need to collect
        int totalWindowIdleTime;
        int maxWindowIdleTime;
        double meanWindowIdleTime;
        int numWindowsFiveMinuteIdleTime;

        string inputFile;
        int clockTick; // the clock tick of the simulation
        int numOpenWindows; //number of windows open in the windows
        int totalNumStudents;
        //vector variables to examine the data from the file and will be used to create each Student
        vector<int> vectorFileInfo; //a vector representation of the file
        vector<int> vectorTimePerStudent; //a vector of the time needed for each student in order
        vector<int> vectorTimeArrived; //a vector of the clock tick the student arrives in order
        vector<int> vectorStudentWaitTimes;
        vector<int> vectorWindowIdleTimes;
        Window *myWindow;
        GenQueue<Student> *myQueue;
        Student *s;



};
