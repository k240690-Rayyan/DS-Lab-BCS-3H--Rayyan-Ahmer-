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
    
    static Node* inAtTail(Node* head, int d){
        Node* newNode = new Node(d);
        newNode -> next = NULL;
        
        if (head == NULL) {
            return newNode;
        }
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        
        return head;
    }
    
    static Node* reverseK(Node* head, int k) {
        if (!head) return NULL;

        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        int count = 0;
        
        Node* check = head;
        for (int i = 0; i < k; i++) {
            if (!check) return head; 
            check = check->next;
        }

        
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        
        if (next != NULL) {
            head->next = reverseK(next, k);
        }

        return prev; 
    }
        
    static void print(Node* head) {
        Node* temp = head;
            
        while (temp != NULL) {
            cout << temp -> data << endl;
            temp = temp -> next;
        }
        cout << endl;
    }
    
    
};    

int main() {
    Node* A = NULL;

    A = Node::inAtTail(A, 1);
    A = Node::inAtTail(A, 2);
    A = Node::inAtTail(A, 3);
    A = Node::inAtTail(A, 4);
    A = Node::inAtTail(A, 5);
    A = Node::inAtTail(A, 6);
    A = Node::inAtTail(A, 7);
    A = Node::inAtTail(A, 8);
    
    cout << "Nodes before reversal:" << endl;
    Node::print(A);
    
    int k = 3;
    A = Node::reverseK(A, k);

    cout << "List after reversing in groups of " << k << ":" << endl;
    Node::print(A);

    return 0;
}
