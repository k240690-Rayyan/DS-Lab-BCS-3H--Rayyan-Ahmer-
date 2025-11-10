#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;

    Node(string val) {
        data = val;
        left = right = NULL;
    }
};

Node* insertNode(Node* root, string child, string parent, char gender) {
    if (!root) return new Node(child);

    if (root->data == child) {
        if (gender == 'F') root->left = new Node(parent);
        if (gender == 'M') root->right = new Node(parent);
        return root;
    }

    insertNode(root->left, child, parent, gender);
    insertNode(root->right, child, parent, gender);
    return root;
}

void printRoot(Node* root) {
    cout << root->data << endl;
}

void printLeaves(Node* root) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        cout << root->data << endl;
        return;
    }

    printLeaves(root->left);
    printLeaves(root->right);
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void levelOrder(Node* root) {
    if (!root) return;

    queue<pair<Node*, int>> q;  //using queue as permitted in dsa theory
    q.push({root, 0});

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        cout << "Node: " << current.first->data << "\tLevel: " << current.second << endl;

        if (current.first->left)
            q.push({current.first->left, current.second + 1});
        if (current.first->right)
            q.push({current.first->right, current.second + 1});
    }
}

int main() {
    Node* root = new Node("Ali");

    root = insertNode(root, "Ali", "Ayesha", 'F');
    root = insertNode(root, "Ali", "Ahmed", 'M');

    root = insertNode(root, "Ayesha", "Fatima", 'F');
    root = insertNode(root, "Ayesha", "Imran", 'M');
    root = insertNode(root, "Ahmed", "Sara", 'F');
    root = insertNode(root, "Ahmed", "Hassan", 'M');

    root = insertNode(root, "Fatima", "Khadija", 'F');
    root = insertNode(root, "Fatima", "Yusuf", 'M');
    root = insertNode(root, "Imran", "Zainab", 'F');
    root = insertNode(root, "Imran", "Bilal", 'M');
    root = insertNode(root, "Sara", "Nazia", 'F');
    root = insertNode(root, "Sara", "Farooq", 'M');
    root = insertNode(root, "Hassan", "Rabia", 'F');
    root = insertNode(root, "Hassan", "Tariq", 'M');

    cout << "Root = ";
    printRoot(root);

    cout << "\nLeaf Nodes (Ancestors with no known parents):\n";
    printLeaves(root);

    cout << "\nHeight of Tree = " << height(root);
    cout << "\n\nLevels of Each Member (Level Order Traversal):\n";
    levelOrder(root);

    return 0;
}
