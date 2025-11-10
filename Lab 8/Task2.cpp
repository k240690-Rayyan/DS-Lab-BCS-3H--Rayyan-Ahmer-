#include <iostream>
#include <string>

using namespace std;

inline int customMax(int a, int b) {
    return (a > b) ? a : b;
}

class Track {
public:
    Track* left;
    Track* right;
    int accessCount;
    string trackName;
    int treeHeight;

    Track(string name, int count) {
        trackName = name;
        accessCount = count;
        left = right = NULL;
        treeHeight = 0;
    }
};

int getHeight(Track* tRoot) {
    return tRoot ? tRoot->treeHeight : -1;
}

int getBalance(Track* tRoot) {
    if (!tRoot) return 0;
    return getHeight(tRoot->left) - getHeight(tRoot->right);
}

Track* rightRotate(Track* pivotY) {
    Track* pivotX = pivotY->left;
    Track* tempT2 = pivotX->right;

    pivotX->right = pivotY;
    pivotY->left = tempT2;

    pivotY->treeHeight = customMax(getHeight(pivotY->left), getHeight(pivotY->right)) + 1;
    pivotX->treeHeight = customMax(getHeight(pivotX->left), getHeight(pivotX->right)) + 1;

    return pivotX;
}

Track* leftRotate(Track* pivotX) {
    Track* pivotY = pivotX->right;
    Track* tempT2 = pivotY->left;

    pivotY->left = pivotX;
    pivotX->right = tempT2;

    pivotX->treeHeight = customMax(getHeight(pivotX->left), getHeight(pivotX->right)) + 1;
    pivotY->treeHeight = customMax(getHeight(pivotY->left), getHeight(pivotY->right)) + 1;

    return pivotY;
}

Track* rebalanceTree(Track* tRoot) {
    if (!tRoot) return tRoot;

    tRoot->treeHeight = customMax(getHeight(tRoot->left), getHeight(tRoot->right)) + 1;

    int balanceFactor = getBalance(tRoot);

    if (balanceFactor > 1 && getBalance(tRoot->left) >= 0) {
        return rightRotate(tRoot);
    }

    if (balanceFactor > 1 && getBalance(tRoot->left) < 0) {
        tRoot->left = leftRotate(tRoot->left);
        return rightRotate(tRoot);
    }

    if (balanceFactor < -1 && getBalance(tRoot->right) <= 0) {
        return leftRotate(tRoot);
    }

    if (balanceFactor < -1 && getBalance(tRoot->right) > 0) {
        tRoot->right = rightRotate(tRoot->right);
        return leftRotate(tRoot);
    }

    return tRoot;
}

Track* addToCatalogue(Track* tRoot, string name, int count) {
    if (!tRoot)
        return new Track(name, count);

    if (count < tRoot->accessCount)
        tRoot->left = addToCatalogue(tRoot->left, name, count);
    else if (count > tRoot->accessCount)
        tRoot->right = addToCatalogue(tRoot->right, name, count);
    else
        return tRoot;

    return rebalanceTree(tRoot);
}

Track* findTrack(Track* tRoot, int count) {
    if (!tRoot) return NULL;
    if (tRoot->accessCount == count) return tRoot;
    if (count < tRoot->accessCount) return findTrack(tRoot->left, count);
    return findTrack(tRoot->right, count);
}

Track* findMinTrack(Track* tRoot) {
    while (tRoot->left)
        tRoot = tRoot->left;
    return tRoot;
}

Track* removeTrack(Track* tRoot, int count) {
    if (!tRoot) return NULL;

    if (count < tRoot->accessCount)
        tRoot->left = removeTrack(tRoot->left, count);
    else if (count > tRoot->accessCount)
        tRoot->right = removeTrack(tRoot->right, count);
    else {
        if (!tRoot->left && !tRoot->right) {
            delete tRoot;
            return NULL;
        }
        else if (!tRoot->left) {
            Track* temp = tRoot->right;
            delete tRoot;
            return temp;
        }
        else if (!tRoot->right) {
            Track* temp = tRoot->left;
            delete tRoot;
            return temp;
        }

        Track* successor = findMinTrack(tRoot->right);
        tRoot->accessCount = successor->accessCount;
        tRoot->trackName = successor->trackName;
        tRoot->right = removeTrack(tRoot->right, successor->accessCount);
    }

    return rebalanceTree(tRoot);
}

void displayInOrder(Track* tRoot) {
    if (!tRoot) return;
    displayInOrder(tRoot->left);
    cout << tRoot->trackName << " [" << tRoot->accessCount << "] | ";
    displayInOrder(tRoot->right);
}

void displayPostOrder(Track* tRoot) {
    if (!tRoot) return;
    displayPostOrder(tRoot->left);
    displayPostOrder(tRoot->right);
    cout << tRoot->trackName << " [" << tRoot->accessCount << "] | ";
}

int main() {
    Track* musicCatalogue = NULL;

    musicCatalogue = addToCatalogue(musicCatalogue, "Jhol", 100);
    musicCatalogue = addToCatalogue(musicCatalogue, "Rockabye", 90);
    musicCatalogue = addToCatalogue(musicCatalogue, "Weeknd", 80);
    musicCatalogue = addToCatalogue(musicCatalogue, "Cheap thrills", 120);

    Track* foundTrack = findTrack(musicCatalogue, 100);
    if (foundTrack) {
        cout << foundTrack->trackName << " found successfully in the catalogue.\n\n";
    }

    cout << "Catalogue In-Order (Sorted by Access Count)\n";
    displayInOrder(musicCatalogue);
    cout << "\n";

    cout << "Catalogue Post-Order Traversal\n";
    displayPostOrder(musicCatalogue);
    cout << "\n";

    cout << "\nRemoving track with Access Count 90\n";
    musicCatalogue = removeTrack(musicCatalogue, 90);

    cout << "\nIn-Order after deletion\n";
    displayInOrder(musicCatalogue);
    cout << "\n";

    return 0;
}
