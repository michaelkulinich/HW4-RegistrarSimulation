#include "Simulation.h"
#include "Window.h"
#include "Student.h"


Simulation::Simulation(){

}
Simulation::~Simulation(){

}

void Simulation::run(){

}

void Simulation::readFile(string inputFile)
{
    string line; //used to read line by line from file
    lineCount = 0; //find what line is being read in the file
    inFile.open(inputFile);
      if(!inFile)
      {
        cout << "unable to open file: " << inputFile << endl;
        exit(1);
      }

      while (inFile >> line)
      {
          if(lineCount == 0){ // number of windows
              openWindows = stoi(line);
              Window registrarWindow(openWindows);
          }
          else if(lineCount == 1){
              

          }
          else if(line count == 2){

          }

      }


}
