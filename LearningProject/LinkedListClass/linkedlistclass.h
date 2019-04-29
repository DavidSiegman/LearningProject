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
    int length();
    NodeClass<T> deleteTopNode();
    bool deleteNode(int key);
    NodeClass<T>* findNode(int key);
    void BubbleShort(bool (*SortingCondition)
                     (T preNodeData,T currNodeData));
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
// Delete node by the key =============================
template <typename T>
bool LinkedListClass<T>::deleteNode(int key){
    bool result = false;
    if(this->head == NULL) {
       return result;
    }
    NodeClass<T> *current = this->head;
    NodeClass<T> *previous = NULL;
    while(current->getKey() != key){
       if(current->getPtrNext() == NULL){
          return result;
       } else {
           previous = current;
           current = current->getPtrNext();
       }
    }
    if (current == this->head){
        this->head = this->head->getPtrNext();
        delete current;
        result = true;
    }else{
        previous->setPtrNext(current->getPtrNext());
        delete current;
        result = true;
    }
    return result;
}
// ====================================================
// Check empty state ==================================
template <typename T>
bool LinkedListClass<T>::isEmpty(){
   return (this->head == NULL);
}
// ====================================================
// Return length of the list ==========================
template <typename T>
int LinkedListClass<T>::length(){
   int result = 0;
   NodeClass<T> *current = this->head;
   while(current != NULL){
       result++;
       current = current->getPtrNext();
   }
   return result;
}
// ====================================================
// Find node by the key ===============================
template <typename T>
NodeClass<T>* LinkedListClass<T>::findNode(int key){
   if(this->head == NULL){
      return NULL;
   }
   NodeClass<T> *current = this->head;
   while(current->getKey() != key){
      if(current->getPtrNext() == NULL){
         return NULL;
      }else{
         current = current->getPtrNext();
      }
   }
   return current;
}
// ====================================================
// Display the liste ==================================
template <typename T>
void LinkedListClass<T>::printList(){
   NodeClass<T> *ptr = this->head;
   while(ptr != NULL){
      ptr->PrintNode();
      ptr = ptr->getPtrNext();
   }
}
// ====================================================
// Bubble Short sorting algorithm =====================
template <typename T>
void LinkedListClass<T>::BubbleShort(
    bool (*SortingCondition)(T preNodeData,
                             T currNodeData)){
    int i, j, k, tempKey;
    T tempData;
    NodeClass<T> *current;
    NodeClass<T> *next;

    int size = this->length();
    k = size;

    for ( i = 0 ; i < size - 1 ; i++, k-- ){
        current = this->head;
        next = this->head->getPtrNext();
        for ( j = 1 ; j < k ; j++ ){
            if(SortingCondition(current->getData(),next->getData())){
                tempData = current->getData();
                current->setData(next->getData());
                next->setData(tempData);

                tempKey = current->getKey();
                current->setKey(next->getKey());
                next->setKey(tempKey);
            }
            current = current->getPtrNext();
            next = next->getPtrNext();
        }
    }
}

#endif // LINKEDLISTCLASS_H
