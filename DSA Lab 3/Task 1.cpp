#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }
    Node(int val) {
        data = val;
        next = NULL;
    }

    Node* t_forward(Node* head)
    {
        if (head == NULL) return NULL;

        Node* new_head = NULL;
        Node* new_tail = NULL;
        Node* temp = head;

        while (temp != NULL)
        {
            Node* new_node = new Node(temp->data);

            if (new_head == NULL) {
                new_head = new_node;
                new_tail = new_node;
            } else {
                new_tail->next = new_node;
                new_tail = new_node;
            }
            temp = temp->next;
        }
        return new_head;
    }

    Node* t_back(Node* head)
    {
        Node* new_head = NULL;
        Node* temp = head;

        while (temp != NULL)
        {
            Node* new_node = new Node(temp->data);
            new_node->next = new_head;
            new_head = new_node;
            temp = temp->next;
        }
        return new_head;
    }

    bool isPalindrome(Node* head)
    {
        Node* fwd = t_forward(head);
        Node* rev = t_back(head);

        Node* p1 = fwd;
        Node* p2 = rev;

        while (p1 != NULL && p2 != NULL) {
            if (p1->data != p2->data) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};

Node* insert_at_tail(Node* head, int val) {
    Node* new_node = new Node(val);
    if (head == NULL) return new_node;

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new_node;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node obj;

    Node* head = NULL;
    head = insert_at_tail(head, 1);
    head = insert_at_tail(head, 2);
    head = insert_at_tail(head, 3);
    head = insert_at_tail(head, 2);
    head = insert_at_tail(head, 1);

    cout << "List: ";
    printList(head);

    if (obj.isPalindrome(head))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    Node* head2 = NULL;
    head2 = insert_at_tail(head2, 1);
    head2 = insert_at_tail(head2, 2);
    head2 = insert_at_tail(head2, 3);

    cout << "List: ";
    printList(head2);

    if (obj.isPalindrome(head2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
