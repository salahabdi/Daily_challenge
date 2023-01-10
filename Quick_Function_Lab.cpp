// This Lab is about functions.
// This lab i'm using the OS commands to change the color of 
// the console and the name of title bar. 
// i'm also using the WYSIWYG style for centering the banner.
// The Group Lab#2: Quick Function Lab.
// Programmer: Abdi salah.
// Last modified: 07/01/2019.

#include <iostream>
using namespace std;

int getInputValidation();
double readPositiveInt();
bool isaNumberPrime( int usernum);  // function name
double getSumProduct(double value1, double value2);  //done  -- function name
double absoluteValue(double num);  // done  -- function name_
void trivialBanner();  // done


int main()
{
	system("title Quick lab Function----- by Abdirahman Salah");
	system("color B0");
	trivialBanner();

	int x, usernum;
	double userinput; // to validate the user input
	double num;
	double value1, value2;
	double isprime;
	double sum;
	

	while (true)

	{ 
		// absolute value
		cout << "\n";
		cout << "What number you want me to find the absolute value of? ";
		cin >> num;
		cin.ignore(100, '\n');

		cout << " The absolute value is " << absoluteValue(num) << "\n";
		
		// my sumProduct function
		cout << "What the first number? ";
		cin >> value1;
		cin.ignore(100, '\n');

		cout << "What is the second number? \n";
		cin >> value2;
		cin.ignore(100, '\n');

		cout << "The result of sumProd with arguments " << value1 << " and " << value2 << " is "<< getSumProduct(value1, value2) << "\n\n";

		// is a number a prime or not
		cout << " Please give me a number and I will tell you if it is prime or not: ";
		cin >> usernum;
		cin.ignore(100, '\n');

		if (isaNumberPrime(usernum) == false)
			cout << " Your number " << usernum << " is NOT a prime number.\n\n";
		else 
			cout << "Your number " << usernum << " is a prime number\n\n";

		// validation of prime number 
		isprime = getInputValidation();
		cout << "you gave me " << isprime << " which is prime number "<< "\n\n";

		//positive number
		sum = readPositiveInt();
		cout << "The sum of all the positive numbers are " << sum << "\n\n";



		system("pause");
	}
}

void trivialBanner()  // done
{
	
	cout << "\n"
		<< "\t\t\t\t                    Quick Function Lab                                       \n"
		<< "\t\t\t\t                       Functions                                             \n"
		<< "\t\t\t\t                  By: Abdi Salah                                       \n"
		<< "\t\t\t\t                       7/1/2019                                              \n\n";

}

double absoluteValue(double num)  // done
{
	
	return (num < 0 ? -num : num);
	
}

double getSumProduct(double value1, double value2)   // done
{
	return (value1 * value2 < 0 ? value1 * value2 : value1 + value2);
}

bool isaNumberPrime( int usernum)
{
	int x;
	for (x = 2; x < usernum; x++)
		if (usernum % x == 0)
			return false;

	return true;
}

int getInputValidation()
{
	int userinput;
	cout << " Please give me a prime number:";
	cin >> userinput;

	while (isaNumberPrime(userinput) == false)
	{
		cout << "Enter another value";
		cin >> userinput;
	}
	return userinput;
}

double readPositiveInt()
{
	double total = 0;
	double number;
	cout << " Please enter a positive number ";
	cin >> number;
	cin.ignore(100, '\n');
	while (number > 0)
	{
		total = total + number;
		cout << " Please enter a positive number ";
		cin >> number;

	}
	return total;
}
