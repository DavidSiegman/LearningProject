#ifndef NODECLASS_H
#define NODECLASS_H

#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;
// ====================================================
// Node Class Implementation ==========================
// ========================================= Voronin.IV

// ====================================================
// Node Class declaration =============================
template <typename T>
class NodeClass{
public:
    NodeClass(int, T, NodeClass<T>*);
    ~NodeClass();
    void PrintNode();
    int getKey();
    void setPtrNext(NodeClass<T>*);
    NodeClass<T>* getPtrNext();
private:
    T             data;
    int           key;
    NodeClass<T> *next;
};
// ====================================================
// Node Class constructor =============================
template <typename T>
NodeClass<T>::NodeClass(int key, T data,
                        NodeClass<T>* next){
    this->key  = key;
    this->data = data;
    this->next = next;
}
// ====================================================
// Node Class destructor ==============================
template <typename T>
NodeClass<T>::~NodeClass(){}
// ====================================================
// Get the node key ===================================
template <typename T>
int NodeClass<T>::getKey(){
    return this->key;
}
// ====================================================
// Get pointer to next node ===========================
template <typename T>
NodeClass<T>* NodeClass<T>::getPtrNext(){
    return this->next;
}
// ====================================================
// Set pointer to next node ===========================
template <typename T>
void NodeClass<T>::setPtrNext(NodeClass<T>* new_next){
    this->next = new_next;
}
// ====================================================
// Display the node ===================================
template <typename T>
void NodeClass<T>::PrintNode(){
    printf("Node.Key %d, Node.Data %d\r\n",
           this->key,this->data);
}
template <>
void NodeClass<double>::PrintNode(){
    printf("Node.Key %d, Node.Data %2.2f\r\n",
           this->key,this->data);
}
template <>
void NodeClass<char*>::PrintNode(){
    printf("Node.Key %d, Node.Data %s\r\n",
           this->key,this->data);
}

#endif // NODECLASS_H
