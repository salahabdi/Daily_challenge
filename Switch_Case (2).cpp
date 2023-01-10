// This is Lab#5 (Group Lab) about the swtich case Lab.
// This lab will be showing the use of switch case 
// This lab also using the WYSIWYG style for centering the banner.
// Lab#5 (Group lab): Switch Case Lab.
// Programmer: Abdirahman Salah.
// Last modified: 06/20/2019.

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

	system("color 90");
	system("Title Switch Case(Abdirahman Salah");

	cout << "\n"
		<< "\t\t\t\t      Switch Case GROUP Lab On line music store                              \n"
		<< "\t\t\t\t                       Switch Case                                           \n"
		<< "\t\t\t\t                  By: Abdirahman Salah                                       \n"
		<< "\t\t\t\t                       6/17/2019                                             \n";

	char menu;   //to hold the menu choice

	double totalsongs, mymusic, songs, AfterFreeSongs;

	const int
		freesong_A = 10,
		freesong_B = 20,
		freesong_C = 30;
	const double
		TAX = 0.06,
		RATE_A = 4.99,
		RATE_B = 9.99,
		RATE_C = 14.99,
		PRICE_AFTER_A = 0.99,
		PRICE_AFTER_B = 0.59,
		PRICE_AFTER_C = 0.29;

	cout << fixed << showpoint << setprecision(2);
	while (true)
	{
		cout << "\n"
			<< "Here are the posible option packages offered in our store:\n"
			<< "  Package A : Monthly fee $ 4.99. 10 free songs and $0.99 per song after that.   \n"
			<< "  Package B : Monthly fee $ 9.99. 20 free songs and $0.59 per song after that.   \n"
			<< "  Package C : Monthly fee $14.99. 30 free songs and $0.29 per song after that.   \n";

		cout << "Please select the package that you have?";
		cin >> menu;
		cin.ignore(100, '\n');

		if (songs > freesong_A)
		{
			mymusic = songs - freesong_A,
				mymusic = PRICE_AFTER_A * mymusic,
				totalsongs = mymusic + RATE_A + TAX;
		}
		else
		{
			if (songs <= freesong_A)
			{
				mymusic = RATE_A + TAX;
			}
		}



		if (songs > freesong_B)
		{
			mymusic = songs - freesong_B,
				mymusic = PRICE_AFTER_B * mymusic,
				totalsongs = mymusic + RATE_B + TAX;
		}
		else
		{
			if (songs <= freesong_B)
			{
				mymusic = RATE_B + TAX;
			}
		}

		if (songs > freesong_C)
		{
			mymusic = songs - freesong_C,
				mymusic = PRICE_AFTER_C * mymusic,
				totalsongs = mymusic + RATE_C + TAX;
		}
		else
		{
			if (songs <= freesong_C)
			{
				mymusic = RATE_C + TAX;
			}
		}
		switch (menu)
		{
		case 'a':
		case 'A':

			cout << "Your total bill for this month is " << totalsongs << "+ " << (totalsongs * TAX) << "(for tax) = " << totalsongs << endl;
			break;
		case 'b':
		case 'B':

			cout << "Your total bill for this month is " << totalsongs << "+ " << (totalsongs * TAX) << "(for tax) = " << totalsongs << endl;
			break;
		case 'c':
		case 'C':

			cout << "Your total bill for this month is " << totalsongs << "+ " << (totalsongs * TAX) << "(for tax) = " << totalsongs << endl;
			break;

		default:
			cout << "\n\t*** Sorry we do not offer that package. \n\n\n";
		}
		system("pause");
	}
	return 0;
}