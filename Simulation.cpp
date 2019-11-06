#include "Simulation.h"
#include <vector>
//#include "Window.h"
//#include "Student.h"

using namespace std;


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


    //this is just to check the queue
    for(int i = 0; i < totalNumStudents; ++i ){
        s = new Student(vectorTimePerStudent.at(i), vectorTimeArrived.at(i));
        myQueue->insert(s);
        cout << endl;
        cout << "Student " << i + 1 << ":\nTime needed at window: " << myQueue->theList->front->data->timeNeeded << endl;
        cout << "Arrival clock tick: " << myQueue->theList->front->data->arrivalClick << endl;
        delete s;
    }

}

void Simulation::createWindow(){
    // myWindow = new Window(numOpenWindows);
    //
}
