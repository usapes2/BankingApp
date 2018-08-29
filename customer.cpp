#include <iostream>
#include <string>
#include <fstream>
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

	string buffer;
	int count = 0;

	ifstream in("/mnt/c/Users/acagu/Desktop/Projects/BankingApp/workingFiles/customers01.csv");
	while (getline(in,buffer,'\n')) 
	{
		string::size_type L = buffer.length(); // This is the length of the line
		string::size_type c1 = buffer.find(",");
		
		string first = buffer.substr(0,c1); 
		cout << first << endl;

		buffer = buffer.substr(c1+1,L-1);
		 L = buffer.length(); // This is the new lenght of the line

		string::size_type c2 = buffer.find(",");
		string second = buffer.substr(0,c2);
		cout << second << endl;

		string third = buffer.substr(c2+1,L-1);

		cout << third << endl;
		cout <<" ___________________________ "<< endl;
	}
	
	
/* // Testing Customer Class
	Customer c1(123,222, "mladjo");
		
	cout << c1.get_balance() << endl;
	c1.set_balance(1000000);
	cout << c1.get_balance(); */
	return 0;
}
