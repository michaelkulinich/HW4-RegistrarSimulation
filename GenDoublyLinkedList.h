#include "DoublyListNode.h"
#include <iostream>

using namespace std;
template<class T>
class GenDoublyLinkedList{
  // private:
  //   DoublyListNode *front;
  //   DoublyListNode *back;
  //   usigned int size;

  public:
    DoublyListNode<T> *front;
    DoublyListNode<T> *back;
    unsigned int size;
    GenDoublyLinkedList();
    ~GenDoublyLinkedList();

    void insertFront(T d);
    void insertBack(T *d);
    T* removeFront();
    T removeBack();
  //  int deletePos(int pos);// aka removeAt()
    int find(T d); //aka contains()
    DoublyListNode<T>* remove(T d); // aka int key

    //helper functions
    bool isEmpty();
    void printList();
    unsigned int getSize();

};


template<class T>
GenDoublyLinkedList<T>::GenDoublyLinkedList(){
  size = 0;
  front = NULL; // nullptr
  back = NULL;
}
template<class T>
GenDoublyLinkedList<T>::~GenDoublyLinkedList(){//need to ask rene
    while(!isEmpty()){
        removeFront();
    }
    //delete front;
    //delete back;
}

template<class T>
unsigned int GenDoublyLinkedList<T>::getSize(){
  return size;
}
template<class T>
void GenDoublyLinkedList<T>::printList(){
    if(isEmpty())
        cout << "empty list" << endl;
    else{
        DoublyListNode<T> *current = front;
        while(current != NULL){
            cout << current->data << ", ";
            current = current->next;
        }
        cout << endl;
    }
}
template<class T>
void GenDoublyLinkedList<T>::insertFront(T d){
  DoublyListNode<T> *node = new DoublyListNode<T>(d);
  if(size == 0)//empty list
  {
    back = node;
  }
  else //not empty
  {
    node->next = front;
    front->prev = node;
    front = node;
  }
  front = node;
  ++size;
}

template<class T>
void GenDoublyLinkedList<T>::insertBack(T *d){
  DoublyListNode<T> *node = new DoublyListNode<T>(d);
  if(size == 0)//empty list
  {
    //we have an empty list
    front = node;
  }
  else //not empty
  {
    back->next = node;
    node ->prev = back;
  }
  back = node;
  ++size;
}


template<class T>
T* GenDoublyLinkedList<T>::removeFront(){
    //check if empty before attempting to remove
    if(isEmpty()){
        cout << "list is empty" << endl;
        exit(1);
    }

    DoublyListNode<T> *ft = front;
    if(size == 1){//front == back or front ->next ==nullptr
        //it's the one node in the list
        back == NULL;
    }
    else
    {
        //we have more than one element in the List
        front->next->prev = NULL; //the pointer (prev) to front is null
    }
    front = front->next;
    T *temp = ft->data;
    ft->next = NULL;
    delete ft;
    --size;
    return temp;
}

template<class T>
T GenDoublyLinkedList<T>::removeBack(){
    //check if empty before attempting to remove
    if(isEmpty()){
        cout << "list is empty" << endl;
        exit(1);
    }

    DoublyListNode<T> *ft = back;
    if(size == 1){//front == back or front ->next ==nullptr
        //it's the one node in the list
        front == NULL;
    }
    else
    {
        //we have more than one element in the List
        back->prev->next = NULL; //the pointer (prev) to front is null
    }
    back = back->prev;
    T temp = ft->data;
    ft->prev = NULL;
    delete ft;
    --size;
    return temp;
}

template<class T>
 DoublyListNode<T>* GenDoublyLinkedList<T>::remove(T d){ //find the value and remove
  //check if list is not empty before attempting to remove
  DoublyListNode<T> *curr = front;

  while(curr->data != d)
  {
    curr = curr-> next;
    if(curr == NULL)//we did not find the value/ListNode
    {
      return NULL;
    }
  }
  //if we get to this point it means we found it

  //let's check if the node is the front
  if(curr == front)
  {
    front = curr->next;
  }
  else
  {
    //not the front
    //update pointer  the previous Node from curr should point to Node next to curr
    curr->prev->next = curr->next;
  }

  if(curr == back){
    back = curr->prev;
  }
  else
  {
    //not the back
    //update pointer  the next Node from curr should point its prev to Node previous to curr
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;
  size--;

  return curr;//you would end up grabbing this value and delete

 }


template<class T>
int GenDoublyLinkedList<T>::find(T d){

  int idx = 0;
  DoublyListNode<T> *curr = front;

  while(curr != NULL){
    if(curr->data ==d){
      //we found the value we were looking for
      break;
    }
    idx++;
    curr = curr->next;
  }

  if(curr == NULL){ //we did not find the value
    idx = -1;
  }

  return idx;
}

template<class T>
bool GenDoublyLinkedList<T>::isEmpty(){
    return (size == 0);
}


//
// int GenDoublyLinkedList<T>::deletePos(int pos){ // find the index and remove
//
//   int idx = 0; //index
//   ListNode *curr = front;
//   ListNode *pre = front; //bc when we delete, we need pre->next to point to  curr->next, skipping curr
//   while(idx != pos){
//     prev = curr;
//     curr = curr->next;
//     idx++;
//   }
//
//   //we have found the poistion of the node to be deleted, hopefully our pointers are in the ocrrect position
//
//   prev->next = curr->next;
//   curr->next = NULL;
//   int temp = curr->data;
//   delete curr;
//   size--;
//
//   return temp;
// }
