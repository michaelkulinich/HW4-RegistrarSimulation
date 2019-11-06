//#include "Student.h"
#include "Window.h"
// #include "GenQueue.h"
//#include "DoublyListNode.h"
//#include "Simulation.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    // Student myStudent(5, 10);
    // cout << myStudent.timeNeeded << endl;
    // cout << myStudent.arrivalClick << endl;


    Window myWindow(5);
    Student *myStudent = new Student(5,10);
    Student *myStudent1 = new Student(6,10);
    Student *myStudent2 = new Student(7,10);
    myWindow.fillWindow(myStudent);
    myWindow.fillWindow(myStudent1);
    myWindow.fillWindow(myStudent2);

    myWindow.printWindows();
    cout << "h" << endl;
    // Simulation mySim(argv[1]);
    // mySim.run();
    //
    //
    // mySim.readFile();
    //
    // mySim.analyzeFileInfo();
    // mySim.printStudentTimeNeeded();
    // mySim.printStudentArrivalTime();
    //
    // mySim.createQueue();





     // GenQueue<Student> *myQueue = new GenQueue<Student>();
     // Student *myStudent = new Student(123);
     // myQueue->insert(myStudent);
     // cout << myQueue->theList->front->data->getId() << endl; //basically a peak
     //










     // Student s = myQueue->remove()->data;

    // DoublyListNode<Student> *myNode = new DoublyListNode<Student>(myStudent);
    // cout << myNode->data->getId();
    // cout << myStudent.getId() << endl;
    //
    //

    //myQueue.printQueue();
    // GenQueue<int> myQueue;
    // myQueue.insert(3);
    // myQueue.insert(4);
    // myQueue.printQueue();
    // myQueue.remove();
    // myQueue.remove();
    // myQueue.remove();
    // myQueue.printQueue();
    //cout << myQueue.peek();
    // GenDoublyLinkedList<char> myList;
    // myList.insertFront('h');
    // myList.printList();
    // GenDoublyLinkedList<int> myList;
    // myList.insertFront(2);
    // myList.insertFront(1);
    // myList.insertFront(0);
    // myList.printList();
    // myList.insertBack(4);
    // myList.insertBack(5);
    // myList.printList();
    // cout << "remove front " << myList.removeFront() << endl;
    // myList.printList();
    // cout << "remove front " << myList.removeFront() << endl;
    // myList.printList();
    // cout << "remove front " << myList.removeFront() << endl;
    // myList.printList();
    // cout << "remove front " << myList.removeFront() << endl;
    // myList.printList();
    // cout << "remove back " << myList.removeBack() << endl;
    // myList.printList();
    // cout << "remove back " << myList.removeBack() << endl;
    // myList.printList();
    // cout << "remove back " << myList.removeBack() << endl;
    //     myList.printList();






    return 0;
}
