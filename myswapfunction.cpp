// This lab will use function to do a swap of integers 
// Swap Function
// By Abdi Salah
// 7/3/2019

#include <iostream>
using namespace std;

void swapFunc(int &, int &);
void trivialBanner();

int main()
{
	system("color fc");
	system("title Swap Function Lab --- Abdirahman Salah");

	trivialBanner();

	int x, y;
	

	while (true)
	{
		
		cout << " Please type an INTEGER for x: ";
		cin >> x;
		cin.ignore(100, '\n');

		cout << " Please type an INTEGER for y: ";
		cin >> y;
		cin.ignore(100, '\n');

		cout << "BEFORE the function call:  " << "X = " << x << " " << "Y = " << y << endl;
		cout << " I am calling the mySwap function ...\n";

		swapFunc(x, y);
		cout << "AFTER the function call:   " << "X = " << x << " " << "Y = " << y << endl;
		cout << "NOTE: The debugging couts are in the main. The actual swaping is happenind in the function. \n\n";
		
		system("pause");
	}
	return 0;
}

void swapFunc(int &userinput, int &secondinput)
{
	int z;
	z = userinput;
	userinput = secondinput;
	secondinput = z;

}

void trivialBanner()  
{

	cout << "\n"
		<< "\t\t\t\t                      swap function                            \n"
		<< "\t\t\t\t                       and drivers                             \n"
		<< "\t\t\t\t                  By: Abdi Salah                         \n"
		<< "\t\t\t\t                       7/3/2019                                \n\n";
}
