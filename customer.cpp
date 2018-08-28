#include <iostream>
#include <string>
using namespace std;

class Customer {

	private:
		int id;
		int balance;
		string name;
		
	public:
		Customer(int a, int b, string n){
			id = a;
			balance = b;
			name = n;
		}
		int get_id() const {return id;}
		int get_balance() const {return balance;}
		string get_name() const {return name;}
		
		void set_balance(int b) {
			balance = b;		
		}

};

int main(){
	Customer c1(123,222, "mladjo");
		
	cout << c1.get_balance() << endl;
	c1.set_balance(1000000);
	cout << c1.get_balance();
	cout << c1.balance << endl;	
	return 0;
}
