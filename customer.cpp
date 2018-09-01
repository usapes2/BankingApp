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
		
		void set_balance(double b) {
			balance = b;		
		}
};
class Transaction{
	
	private:
		int id;
		double amount;
	
	public:
/*		Transaction(int a, double b){
			id = a;
			amount = b;
		}*/

		Transaction(int a, double b):id(a),amount(b) {} // constructor proper definition
		
		int get_id() const {return id;}
		double get_amount() {return amount;}
};
string chopper(string& buffer) {

		string::size_type L = buffer.length(); // This is the length of the line
		if ( L!=string::npos) { 
		string::size_type c1 = buffer.find(",");
		string first = buffer.substr(0,c1); 
		buffer = buffer.substr(c1+1,L-1); 

	return first; }
		else return buffer;
}
int main(){

	string buffer;
	int count = 0;
	
	vector<Customer> v;
	
	//ifstream in("/mnt/c/Users/acagu/Desktop/Projects/BankingApp/workingFiles/customers01.csv");
	ifstream in("/mnt/c/Users/mladjo/Desktop/Projects/BankingApp/workingFiles/customers01.csv");
	while (getline(in,buffer,'\n')) 
	{
		string first = chopper(buffer);	
		string second = chopper(buffer);
		string third = chopper(buffer);

		
		Customer cust(atoi(second.c_str()), atof(third.c_str()), first);
		v.push_back(cust);

	//	cout << cust.get_id() << " " << cust.get_balance() << " " << cust.get_name() << endl;


	} 

	Transaction trans(123, 34.43);
	
	cout << trans.get_amount() << endl;
	


/* // Testing Customer Class
	Customer c1(123,222, "mladjo");
		
	cout << c1.get_balance() << endl;
	c1.set_balance(1000000);

	*/
//	for(int i=0; i<v.size(); i++){
//		cout << v[i].get_id() << " " << v[i].get_balance() << " " << v[i].get_name() << endl;
//}	


	return 0;
}
