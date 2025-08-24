#include <iostream>
using namespace std;

class BankAccount {
	private:
		double balance;
		
			
	public:
		BankAccount() {
			balance = 0.00;
			
		}
		BankAccount(double bal) {
			balance = bal;
		}
		BankAccount(BankAccount &obj) {

			balance = obj.balance - 200;
			
			
					
		}
		void display() const {
			cout << "Balance:" << balance << endl;
		}
	
};

int main() {
	BankAccount account1;
	cout << "Account 1:" << endl;
	account1.display();
	
	BankAccount account2(1000);
	cout << "Account 2:" << endl;

	account2.display();
	
	BankAccount account3(account2);
	cout << "Account 3:" << endl;

	account3.display();
	
	cout << "Account 2 again:" << endl;

	account2.display();

	
		
}
