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
    void insertToHead(int,T);
    void insertToTail(int,T);
    bool isEmpty();
    int length();
    NodeClass<T> deleteFromHead();
    NodeClass<T> deleteFromTail();
    NodeClass<T> deleteNode(int key);
    NodeClass<T> getNode(int key);

    void BubbleSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData));
    void SelectionSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData));
    void InsertionSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData));
    void GnomeSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData));
    void QuickSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData));

private:
    NodeClass<T> *head;
    NodeClass<T> *tail;
};
// ====================================================
// Linked List Class constructor ======================
template <typename T>
LinkedListClass<T>::LinkedListClass(){
    this->head    = NULL;
    this->tail    = NULL;
}
// ====================================================
// Insert node to head ================================
template <typename T>
void LinkedListClass<T>::insertToHead(int key,
                                      T data){
    NodeClass<T> *NewNode =
            new NodeClass<T>(key,data,this->head);
    this->head = NewNode;
    if (length() == 1){
       this->tail = this->head;
    }
}
// ====================================================
// Insert node to tail ================================
template <typename T>
void LinkedListClass<T>::insertToTail(int key,
                                      T data){
    NodeClass<T> *NewNode =
            new NodeClass<T>(key,data,NULL);
    if (this->tail != NULL){
        this->tail->setPtrNext(NewNode);
    }
    this->tail = NewNode;
    if (this->head == NULL){
       this->head = this->tail;
    }
}
// ====================================================
// Delete node from head ==============================
template <typename T>
NodeClass<T> LinkedListClass<T>::deleteFromHead(){
    try{
        if (this->head == NULL){
          throw 0;
        }
        NodeClass<T> tempNode = *this->head;
        delete this->head;
        if (tempNode.getPtrNext() != NULL){
            this->head = tempNode.getPtrNext();
        }else{
            this->head = NULL;
            this->tail = NULL;
        }
        return tempNode;
    }catch(int x) {
        cout << "\r\nDelete error: "
                "head pointer is NULL" << endl;
        NodeClass<T> *node = new NodeClass<T> (0, 0, NULL);
        return *node;
    }
}
// ====================================================
// Delete node from tail ==============================
template <typename T>
NodeClass<T> LinkedListClass<T>::deleteFromTail(){
    try{
        if (this->tail == NULL){
          throw 0;
        }
        NodeClass<T> tempNode = *this->tail;
        NodeClass<T> *preTail = this->head;

        int size = this->length();
        if (size > 1){
            for(int i = 0; i < size-2; i++){
                preTail = preTail->getPtrNext();
            }
        }
        if (preTail->getPtrNext() != NULL){
            preTail->setPtrNext(NULL);
        }else{
            preTail = NULL;
            this->head = NULL;
        }
        delete this->tail;
        this->tail = preTail;
        return tempNode;
    }catch(int x) {
        cout << "\r\nDelete error: "
                "tail pointer is NULL" << endl;
        NodeClass<T> *node = new NodeClass<T> (0, 0, NULL);
        return *node;
    }
}
// ====================================================
// Delete node by the key =============================
template <typename T>
NodeClass<T> LinkedListClass<T>::deleteNode(int key){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        NodeClass<T> *current = this->head;
        NodeClass<T> *previous = NULL;
        while(current->getKey() != key){
           if(current->getPtrNext() == NULL){
              throw 1;
           } else {
               previous = current;
               current = current->getPtrNext();
           }
        }
        NodeClass<T> result = *current;
        if (current == this->head){
            this->head = this->head->getPtrNext();
            delete current;
        }else{
            previous->setPtrNext(current->getPtrNext());
            delete current;
        }
        return result;
    }catch(int x) {
        if (x == 0){
            cout << "\r\nDelete error: "
                    "head pointer is NULL" << endl;
        }
        if (x == 1){
            cout << "\r\nDelete error: "
                    "key wasn't found" << endl;
        }
        NodeClass<T> *node = new NodeClass<T> (0, 0, NULL);
        return *node;
    }
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
// Get node by the key ================================
template <typename T>
NodeClass<T> LinkedListClass<T>::getNode(int key){
    try{
       if(this->head == NULL) {
           throw 0;
       }
       NodeClass<T> *current = this->head;
       while(current->getKey() != key){
          if(current->getPtrNext() == NULL){
             throw 1;
          }else{
             current = current->getPtrNext();
          }
       }
       NodeClass<T> result = *current;
       return result;
    }catch(int x) {
        if (x == 0){
            cout << "\r\ngetNode: "
                    "head pointer is NULL" << endl;
        }
        if (x == 1){
            cout << "\r\ngetNode: "
                    "key wasn't found" << endl;
        }
        NodeClass<char*> *node =
                new NodeClass<char*> (0, NULL, NULL);
        return *node;
    }
}
// ====================================================
// Display the liste ==================================
template <typename T>
void LinkedListClass<T>::printList(){
   NodeClass<T> *ptr = this->head;
   int number = 0;
   while(ptr != NULL){
      cout << "No.: " << number << " ";
      number++;
      ptr->PrintNode();
      if (ptr == this->head){
          cout << " - head";
      }
      if (ptr == this->tail){
          cout << " - tail";
      }
      cout << "\r\n";
      ptr = ptr->getPtrNext();
   }
}
// ====================================================
// Bubble Sort sorting algorithm ======================
template <typename T>
void LinkedListClass<T>::BubbleSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int i, j, k, tempKey;
        T tempData;
        NodeClass<T> *current;
        NodeClass<T> *next;

        int size = this->length();
        k = size;

        for (i = 0 ; i < size - 1 ; i++, k--){
            current = this->head;
            next = this->head->getPtrNext();
            for ( j = 1 ; j < k ; j++ ){
                if(SortingCondition(current->getData(),
                                    next->getData())){
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
    }catch(int x) {
        if (x == 0){
            cout << "\r\nBubble Sort: "
                    "head pointer is NULL" << endl;
        }
    }
}
// ====================================================
// Selection Sort sorting algorithm ===================
template<typename T>
void LinkedListClass<T>::SelectionSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int i, tempKey;
        T             tempData;
        NodeClass<T> *UnsortedArea;
        NodeClass<T> *Current;
        NodeClass<T> *Minimum;

        int size = this->length();

        UnsortedArea = this->head;
        Minimum = UnsortedArea;
        Current = UnsortedArea;

        for (i = 0 ; i < size; i++) {
            while(Current != NULL) {
                if (SortingCondition(Minimum->getData(),
                                     Current->getData())) {
                    Minimum = Current;
                }
                Current = Current->getPtrNext();
            }
            if (Minimum != UnsortedArea) {
                tempData = Minimum->getData();
                Minimum->setData(UnsortedArea->getData());
                UnsortedArea->setData(tempData);
                tempKey = Minimum->getKey();
                Minimum->setKey(UnsortedArea->getKey());
                UnsortedArea->setKey(tempKey);
            }
            UnsortedArea = UnsortedArea->getPtrNext();
            Current = UnsortedArea;
            Minimum = UnsortedArea;
        }
    }catch(int x) {
        if (x == 0){
            cout << "\r\nBubble Sort: "
                    "head pointer is NULL" << endl;
        }
    }
}
// ====================================================
// Insertion Sort sorting algorithm ===================
template<typename T>
void LinkedListClass<T>::InsertionSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int i, tempKey;
        T             tempData;
        NodeClass<T> *SortedAreaTail   = this->head;

        int size = this->length();
        int sorted_nodes   = 1;
        int unsorted_nodes = size;

        while(SortedAreaTail->getPtrNext() != NULL){

            NodeClass<T> *preSortedCurrent = this->head;
            NodeClass<T> *SortedCurrent    = this->head;
            NodeClass<T> *Current =
                    SortedAreaTail->getPtrNext();

            for(i = 0; i < sorted_nodes; i++){
                if(SortingCondition(SortedCurrent->getData(),
                                    Current->getData())){
                    SortedAreaTail->setPtrNext(
                                Current->getPtrNext());
                    if (SortedCurrent != this->head){
                        preSortedCurrent->setPtrNext(Current);
                        Current->setPtrNext(SortedCurrent);
                    }else{
                        this->head = Current;
                        Current->setPtrNext(SortedCurrent);
                    }
                    break;
                }else{
                    if(SortedCurrent == SortedAreaTail){
                      SortedAreaTail = Current;
                    }else{
                      preSortedCurrent = SortedCurrent;
                      SortedCurrent =
                              SortedCurrent->getPtrNext();
                    }
                }
            }
            sorted_nodes++;
            unsorted_nodes--;
        }

    }catch(int x) {
        if (x == 0){
            cout << "\r\nBubble Sort: "
                    "head pointer is NULL" << endl;
        }
    }
}
// ====================================================
// Gnome Sort sorting algorithm =======================
template<typename T>
void LinkedListClass<T>::GnomeSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int i, tempKey;
        T             tempData;
        NodeClass<T> *preCurrent = this->head;
        NodeClass<T> *Current    = this->head;

        while(Current->getPtrNext() != NULL){
            preCurrent = Current;
            Current = Current->getPtrNext();
            if(SortingCondition(preCurrent->getData(),
                                Current->getData())){
                tempData = preCurrent->getData();
                preCurrent->setData(Current->getData());
                Current->setData(tempData);
                tempKey = preCurrent->getKey();
                preCurrent->setKey(Current->getKey());
                Current->setKey(tempKey);

                preCurrent = this->head;
                Current    = this->head;
            }
        }
    }catch(int x) {
        if (x == 0){
           cout << "\r\nBubble Sort: "
                   "head pointer is NULL" << endl;
        }
    }
}

#endif // LINKEDLISTCLASS_H
