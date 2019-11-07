/*Michael Kulinich
2328386
kulinich@chapman.edu
Matthew Nwerem
2277158
nwere100@mail.chapman.edu


FileHelper.cpp
*/

#include "Simulation.h"
#include <vector>
#include <algorithm>


using namespace std;

Simulation::Simulation(string inputFile){//input file
    this->inputFile = inputFile;
}
Simulation::~Simulation(){
    delete s;
    delete myWindow;
}

void Simulation::run(){
    readFile();
    analyzeFileInfo();
    createQueue();
    createWindow();
    int round = 1;
    totalStudentWaitTime = 0;
    tenMinuteWaitTime = 0;
    maxWaitTime = 0;
    clockTick = 0;


    while(!myQueue->isEmpty()){


        //while to fill up the emtpy windows for the students that have arrived at or before the clock tick
        while((!myQueue->isEmpty()) && (myWindow->getNumOpenWindows() != 0) && (myQueue->peek()->arrivalTick <= clockTick)){

            //fill any windows that are open with the
            myWindow->fillWindow(myQueue->peek());

            //vector used to find the median of all the wait times
            vectorStudentWaitTimes.push_back(myQueue->peek()->arrivalTick);
            //if the a window is open, increase it window idle time

            //
            //regarding student variables
            //

            //checking for max wait time of student
            if(clockTick-(myQueue->peek()->arrivalTick) > maxWaitTime){
                maxWaitTime = clockTick-(myQueue->peek()->arrivalTick);
            }

            //cheching for number of students waiting over 10 minutes
            if(clockTick-(myQueue->peek()->arrivalTick ) >= 10){
                tenMinuteWaitTime++;
            }

            //sum up the total student wait time
            totalStudentWaitTime += clockTick-myQueue->peek()->arrivalTick;

            //remove the student from the queue
            myQueue->remove();

            //once all of the students that can go into the windows
            //at the current clock tick have went, we incriment the number
            //of idle winodws if there are any
            if(!myQueue->isEmpty()){
                //if we got every student that has arrived has entered
                if(myQueue->peek()->arrivalTick > clockTick){
                    for(unsigned int i = 0; i < myWindow->arrSize; i++){
                        if(myWindow->windowArray[i] == 0){
                            vectorWindowIdleTimes.at(i)++;
                        }
                    }
                }
            }
        }


        clockTick++;
        for(int i = 0; i < myWindow->arrSize; ++i){
            //if all no students are ready to come into the windows
            //then increase the window idle times
            if(myWindow->windowArray[i] == 0){
                vectorWindowIdleTimes.at(i)++;
            }

            //if the window has a student in it
            //then decrement the amount of time the student needs
            if(myWindow->windowArray[i] != 0){
                myWindow->windowArray[i]--;
            }
        }
    }

    //once the queue is empty, then now only the window has students
    while(!myWindow->windowsEmpty()){
        for(unsigned int i = 0; i < myWindow->arrSize; i++){
            //we increase each windows idle time
            if(myWindow->windowArray[i] == 0){
                vectorWindowIdleTimes.at(i)++;
            }
            //decrement the time needed for the student in the window
            if(myWindow->windowArray[i] != 0){
                myWindow->windowArray[i]--;
            }
        }
    }
    //
    //
    //regarding student variables
    //
    //
    sort(vectorStudentWaitTimes.begin(), vectorStudentWaitTimes.end());
    int size = vectorStudentWaitTimes.size();
    //then find median
    medianStudentWaitTime = vectorStudentWaitTimes.at((size -1)/ 2);
    meanStudentWaitTime = double(totalStudentWaitTime)/double(totalNumStudents);

    //
    //regarding the windows
    //
    //

    //gets the totalWindowIdleTime
    maxWindowIdleTime = 0;
    numWindowsFiveMinuteIdleTime = 0;
    for(int i = 0; i < vectorWindowIdleTimes.size(); i++){
        //find the total
        totalWindowIdleTime += vectorWindowIdleTimes.at(i);

        //find the max window idle time
        if(maxWindowIdleTime < vectorWindowIdleTimes.at(i)){
            maxWindowIdleTime = vectorWindowIdleTimes.at(i);
        }

        if(vectorWindowIdleTimes.at(i) >= 5){
            numWindowsFiveMinuteIdleTime++;
        }
    }
    meanWindowIdleTime = double(totalWindowIdleTime)/double(myWindow->arrSize);

    cout << "totalStudentWaitTime: " << totalStudentWaitTime << endl ;
    cout << "tenMinuteWaitTime: " << tenMinuteWaitTime << endl;
    cout << "maxWaitTime: " << maxWaitTime << endl;
    cout <<  "medianStudentWaitTime: " << medianStudentWaitTime << endl;
    cout <<  "meanStudentWaitTime: " << meanStudentWaitTime << endl;
    cout << "totalWindowIdleTime: " << totalWindowIdleTime << endl;
    cout <<  "maxWindowIdleTime: " << maxWindowIdleTime << endl;
    cout << "meanWindowIdleTime: " << meanWindowIdleTime << endl;

}

void Simulation::readFile()
{
    string line; //used to read line by line from file
    inFile.open(inputFile);
    if(!inFile)
    {
        cout << "unable to open file: " << inputFile << endl;
        exit(1);
    }

    while (inFile >> line)
    {
        vectorFileInfo.push_back(stoi(line));
    }
    inFile.close();
}

void Simulation::analyzeFileInfo(){
    numOpenWindows = vectorFileInfo.at(0);
    int total = 0;
    int indexNumStudents = 2; //the index in the vector where it says the number of students
    int numStudents = vectorFileInfo.at(indexNumStudents);//the number of students at a certain clock tick
    int count = 0;
    while(true){
        if(numStudents > 0){
            total += numStudents;
            //the for loop adds to the vector of each students time needed
            //each index of this vector and vectorTimeArrived correspond to the same student
            for(int i = 1; i <= numStudents; ++i){
                vectorTimePerStudent.push_back(vectorFileInfo.at(indexNumStudents+i));
                vectorTimeArrived.push_back(vectorFileInfo.at(indexNumStudents-1));
            }

            //to control when the file is fully read
            if(indexNumStudents + numStudents < vectorFileInfo.size()-1){
                //total += numStudents;
                indexNumStudents += numStudents + 2;
                numStudents = vectorFileInfo.at(indexNumStudents);
            }

            //once we read the whole file, total up the students and break
            else{
                totalNumStudents = total;
                break;
            }
        }
        else{
            cout << "File info is improper" << endl;
            exit(1);
        }
    }
}

void Simulation::printStudentTimeNeeded(){
    cout << "Time needed for each student:\n";
    for(int i = 0; i < totalNumStudents; i++){
        cout << "Student " << i + 1 << " : " << vectorTimePerStudent.at(i) << endl;
    }
}

void Simulation::printStudentArrivalTime(){
    cout << "Arrival clock tick of each student:\n";
    for(int i = 0; i < totalNumStudents; i++){
        cout << "Student " << i + 1 << " : " << vectorTimeArrived.at(i) << endl;
    }
}


void Simulation::createQueue(){
    myQueue = new GenQueue<Student>();
    for(int i = 0; i < totalNumStudents; ++i ){
        s = new Student(vectorTimePerStudent.at(i), vectorTimeArrived.at(i));
        myQueue->insert(s);
    }
}

void Simulation::createWindow(){
    myWindow = new Window(numOpenWindows);
    for(int i = 0; i < numOpenWindows; ++i){
        vectorWindowIdleTimes.push_back(0);
    }
}
