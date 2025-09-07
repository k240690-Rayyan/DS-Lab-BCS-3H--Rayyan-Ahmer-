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
    
    Node* inAtTail(Node* head, int d){
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
    void print(Node* head) {
        Node* temp = head;
        
        while (temp != NULL) {
            cout << temp -> data << endl;
            temp = temp -> next;
        }
        cout << endl;
    }
    
    Node* thirdList(Node* A, Node* B) {
        Node* C = NULL;
        
        Node* temp = A;
        while(temp != NULL) {
            C = inAtTail(C, temp -> data);
            temp = temp -> next;
        }
        
        temp = B;
        while(temp != NULL) {
            C = inAtTail(C, temp -> data);
            temp = temp -> next;
        }
        return C;
    }
    // executing through bubble sort as I studied in A levels and find this method easier
    
    Node* bubbleSort(Node* head) {
        if (head == NULL) {
            return head;
            
        }
        bool swap;
        int temp;
        do {
            swap = false;
            Node* curr = head;
            while(curr->next != NULL) {
                if (curr -> data > curr->next -> data) {
                    temp = curr -> data;
                    curr -> data = curr->next -> data;
                    curr->next -> data = temp;
                    swap = true;
                }
                curr = curr -> next;
            }
        }while (swap);
    
        return head;
    }
};    

int main() {
    Node* A = NULL;
    Node* B = NULL;

    A = inAtTail(A, 1);
    A = inAtTail(A, 3);
    A = inAtTail(A, 5);

    B = inAtTail(B, 2);
    B = inAtTail(B, 4);
    B = inAtTail(B, 6);

    cout << "List A: ";
    print(A);
    cout << "List B: ";
    print(B);

    Node* C = thirdList(A, B);

    cout << "Third (before sorting): ";
    print(C);

    C = bubbleSort(C);

    cout << "Third (after sorting): ";
    print(C);

    return 0;
}
