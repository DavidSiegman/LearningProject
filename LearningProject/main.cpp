#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

#include "LinkedListClass/linkedlistclass.h"

using namespace std;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    char str[100] = {0};

    LinkedListClass<int>    *iLList =
            new LinkedListClass<int>();
    if (iLList->isEmpty()){
        cout << "iLList is empty" << endl;
    }else{cout << "iLList isn't empty" << endl;}
    iLList->insertFirst(1,10);
    iLList->insertFirst(2,11);
    iLList->insertFirst(3,20);
    iLList->deleteFirst();
    iLList->deleteFirst();
    iLList->printList();
    if (iLList->isEmpty()){
        cout << "iLList is empty" << endl;
    }else{cout << "iLList isn't empty" << endl;}

    LinkedListClass<char*>  *sLList =
            new LinkedListClass<char*>();
    strcpy(str,"String10");
    sLList->insertFirst(1,str);
    strcpy(str,"String11");
    sLList->insertFirst(2,str);
    strcpy(str,"String20");
    sLList->insertFirst(3,str);
    iLList->deleteFirst();
    sLList->printList();

    LinkedListClass<double>  *dLList =
            new LinkedListClass<double>();
    dLList->insertFirst(1,0.01);
    dLList->insertFirst(2,4.11);
    dLList->insertFirst(3,100.78);
    dLList->deleteFirst();
    dLList->printList();

    return a.exec();
}
