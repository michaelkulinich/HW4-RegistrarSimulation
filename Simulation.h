#include <iostream>
#include <fstream>
#include <vector>
#include "GenQueue.h"
#include "Window.h"

using namespace std;


class Simulation {
    public:
        //constructor
        Simulation(string inputFile);//input file
        ~Simulation();

        //methods
        void run();

        //create a vector that is the same as the file for easier access later
        void readFile();

        //take in the vector(created from readFile()) to gather all the necessary information to create our students
        void analyzeFileInfo();
        void printStudentTimeNeeded();
        void printStudentArrivalTime();
        void createQueue();
        void createWindow();


        //variables
        ifstream inFile;
        int lineCount;
        int openWindows;
    private:
        int totalStudentWaitTime;
        int tenMinuteWaitTime;
        int maxWaitTime;
        int medianStudentWaitTime;
        string inputFile;
        int clockTick; // the clock tick of the simulation
        int numOpenWindows;
        int totalNumStudents;
        //vector variables to examine the data from the file and will be used to create each Student
        vector<int> vectorFileInfo; //a vector representation of the file
        vector<int> vectorTimePerStudent; //a vector of the time needed for each student in order
        vector<int> vectorTimeArrived; //a vector of the clock tick the student arrives in order
        vector<int> vectorStudentWaitTimes;
        Window *myWindow;
        GenQueue<Student> *myQueue;
        Student *s;



};
