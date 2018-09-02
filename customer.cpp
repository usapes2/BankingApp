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

void print_Rejected(Transaction t) {
	cout << "Rejected Tx: "<< t.get_id() <<","<<t.get_amount()<<endl;
}
void print_Invalid(Transaction t) {
	cout << "Invalid Tx: "<< t.get_id() <<","<<t.get_amount()<<endl;
}
int main(){

	string buffer;
	int count = 0;
	
	vector<Customer> v;
	
	ifstream in("/mnt/c/Users/acagu/Desktop/Projects/BankingApp/workingFiles/customers01.csv");
//	ifstream in("/mnt/c/Users/mladjo/Desktop/Projects/BankingApp/workingFiles/customers01.csv");
	while (getline(in,buffer,'\n')) 
	{
		string first = chopper(buffer);	
		string second = chopper(buffer);
		string third = chopper(buffer);
		
		Customer cust(atoi(second.c_str()), atof(third.c_str()), first);
		v.push_back(cust);

	} 


	for(int i=0; i<v.size(); i++){
		cout << v[i].get_id() << " " << v[i].get_balance() << " " << v[i].get_name() << endl;
}
	ifstream intrans("/mnt/c/Users/acagu/Desktop/Projects/BankingApp/workingFiles/transactions01.csv");
	//ifstream intrans("/mnt/c/Users/mladjo/Desktop/Projects/BankingApp/workingFiles/transactions01.csv");
cout<<"Processing..."<<endl;
	vector<Transaction> vtrans;
	while (getline(intrans,buffer,'\n')) 
	{
		string first = chopper(buffer);	
		string second = chopper(buffer);
		
		Transaction tr(atoi(first.c_str()),atof(second.c_str()));
		vtrans.push_back(tr);
	} 

	for ( int i = 0 ; i < vtrans.size() ; i++ ) {
		int id_temp = vtrans[i].get_id(); // temp ID 
		bool trigger = false ;
		for ( int j = 0 ; j < v.size() ; j++ ) {
			if(id_temp == v[j].get_id() ) {
				double balance = v[j].get_balance();
				double amount = vtrans[i].get_amount();
				if ( balance + amount >= 0 ) {
					v[j].set_balance(amount+balance);
					trigger = true;
				} else {print_Rejected(vtrans[i]);
					trigger = true; }
			} 
		}
		if ( trigger == false ) print_Invalid(vtrans[i]);
	      	


	}	




	/*for ( int i = 0 ; i < vtrans.size() ; i++ ) 
		cout << vtrans[i].get_id() << " " << vtrans[i].get_amount() << endl; */

/* // Testing Customer Class
	Customer c1(123,222, "mladjo");
		
	cout << c1.get_balance() << endl;
	c1.set_balance(1000000);

	*/
	for(int i=0; i<v.size(); i++){
		cout << v[i].get_id() << " " << v[i].get_balance() << " " << v[i].get_name() << endl;
}
 /* Testing Transaction class
 	Transaction trans(123, 34.43);
	
	cout << trans.get_amount() << endl;
*/	


	return 0;
}
