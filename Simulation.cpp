#include "Simulation.h"
#include <vector>
#include <algorithm>
//#include "Student.h"

using namespace std;




/*
myQueue->theList->front->data->timeNeeded
CHange this Every where I do this
*/
Simulation::Simulation(string inputFile){//input file
    this->inputFile = inputFile;
}
Simulation::~Simulation(){

}

void Simulation::run(){
    readFile();
    analyzeFileInfo();
    printStudentTimeNeeded();
    printStudentArrivalTime();
    createQueue();
    createWindow();
    int round = 1;
    totalStudentWaitTime = 0;
    tenMinuteWaitTime = 0;
    maxWaitTime = 0;
    clockTick = 0;


    while(!myQueue->isEmpty()){
        cout << "numWindows open " << myWindow->getNumOpenWindows() << endl;
        cout << "ArrivalTick " << myQueue->peek()->arrivalTick << endl;
        //fill up the emtpy windows
        while((myWindow->getNumOpenWindows() != 0) && (myQueue->peek()->arrivalTick <= clockTick)){

            cout << "check " << round << endl;
            round++;
            //to find the median of all the wait times
            vectorStudentWaitTimes.push_back(myQueue->peek()->arrivalTick);

            //checking for max wait time
            if(clockTick-(myQueue->peek()->arrivalTick) > maxWaitTime){
                maxWaitTime = clockTick-(myQueue->peek()->arrivalTick);
            }

            //chekcing for number of students waiting over 10 minutes
            if(clockTick-(myQueue->peek()->arrivalTick >= 10)){
                tenMinuteWaitTime++;
            }

            //sum up the total student wait time
            totalStudentWaitTime += (clockTick-myQueue->peek()->arrivalTick);
            myWindow->fillWindow(myQueue->remove());
        }
        clockTick++;
        for(int i = 0; i < myWindow->arrSize; ++i){
            if(myWindow->windowArray[i] != 0){
                myWindow->windowArray[i]--;
            }
        }


    }

    cout << "check 1" << endl;
    sort(vectorStudentWaitTimes.begin(), vectorStudentWaitTimes.end());
    cout << "check 2" << endl;
    int size = vectorStudentWaitTimes.size();   // might have to make this unsigned
    //then find median
    cout << "check 3" << endl;
    medianStudentWaitTime = vectorStudentWaitTimes.at((size -1)/ 2);
cout << "check 4" << endl;

    myWindow->printWindows();
    cout << "clock tick" << clockTick << endl;

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

 // change the parameter to totalNumStudents for for loop
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
    //
    // s = new Student(vectorTimePerStudent.at(0), vectorTimeArrived.at(0));
    // myQueue->insert(s);
    // s1 = new Student(vectorTimePerStudent.at(1), vectorTimeArrived.at(1));
    // myQueue->insert(s1);
    //
    // s2 = new Student(vectorTimePerStudent.at(2), vectorTimeArrived.at(2));
    // myQueue->insert(s2);
    //
    // s3 = new Student(vectorTimePerStudent.at(3), vectorTimeArrived.at(3));
    // myQueue->insert(s3);
    //
    // s4 = new Student(vectorTimePerStudent.at(4), vectorTimeArrived.at(4));
    // myQueue->insert(s4);
    //
    // for(int i = 0; i <totalNumStudents; i++){
    //     cout << endl;
    //     cout <<  "Student " << i + 1 << ":\nTime needed at window: " << myQueue->remove()->timeNeeded << endl;
    //     //cout << "Student " << i + 1 << ":\nTime needed at window: " << myQueue->theList->front->data->timeNeeded << endl;
    //     //cout << "Arrival clock tick: " << myQueue->theList->front->data->arrivalTick << endl;
    // }


    for(int i = 0; i < totalNumStudents; ++i ){
        s = new Student(vectorTimePerStudent.at(i), vectorTimeArrived.at(i));
        myQueue->insert(s);
        // cout << endl;
        // cout << "Student " << i + 1 << ":\nTime needed at window: " << myQueue->theList->front->data->timeNeeded << endl;
        // cout << "Arrival clock tick: " << myQueue->theList->front->data->arrivalTick << endl;
        //delete s;
    }
    // for(int i = 0; i <totalNumStudents; i++){
    //     cout << endl;
    //     cout <<  "Student " << i + 1 << ":\nTime needed at window: " << myQueue->remove()->timeNeeded << endl;
    // }

}

void Simulation::createWindow(){
    myWindow = new Window(numOpenWindows);

}
