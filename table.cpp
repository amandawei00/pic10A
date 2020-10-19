#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////
// pic10A assingment 3, table formatting                                                            //
// author: Amanda Wei                                                                               //
// student ID: 505 106 664                                                                          //
// date: 10/18/2020                                                                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	// declare variables
	string in1, in2, in3, xlabel, ylabel;
	int xlen, ylen, len, tol;
	double in11, in12, in21, in22, in31, in32, avgx, avgy, num, devx, devy, b, m, cc;
	int i3, i4, i5;

	cout << "Enter your first x- and y- values separated by a space: ";
	getline(cin, in1);  // reading input line including space
	i3 = in1.find(" ");  // index of the space in the input
	in11 = stod(in1.substr(0,i3));  //obtaining first value, splicing at the index of space
	in12 = stod(in1.substr(i3+1));  //obtaining second value

	// same procedure done to obtain the next two lines of data
	cout << "Enter your second x- and y- values separated by a space: ";
	getline(cin, in2);
	i4 = in2.find(" ");
	in21 = stod(in2.substr(0,i4));
	in22 = stod(in2.substr(i4+1));

	cout << "Enter your third x- and y- values separated by a space: ";
	getline(cin, in3);
	i5 = in3.find(" ");
	in31 = stod(in3.substr(0,i5));
	in32 = stod(in3.substr(i5+1));

	// prompting user for labels
	cout << "Enter your x-label: ";
	getline(cin, xlabel);
	xlen = xlabel.size();  // obtaining length of xlabel

	cout << "Enter your y-label: ";
	getline(cin, ylabel);
	ylen = ylabel.size();  // obtaining length of ylabel

	// promprting user for precision
	cout << "What level of precision would you like? ";
	cin >> tol;

	len = xlen + ylen + 1;  // total length of all five lines

	string l1 = xlabel + '|' + ylabel;  // first line concatenates xlabel, divider, and ylabel
	string l2(len, '-');  // the second line is dashes which run the length of total

	avgx = (in11 + in21 + in31)/3;  // average of x values
	avgy = (in12 + in22 + in32)/3;  //averge of y values

	// define values used more than once to calculate best fitting equation, correlation coefficient
	num = (in11 - avgx)*(in12 - avgy) + (in21 - avgx)*(in22 - avgy) + (in31 - avgx)*(in32 - avgy);
	devx = pow(in11 - avgx, 2) + pow(in21 - avgx, 2) + pow(in31 - avgx, 2);
	devy = pow(in12 - avgy, 2) + pow(in22 - avgy, 2) + pow(in32 - avgy, 2);
	
	m = num/devx;  // best fit slope m

	b = avgy - m*avgx;  // best fit intercept b

	cc = num/sqrt(devx*devy);  //correlation coefficient

	cout << fixed << showpoint << setprecision(tol);  // setting precision for doubles in the output
	cout << l1 << endl;  // output
	cout << l2 << endl;
	cout << setw(xlen) << in11 << '|' << in12 << setw(ylen) << endl;
	cout << setw(xlen) << in21 << '|' << in22 << setw(ylen) << endl;
	cout << setw(xlen) << in31 << '|' << in32 << setw(ylen) << endl;

	cout << "The best fitting equation is: y = " << m << "x + " << b << endl;
	cout << "The correlation coefficient is: " << cc << endl;
	return 0;

// end of program
}

