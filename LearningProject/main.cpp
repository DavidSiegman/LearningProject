#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

#include "LinkedListClass/nodeclass.h"
#include "LinkedListClass/linkedlistclass.h"

using namespace std;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    char str[5][100] = {0};

    LinkedListClass<char*>  *sLList =
            new LinkedListClass<char*>();
    strcpy(str[0],"String1");
    sLList->insertOnTop(1,str[0]);
    strcpy(str[1],"String2");
    sLList->insertOnTop(2,str[1]);
    strcpy(str[2],"String3");
    sLList->insertOnTop(3,str[2]);
    strcpy(str[3],"String4");
    sLList->insertOnTop(4,str[3]);
    strcpy(str[4],"String5");
    sLList->insertOnTop(5,str[4]);
    sLList->deleteTopNode();
    //sLList->printList();

    NodeClass<char*> *node = NULL;
    node = sLList->findNode(4);
    if (node != NULL){
        cout << "Node found - ";
        node->PrintNode();
    }else {
        cout << "Node not found" << endl;
    }

    return a.exec();
}
