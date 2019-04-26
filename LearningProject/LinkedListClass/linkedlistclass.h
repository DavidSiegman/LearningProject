#ifndef LINKEDLISTCLASS_H
#define LINKEDLISTCLASS_H
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "nodeclass.h"

using namespace std;

// ====================================================
// Linked List Class Implementation ===================
// ========================================= Voronin.IV

// ====================================================
// Linked List Class declaration ======================
template <typename T>
class LinkedListClass{   
public:
    LinkedListClass();
    void printList();
    void insertOnTop(int,T);
    bool isEmpty();
    NodeClass<T> deleteTopNode();
    NodeClass<T>* findNode(int key);
private:
    NodeClass<T> *head;
};
// ====================================================
// Linked List Class constructor ======================
template <typename T>
LinkedListClass<T>::LinkedListClass(){
    this->head    = NULL;
}
// ====================================================
// Insert node on top =================================
template <typename T>
void LinkedListClass<T>::insertOnTop(int key,
                                     T data){
    NodeClass<T> *NewNode =
            new NodeClass<T>(key,data,this->head);
    this->head = NewNode;
}
// ====================================================
// Delete top node ====================================
template <typename T>
NodeClass<T> LinkedListClass<T>::deleteTopNode(){
    NodeClass<T> tempNode = *this->head;
    delete this->head;
    this->head = tempNode.getPtrNext();
    return tempNode;
}
// ====================================================
// Check empty state ==================================
template <typename T>
bool LinkedListClass<T>::isEmpty() {
   return (this->head == NULL);
}
// ====================================================
// Find node by their key =============================
template <typename T>
NodeClass<T>* LinkedListClass<T>::findNode(int key) {
   if(this->head == NULL) {
      return NULL;
   }
   NodeClass<T> *current = this->head;
   while(current->getKey() != key) {
      if(current->getPtrNext() == NULL) {
         return NULL;
      } else {
         current = current->getPtrNext();
      }
   }
   return current;
}
// ====================================================
// Display the liste ==================================
template <typename T>
void LinkedListClass<T>::printList() {
   NodeClass<T> *ptr = this->head;
   while(ptr != NULL) {
      ptr->PrintNode();
      ptr = ptr->next;
   }
}

#endif // LINKEDLISTCLASS_H
