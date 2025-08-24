#include <iostream>
using namespace std;

class Exam {
	private:
	string *name;
	string date;
	float score;
	
	public:
		Exam (string name, string date, float score) {
			this -> name = new string(name);
			this -> date = date;
			this -> score = score;
		}
		
		~Exam() {
        delete name;   
    }
						
		void display()  {
			cout << "Name:" << *name << endl;
			cout << "Date:" << date << endl;
			cout << "Score:" << score << endl;
		}
		
	
};

int main(){
	Exam examm("Rayyan", "18th Aug 2025", 83.0);
    examm.display();

    Exam exam2 = examm;
    
	cout << "Copy:" << endl;

	exam2.display();

	}
