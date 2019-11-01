#include "Student.h"
#include "GenQueue.h"


//#include "DoublyListNode.h"
#include <iostream>

using namespace std;

int main(){



     GenQueue<Student> *myQueue = new GenQueue<Student>();
     Student *myStudent = new Student(123);
     myQueue->insert(myStudent);
     cout << myQueue->theList->front->data->getId() << endl; //basically a peak











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
