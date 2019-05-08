#ifndef DLLNODECLASS_H
#define DLLNODECLASS_H

#include "LinkedListClass/nodeclass.h"

template <typename T>
class DLLNodeClass : public NodeClass<T>{
public:
    DLLNodeClass(int, T, DLLNodeClass<T>*, DLLNodeClass<T>*);
    ~DLLNodeClass();
    void setPtrPrev(DLLNodeClass<T>*);
    DLLNodeClass<T>* getPtrPrev();
private:
    DLLNodeClass<T> *prev;
};
// ====================================================
// Node Class constructor =============================
template <typename T>
DLLNodeClass<T>::DLLNodeClass(int key, T data,
    DLLNodeClass<T>* next, DLLNodeClass<T>* prev) :
    NodeClass<T>(key,data,next,prev){
    this->setKey(key);
    this->setData(data);
    this->setPtrNext(next);
    this->prev = prev;
}
// ====================================================
// Get pointer to previous node =======================
template <typename T>
DLLNodeClass<T>* DLLNodeClass<T>::getPtrPrev(){
    return this->prev;
}
// ====================================================
// Set pointer to previous node =======================
template <typename T>
void DLLNodeClass<T>::setPtrPrev(DLLNodeClass<T>* new_prev){
    this->prev = new_prev;
}
#endif // DLLNODECLASS_H
