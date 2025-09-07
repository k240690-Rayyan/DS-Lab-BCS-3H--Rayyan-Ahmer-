#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

Node* flatten(Node* head) {
    if (!head) return nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->child) {
            Node* nextNode = curr->next;
            curr->next = curr->child;
            curr->child = nullptr;

            Node* temp = curr->next;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nextNode;
        }
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->next->child = new Node(4);
    head->next->child->next = new Node(5);

    head = flatten(head);

    cout << "Flattened List: ";
    printList(head);

    return 0;
}
