#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////
// pic10A assingment 2                                                                              //
// author: Amanda Wei                                                                               //
// student ID: 505 106 664                                                                          //
// date: 10/14/2020                                                                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	// declare variables
	int dollars, cents;
	string paid_dollar, paid_cents, c_dollar, c_cents, cash_dollar, cash_cents;
	int toonies, loonies;
	int fifty, q, d, n;
	double cash, paid, c;


	cout << "Enter true cost." << endl; 
	cout << "Give the dollars: "; //prompt user for information and then assign input to variable
	cin >> dollars;

	cout << "Now give the cents: ";
	cin >> cents;

	cash = dollars + round(cents/5.0 + 0.5)*5*0.01; // finds fractional nickel value, rounds, and then adds cent value to dollar value for total cash 

	cout << std::fixed << std::setprecision(2) << "In cash, the item costs: $" + std::to_string(cash) << endl; //outputting to two decimal points the total cash

	cout << "Enter payment details." << endl;

	cout << "Number of toonies: "; //prompt user for input to assign to variable
	cin >> toonies;

	cout << "Number of loonies: ";
	cin >> loonies;

	cout << "Number of fifty cent pieces: ";
	cin >> fifty;

	cout << "Number of quarters: "; 
	cin >> q;

	cout << "Number of dimes: ";
	cin >> d;

	cout << "Number of nickels: ";
	cin >> n;

	paid = (2*toonies) + loonies + (0.5*fifty) + (0.25*q) + (0.10*d) + (0.05*n); // calculating total paid dollar value

	paid_dollar = std::to_string(int(round(paid))); // calculates dollar value by truncating paid variable, casts as string for printing
	paid_cents = std::to_string(int((paid - round(paid)))*100); // calculates cent value by subtracting truncated value from total paid value
	cout << "You paid: " + paid_dollar + " dollar(s) and " + paid_cents + " cent(s))" << endl; // output

	c = paid - cash; // change due is difference between paid and cash
	c_dollar = std::to_string(int(round(c)));
	c_cents = std::to_string(int((c - round(c))*100));
	cout << "Your change due is: " + c_dollar + " dollar(s) and " + c_cents + " cent(s). Have a nice day, eh!" << endl;


// end of program
}
