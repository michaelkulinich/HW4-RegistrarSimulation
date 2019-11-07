#include <iostream>
#include "GenDoublyLinkedList.h"

using namespace std;


template <class T>
class GenQueue
{
public:
    GenQueue();
    ~GenQueue();

    //core functions
    void insert(T *d);
    T* remove();

    //aux functions
    T* peek();
    bool isEmpty();
    int getSize();
    void printQueue();

    //variables
    int size;
    int numElements;

    GenDoublyLinkedList<T> *theList; //list
};

template <class T>
GenQueue<T>::GenQueue(){
    //default constructor
    //finish this
    theList = new GenDoublyLinkedList<T>();
    size = 0;
}

template <class T>
GenQueue<T>::~GenQueue(){
  //figure it out
}
template <class T>
void GenQueue<T>::insert(T *d){
    theList->insertBack(d);
    size++;
}

template <class T>
T* GenQueue<T>::remove(){
    //error checking
    if(isEmpty()){
        cout << "queue is empty" << endl;
        exit(1);
    }
    T *c = theList->removeFront();
    size--;
    return c;
}

template <class T>
T* GenQueue<T>::peek(){
    if(size == 0){
        cout << "queue is empty, cant peek" << endl;
        exit(1);
    }
    return theList->front->data;
}


template <class T>
bool GenQueue<T>::isEmpty(){
    return (size == 0);
}

template <class T>
int GenQueue<T>::getSize(){
    return size;
}

template <class T>
void GenQueue<T>::printQueue(){
    theList->printList();
}
