#ifndef DOUBLELINKEDLISTCLASS_H
#define DOUBLELINKEDLISTCLASS_H

#include "LinkedListClass/linkedlistclass.h"

using namespace std;

// ====================================================
// Double Linked List Class Implementation ============
// ========================================= Voronin.IV

// ====================================================
// Double Linked List Class declaration ===============
template <typename T>
class DoubleLinkedListClass : public LinkedListClass<T>{
public:
    DoubleLinkedListClass();
    void printList();
    void insertToHead(int,T);
    void insertToTail(int,T);

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
DoubleLinkedListClass<T>::DoubleLinkedListClass(){
    this->head    = NULL;
    this->tail    = NULL;
}
#endif // DOUBLELINKEDLISTCLASS_H
