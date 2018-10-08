/*
 *	Authors:	Jay Ramirez, Phillip Wong, Derrick Galindo
 *	Title:		Decimal to base(2-16) converter
 *	Class: 		CSCE 121-530
 *	Last Updated:	September 18, 2018
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main () {
	
	int decimal;
	int base;
	int quotient;
	int i;
	int tempVal;
	vector<int> remainder;
	vector<char> finalRemainder;
	
	//Input base-10 number
	cout << "Enter a decimal value : "; 
	cin >> decimal;
	
	//Set base to invalid base to have while loop
	//run at least once
	base = 17;

	//While loop keeps asking for base until valid 
	//base argument is given
	while ((base < 2) || (base > 16)) {
		cout << "Enter a base (2-16) : ";
		cin >> base;
	}
	
	//If decimal is zero, we can just print out 
	//zeroes instead of trying to calculate	
	if (decimal == 0) {
		cout << endl;
		cout << "Base-10 value : 0" << endl;
		cout << "Base-" << base << " value : 0" << endl;
		cout << "Digits required : 0" << endl;
		}
	
	//If decimal is not zero, we can calculate
	//digits
	else {	
		//Find first quotient
		quotient = decimal / base;

		//Store first base-n digit
		remainder.push_back(decimal % base);

		//If quotient is not zero, then there still 
		//are more base-n digits to add	
		while (quotient != 0) {
			remainder.push_back(quotient % base);
			quotient = quotient / base;
		}
	
		//Reverse the order of vector so that elements
		//will print out in order
		for (i = 0; i < (remainder.size() / 2); ++i) {
			tempVal = remainder.at(i);
			remainder.at(i) = remainder.at(remainder.size()-1-i);
			remainder.at(remainder.size()-1-i) = tempVal;
		}
	
		//Fill character vector with characters so that
		//digits greater than 9 can be replaced by 
		//letters A-F
		for (i = 0; i < remainder.size(); ++i) {
		
			switch (remainder.at(i)) {
				case 1:
					finalRemainder.push_back('1');
					break;

				case 2: 
					finalRemainder.push_back('2');
					break;

				case 3: 
					finalRemainder.push_back('3');
					break;
	
				case 4: 
					finalRemainder.push_back('4');
					break;
	
				case 5: 
					finalRemainder.push_back('5');
					break;
		
				case 6: 
					finalRemainder.push_back('6');
					break;
	
				case 7: 
					finalRemainder.push_back('7');
					break;
		
				case 8: 
					finalRemainder.push_back('8');
					break;
	
				case 9: 
					finalRemainder.push_back('9');
					break;

				case 10:
					finalRemainder.push_back('A');
					break;

				case 11:
					finalRemainder.push_back('B');
					break;
		
				case 12:
					finalRemainder.push_back('C');
					break;
				
				case 13:
					finalRemainder.push_back('D');
					break;

				case 14:
					finalRemainder.push_back('E');
					break;

				case 15:
					finalRemainder.push_back('F');
					break;
				
				default:
					finalRemainder.push_back('0');
				}
					
 		}

		//Print given decimal
		cout << endl;	
		cout << "Base-10 value : " << decimal << endl;
	
		cout << "Base-" << base << " value : ";

		//Print character vector in order
		for (i = 0; i < finalRemainder.size(); ++i) {
			cout << finalRemainder.at(i);
		}

		//Print number of digits required
		cout << endl;
		cout << "Digits required : " << finalRemainder.size() << endl;
	}
	return 0;
}
