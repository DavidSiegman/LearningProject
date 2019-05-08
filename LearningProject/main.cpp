#include <QCoreApplication>

#include "DoubleLinkedListClass/dllnodeclass.h"
//#include "LinkedListClass/nodeclass.h"
#include "LinkedListClass/linkedlistclass.h"
#include "SortingConditions/sortingconditions.h"

using namespace std;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    char str[20][100] = {0};

    LinkedListClass<char*>  *sLList =
            new LinkedListClass<char*>();
    strcpy(str[0],"Ivan");
    sLList->insertToTail(1,str[0]);
    strcpy(str[1],"Yuriy");
    sLList->insertToTail(2,str[1]);
    strcpy(str[2],"Maxim");
    sLList->insertToTail(3,str[2]);
    strcpy(str[3],"Alexandr");
    sLList->insertToTail(4,str[3]);
    strcpy(str[4],"Boris");
    sLList->insertToTail(5,str[4]);
    strcpy(str[5],"Andrey");
    sLList->insertToTail(6,str[5]);
    strcpy(str[6],"Ilya");
    sLList->insertToTail(7,str[6]);
    strcpy(str[7],"Mihail");
    sLList->insertToTail(8,str[7]);
    strcpy(str[8],"Marat");
    sLList->insertToTail(9,str[8]);
    strcpy(str[9],"Semyon");
    sLList->insertToTail(10,str[9]);
    strcpy(str[10],"Dmitriy");
    sLList->insertToHead(0,str[10]);

    NodeClass<char*> deleted_node = sLList->deleteNode(3);
    if (deleted_node.getData() != NULL){
        cout << "\r\nDeleted Node - ";
        deleted_node.PrintNode();
    }
    delete &deleted_node;

    cout << "\r\nUnsorted List =======================" << endl;
    sLList->printList();

    sLList->GnomeSort(&AlphaBethSorting);
    cout << "\r\nAlphabetically Sorted List with sorted by GnomeSort==========" << endl;
    sLList->printList();

    //sLList->BubbleSort(&AlphaBethSorting);
    //cout << "\r\nAlphabetically Sorted List with sorted by BubbleSort==========" << endl;
    //sLList->printList();

    //sLList->SelectionSort(&iAlphaBethSorting);
    //cout << "\r\nInverse Alphabetically Sorted List with sorted by SelectionSort==========" << endl;
    //sLList->printList();

    //sLList->InsertionSort(&AlphaBethSorting);
    //cout << "\r\nAlphabetically Sorted List with sorted by InsertionSort==========" << endl;
    //sLList->printList();

    NodeClass<char*> found_node = sLList->getNode(400);
    if (found_node.getData() != NULL){
        cout << "\r\nNode found - ";
        found_node.PrintNode();
    }
    delete &found_node;

    DLLNodeClass<char*> *node = new DLLNodeClass<char*> (0,0,NULL,NULL);

    return a.exec();
}

