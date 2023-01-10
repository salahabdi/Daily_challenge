// This is lab about Positive number classification perfect, abundant, or deficient.
// This lab using the OS commands to change the color and the name of title bar. 
// This lab also using the WYSIWYG style for centering the banner.
// Lab: Positive number classification.
// Programmer: Abdi Salah.
// Last modified: 06/25/2019.

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

	system("color E1");
	system("title Classify a POSITIVE number as Deficient, Perfect or Abundant by (Abdirahman Salah)");

	cout << "\n"
		<< "\t\t\t    Positive number classification as          \n"
		<< "\t\t\t      perfect, abundant, or deficient          \n"
		<< "\t\t\t           by: Abdirahman Salah                \n\n";

	int x, num, div, sum = 0;

	while (true)
	{
		cout << "Enter a number to be classified as perfect, abundant, or deficient: ";
		cin >> num;

		while (num < 0)
		{
			cout << "This classification is for POSITIVE integers only. Please try again: ";
			cin >> num;
		}
		for (x = 1; x < num; x++)
		{
			div = num % x;
			sum = 0;
			if (div == 0)
				sum = sum + x;
		}
		if (sum == num)
			cout << num << " is a perfect number\n";

		else if (sum < num)
			cout << num << " is deficient";
		else if (sum > num)
			cout << num << " is abundant";

		system("pause");

	}

	return 0;

}


