#ifndef NODECLASS_H
#define NODECLASS_H

#include <iostream>
#include <cstdlib>
#include <stdlib.h>

template <typename T>
class NodeClass{
public:
    NodeClass(int key, T data, NodeClass *next);
    ~NodeClass();
    void PrintNode();

    NodeClass *next;
private:
    T          data;
    int        key;
};
template <typename T>
NodeClass<T>::NodeClass(int key, T data,
                        NodeClass *next){
    this->key  = key;
    this->data = data;
    this->next = next;
}
template <typename T>
NodeClass<T>::~NodeClass(){

}
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
