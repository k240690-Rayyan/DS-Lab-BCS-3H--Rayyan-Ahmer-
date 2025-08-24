#include <iostream>
using namespace std;

class Box {
private:
    int *ib;

public:
    Box(int a = 0) {
        ib = new int(a);
    }

    ~Box() {
        delete ib;
    }

    Box(const Box &obj) {
        ib = new int(*obj.ib);
    }

    Box& operator=(const Box& obj) {
        if (this != &obj) {
            delete ib;  
            ib = new int(*obj.ib);
        }
        return *this;
    }

    void setValue(int a) {
        *ib = a;
    }

    int getValue() const {
        return *ib;
    }

    void display(const string& name) const {
        cout << name << " Value: " << *ib 
             << " Address of value is: " << ib << endl;
    }
};

int main() {
    cout << "Copy Constructor (performing deep copy)" << endl;
    {
        Box box1(5);
        Box box2 = box1;   

        box1.display("Box 1");
        box2.display("Box 2");

        box2.setValue(10);  
        cout << "After changes:" << endl;
        box1.display("Box 1");
        box2.display("Box 2");
    }

    cout << "Assignment Operator (performing deep copy)" << endl;
    {
        Box box1(15);
        Box box2;
        box2 = box1;   

        box1.display("Box 1");
        box2.display("Box 2");

        box1.setValue(20);  
        cout << "After changes:" << endl;
        box1.display("Box 1");
        box2.display("Box 2");
    }

    return 0;
}
