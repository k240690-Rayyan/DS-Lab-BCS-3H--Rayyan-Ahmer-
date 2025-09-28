#include <iostream>
using namespace std;

void printNum(int n) {
    if(n==0)    return;
    cout << n << "  ";
    printNum(n-1);
}

void func1(int n);
void func2(int n);

void func2(int n) {
    cout << n << "  ";
    func1(n-1);
}

void func1(int n) {
    if(n==0)    
		return;
    else    
		func2(n);
}

int main() {
    printNum(5);
    cout << endl;
    func2(5);
}
