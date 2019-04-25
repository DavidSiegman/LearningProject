#ifndef LINKEDLISTCLASS_H
#define LINKEDLISTCLASS_H
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "nodeclass.h"

using namespace std;

template <typename T>
class LinkedListClass{   
public:
    LinkedListClass();
    void insertFirst(int,T);
    NodeClass<T> deleteFirst();
    bool isEmpty();
    void printList();

private:
    NodeClass<T> *head;
    NodeClass<T> *current;
};
template <typename T>
LinkedListClass<T>::LinkedListClass(){
    this->head    = NULL;
    this->current = NULL;
}
template <typename T>
void LinkedListClass<T>::insertFirst(int key,
                                     T data){
    NodeClass<T> *NewNode =
            new NodeClass<T>(key,data,this->head);
    this->head = NewNode;
}
template <typename T>
NodeClass<T> LinkedListClass<T>::deleteFirst(){
    NodeClass<T> tempNode = *this->head;
    delete this->head;
    this->head = tempNode.next;
    return tempNode;
}
template <typename T>
bool LinkedListClass<T>::isEmpty() {
   return (this->head == NULL);
}
template <typename T>
void LinkedListClass<T>::printList() {
   NodeClass<T> *ptr = this->head;
   while(ptr != NULL) {
      ptr->PrintNode();
      ptr = ptr->next;
   }
}
#endif // LINKEDLISTCLASS_H
