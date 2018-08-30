#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

class Customer {

	private:
		int id;
		double balance;
		string name;
		
	public:
		Customer(int a, double b, string n){
			id = a;
			balance = b;
			name = n;
		}
		int get_id() const {return id;}
		double get_balance() const {return balance;}
		string get_name() const {return name;}
		
		void set_balance(int b) {
			balance = b;		
		}

};

int main(){

	string buffer;
	int count = 0;
	
	vector<Customer> v;
	
	ifstream in("/mnt/c/Users/mladjo/Desktop/Projects/BankingApp/workingFiles/customers01.csv");
	while (getline(in,buffer,'\n')) 
	{
		string::size_type L = buffer.length(); // This is the length of the line
		string::size_type c1 = buffer.find(",");
		string first = buffer.substr(0,c1); 
	//	cout << first << endl;
		buffer = buffer.substr(c1+1,L-1);
		L = buffer.length(); // This is the new lenght of the line
		string::size_type c2 = buffer.find(",");
		string second = buffer.substr(0,c2);
	//	cout << second << endl;
		string third = buffer.substr(c2+1,L-1);
	//	cout << third << endl;
	//	cout <<" ___________________________ "<< endl;
		
		Customer cust(atoi(second.c_str()), atof(third.c_str()), first);
//		int i = atoi(first.c_str());
		v.push_back(cust);

	//	cout << cust.get_id() << " " << cust.get_balance() << " " << cust.get_name() << endl;


		
		


	}
	for(int i=0; i<v.size(); i++){
		cout << v[i].get_id() << " " << v[i].get_balance() << " " << v[i].get_name() << endl;
}	


/* // Testing Customer Class
	Customer c1(123,222, "mladjo");
		
	cout << c1.get_balance() << endl;
	c1.set_balance(1000000);
	cout << c1.get_balance(); */
	return 0;
}
