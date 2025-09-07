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
};    

Node* circularLL(int n) {
    if (n <= 0) {
        return nullptr;
    }
    Node* head = new Node(1);
    Node* prev = head;
    
    for (int i=2; i <= n; i++) {
        Node* newNode = new Node(i);
        prev -> next = newNode;
        prev = newNode;
    }
    prev -> next = head;
    return head;
}

int jp(int n, int k) {
    Node* head = circularLL(n);
    
    Node* prev = head;
    while (prev -> next != head) {
        prev = prev -> next;
    }
    Node* curr = head;
    
    while (curr->next != curr) {
        
        for (int count = 1; count < k; ++count) {
            prev = curr;
            curr = curr->next;
        }

        cout << "Player no. : " << curr->data << " has been eliminated!"<<endl;

        prev->next = curr->next;

        Node* toDelete = curr;
        curr = prev->next;    

        delete toDelete;
    }

    int survivor = curr->data;
    delete curr; 
    return survivor;
    
};

int main() {
    int N;
    int k;
    
    cout << "Enter size of N and k..." << endl;
    cin >> N ;
    cin >> k ;
    cout << "N = " << N << ", k = " << k << endl;
    int survivor = jp(N, k);

    cout << "Position no.: " << survivor << " is the winner" << endl;
    return 0;
}
