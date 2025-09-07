#include <iostream>
using namespace std;

class SLL {
public:
    int data;
    SLL* next;

    SLL(int val) {
        data = val;
        next = nullptr;
    }
};

class DLL {
public:
    int data;
    DLL* next;
    DLL* prev;

    DLL(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void toCircular(SLL* head) {
    if (!head) return;
    SLL* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head;
}

void printCircular(SLL* head) {
    if (!head) return;
    SLL* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

DLL* toDoubly(SLL* head) {
    if (!head) return nullptr;

    DLL* dHead = new DLL(head->data);
    DLL* dCurr = dHead;
    SLL* sCurr = head->next;

    while (sCurr != nullptr) {
        DLL* newNode = new DLL(sCurr->data);
        dCurr->next = newNode;
        newNode->prev = dCurr;
        dCurr = newNode;
        sCurr = sCurr->next;
    }
    return dHead;
}

void printDLL(DLL* head) {
    DLL* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    SLL* circularList = new SLL(1);
    circularList->next = new SLL(2);
    circularList->next->next = new SLL(3);
    circularList->next->next->next = new SLL(4);

    toCircular(circularList);
    cout << "Circular SLL: ";
    printCircular(circularList);

    SLL* simpleList = new SLL(10);
    simpleList->next = new SLL(20);
    simpleList->next->next = new SLL(30);
    simpleList->next->next->next = new SLL(40);

    DLL* dHead = toDoubly(simpleList);
    cout << "DLL to SLL: ";
    printDLL(dHead);

    return 0;
}
