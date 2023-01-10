// This is Lab#3 (Group Lab) about the swtich case Lab.
// This lab using the OS commands to change the color and the name of title bar. 
// This lab also using the WYSIWYG style for centering the banner.
// Lab#3 (Group lab): Switch Case Lab.
// Programmer: Abdi salah.
// Last modified: 07/09/2019.

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

void showBanner();
void getValidPackage(char &);
void getPosInt(double &);
void getNum(double &);

int main()
{
	char packChoice;
	int freeSongs;
	double downloadSongs, chargesBeforeTax, monthlyCharge, chargePerSong;
	const int
		FREE_SONG_A = 10,
		FREE_SONG_B = 20,
		FREE_SONG_C = 30;
	const double
		TAX_RATE = 0.06,
		MONTHLY_FEE_A = 4.99,
		MONTHLY_FEE_B = 9.99,
		MONTHLY_FEE_C = 14.99,
		PRICE_AFTER_A = 0.99,
		PRICE_AFTER_B = 0.59,
		PRICE_AFTER_C = 0.29;

	system("title Swtich Case Lab -- Online Music Store by Cong Pham");
	system("color E2");

	showBanner();

	while (true)
	{
		cout << "Here are the posible option packages offered in our store: \n"
			<< "\tPackage A: Monthly fee $ " << MONTHLY_FEE_A << ". " << FREE_SONG_A << " free songs and $" << PRICE_AFTER_A << " per song after that.\n"
			<< "\tPackage B: Monthly fee $ " << MONTHLY_FEE_B << ". " << FREE_SONG_B << " free songs and $" << PRICE_AFTER_B << " per song after that.\n"
			<< "\tPackage C: Monthly fee $ " << MONTHLY_FEE_C << ". " << FREE_SONG_C << " free songs and $" << PRICE_AFTER_C << " per song after that.\n\n";

		getValidPackage(packChoice);

		getNum(downloadSongs);

		switch (packChoice)
		{
		case 'a':
		case 'A':
			freeSongs = FREE_SONG_A;
			monthlyCharge = MONTHLY_FEE_A;
			chargePerSong = PRICE_AFTER_A;
			break;

		case 'b':
		case 'B':
			freeSongs = FREE_SONG_B;
			monthlyCharge = MONTHLY_FEE_B;
			chargePerSong = PRICE_AFTER_B;
			break;

		case 'c':
		case 'C':
			freeSongs = FREE_SONG_C;
			monthlyCharge = MONTHLY_FEE_C;
			chargePerSong = PRICE_AFTER_C;
			break;
		}

		cout << fixed << showpoint << setprecision(2);

		if (downloadSongs > freeSongs)
		{
			double chargeNotFreeSongs, afterTax;
			int songsToCharge;

			songsToCharge = downloadSongs - freeSongs;
			chargeNotFreeSongs = songsToCharge * chargePerSong;
			chargesBeforeTax = monthlyCharge + chargeNotFreeSongs;
			afterTax = chargesBeforeTax * TAX_RATE;
			chargesBeforeTax += afterTax;

			cout << "\tYour total bill for this month is " << monthlyCharge << " + " << afterTax << " (for tax) = " << chargesBeforeTax << ".\n"
				<< "\tYou have $ " << chargeNotFreeSongs << " extra charges for having " << songsToCharge << " more " << (songsToCharge > 1 ? "songs" : "song") << endl
				<< "\tthan your monthly limit of " << freeSongs << " free songs.\n\n";
		}
		else
		{
			chargesBeforeTax = monthlyCharge * TAX_RATE;
			cout << "Your total bill for this month is " << monthlyCharge << " + " << chargesBeforeTax << " (for tax) = " << monthlyCharge + chargesBeforeTax << ".\n\n";
		}

		system("pause");
		cout << "\n\t\t************************************************************\n\n";
	}
	return 0;
}

void showBanner()
{
	cout << "\n"
		<< "\t\t                  Switch Case GROUP Lab                   \n"
		<< "\t\t                   On line music store                    \n"
		<< "\t\t                      with FUNCTIONS                      \n"
		<< "\t\t         also needs nested if ... else statements         \n"
		<< "\t\t               and the conditional operator               \n"
		<< "\t\t                      by Cong Pham						  \n\n";
}

void getValidPackage(char &letter)
{
	cout << "Please select the option package that you have by typing in letter A, or B, or C?: ";
	cin >> letter;
	cin.ignore(100, '\n');

	while (letter < 'A' || letter > 'C' && letter < 'a' || letter > 'c')
	{
		cout << "\n\t*** Sorry we do not offer that package. Please choose from A, B, or C: ";
		cin >> letter;
		cin.ignore(100, '\n');
	}
}

void getPosInt(double &number)
{
	cout << "How many songs did you download this month? ";
	cin >> number;
	cin.ignore(100, '\n');

	while ((fmod(number, 1) != 0) || (number < 0))
	{
		if ((fmod(number, 1) != 0) && (number < 0))
		{
			cout << "\t Please enter a WHOLE POSITIVE number. Please try again: ";
			cin >> number;
			cin.ignore(100, '\n');
		}
		else
		{
			cout << "\t Please enter a " << ((fmod(number, 1) != 0) ? "WHOLE " : "POSITIVE ")
				<< "number. Please try again: ";

			cin >> number;
			cin.ignore(100, '\n');
		}
	}
}

void getNum(double &numSongs)
{
	getPosInt(numSongs);

	while (!cin || (fmod(numSongs, 1) != 0) || (numSongs < 0))
	{
		cout << "\t Please enter a suitable number: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> numSongs;
	}
}