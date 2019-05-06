#include <QCoreApplication>

#include "LinkedListClass/nodeclass.h"
#include "LinkedListClass/linkedlistclass.h"
#include "SortingConditions/sortingconditions.h"

using namespace std;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    char str[20][100] = {0};

    LinkedListClass<char*>  *sLList =
            new LinkedListClass<char*>();
    strcpy(str[0],"Ivan");
    sLList->insertOnTop(1,str[0]);
    strcpy(str[1],"Yuriy");
    sLList->insertOnTop(2,str[1]);
    strcpy(str[2],"Maxim");
    sLList->insertOnTop(3,str[2]);
    strcpy(str[3],"Alexandr");
    sLList->insertOnTop(4,str[3]);
    strcpy(str[4],"Boris");
    sLList->insertOnTop(5,str[4]);
    strcpy(str[5],"Andrey");
    sLList->insertOnTop(6,str[5]);
    strcpy(str[6],"Ilya");
    sLList->insertOnTop(7,str[6]);
    strcpy(str[7],"Mihail");
    sLList->insertOnTop(8,str[7]);
    strcpy(str[8],"Marat");
    sLList->insertOnTop(9,str[8]);
    strcpy(str[9],"Semyon");
    sLList->insertOnTop(10,str[9]);
    sLList->deleteNode(3);
    cout << "\r\nUnsorted List =======================" << endl;
    sLList->printList();
    sLList->SelectionSort(&AlphaBethSorting);
    cout << "\r\nAlphabetically Sorted List ==========" << endl;
    sLList->printList();

    NodeClass<char*> *node = NULL;
    node = sLList->findNode(4);
    if (node != NULL){
        cout << "\r\nNode found - ";
        node->PrintNode();
    }else {
        cout << "\r\nNode not found" << endl;
    }

    return a.exec();
}

