#include <iostream>
//#include "Student.h"

using namespace std;

template<class T>
class DoublyListNode{
  public:
    T *data;
    DoublyListNode *next;
    DoublyListNode *prev;

    //constructor
    DoublyListNode();
    DoublyListNode(T *d);
    ~DoublyListNode();

};
template<class T>
DoublyListNode<T>::DoublyListNode(){}

template<class T>
DoublyListNode<T>::DoublyListNode(T *d)
{
  data = d;
  next = NULL; //nullptr
  prev = NULL;
}

template<class T>
DoublyListNode<T>::~DoublyListNode()
{
  next = NULL;
  prev = NULL;

}
