// Using SWITCH statements and CONDITIONAL OPERATORS 
// in order to calculate music charges, and using validation loops 
// to validate if the selection is a valid whole number of songs,
// also to make sure a negative number is NOT valid
// Date Modified: June 30, 2019

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void banner();
void getValidPackage(char &packChoice);
void getNumberSongs(double &downloadSongs);
////void printPackage();


int main()
{
	system("title Switch Case Lab - Online Music Store");
	system("color fc");

	banner();
	
	char packChoice;

	

	int songsToCharge, freeSongs;

	double downloadSongs, totalCharges, afterTax, chargesBeforeTax,
		chargePerSong, chargeNotFreeSongs, monthlyCharge;

	const int FREE_SONGS_A = 10,
		FREE_SONGS_B = 20,
		FREE_SONGS_C = 30;

	const double PACK_A_FEE = 4.99,
		PACK_B_FEE = 9.99,
		PACK_C_FEE = 14.99,
		FEE_PER_SONG_A = 0.99,
		FEE_PER_SONG_B = 0.59,
		FEE_PER_SONG_C = 0.29,
		TAX_RATE = 0.06;

	while (true)
	{
		cout << "Here are the posible option packages offered in our store: \n"
			<< "\t Package A: Monthly fee $" << PACK_A_FEE << ". " << FREE_SONGS_A << " free songs and $" << FEE_PER_SONG_A << " per song after that. \n"
			<< "\t Package B: Monthly fee $" << PACK_B_FEE << ". " << FREE_SONGS_B << " free songs and $" << FEE_PER_SONG_B << " per song after that. \n"
			<< "\t Package C: Monthly fee $" << PACK_C_FEE << ". " << FREE_SONGS_C << " free songs and $" << FEE_PER_SONG_C << " per song after that. \n\n";

		
		getValidPackage(packChoice);

		getNumberSongs(downloadSongs);

		if (packChoice >= 'a' && packChoice <= 'c')
		{
			cout << "\t I would like you to enter an UPPERCASE A, B, or C! \n";
			cout << "\t The programmer has corrected the lowercase \'a\', \'b\', or \'c\' "
				<< "into the UPPERCASE \'" << (packChoice -= ('a' - 'A'))
				<< "\' \n\n";
		}

		switch (packChoice)
		{
		case 'A':
			monthlyCharge = PACK_A_FEE;
			freeSongs = FREE_SONGS_A;
			chargePerSong = FEE_PER_SONG_A;
			break;
		case 'B':
			monthlyCharge = PACK_B_FEE;
			freeSongs = FREE_SONGS_B;
			chargePerSong = FEE_PER_SONG_B;
			break;
		case 'C':
			monthlyCharge = PACK_C_FEE;
			freeSongs = FREE_SONGS_C;
			chargePerSong = FEE_PER_SONG_C;
			break;
		}

		if (downloadSongs > freeSongs)
		{
			songsToCharge = downloadSongs - freeSongs;
			chargeNotFreeSongs = songsToCharge * chargePerSong;
			chargesBeforeTax = monthlyCharge + chargeNotFreeSongs;
			afterTax = chargesBeforeTax * TAX_RATE;
			totalCharges += afterTax;


			cout << "\t\tYour total bill for this month is $ " << chargesBeforeTax << " + $" << afterTax << " (for tax) = $" << chargesBeforeTax + afterTax << ". \n";
			cout << "\t\t You have $" << chargeNotFreeSongs << " extra charges for having " << songsToCharge << " more " << (songsToCharge > 1 ? "songs" : "song") << "\n";
			cout << "\t\t than your monthy limit of " << freeSongs << " free songs. \n\n";
		}

		else
		{
			totalCharges = monthlyCharge * TAX_RATE;
			cout << "Your total bill for this month is $" << monthlyCharge << " + $" << totalCharges << " (for tax) = $" << monthlyCharge + totalCharges << ". \n\n";
		}

		system("pause");

		cout << "\n\t\t*********************************************************************************************\n\n";
	}

	return 0;

}


void banner()
{
	cout << "\n"
		<< "\t\t\t              Switch Case INDIVIDUAL - LAB              \n"
		<< "\t\t\t               Part 2 Online Music Store                \n"
		<< "\t\t\t              with INPUT VALIDATION LOOPS               \n"
		<< "\t\t\t          also needs SWITCH and IF statements           \n"
		<< "\t\t\t              and the CONDITIONAL OPERATOR              \n"
		<< "\t\t\t                By: Frederick Vitug                     \n\n";

}

void getValidPackage(char &packChoice)
{
	
	cout << "Please select the option package that you have by typing in letter A, or B, or C?: ";
	cin >> packChoice;
	cin.ignore(100, '\n');

	while (packChoice < 'A' || packChoice > 'C' && packChoice < 'a' || packChoice > 'c')
	{
		cout << "\n\t*** Sorry we do not offer that package. Please choose from A, B, or C: ";
		cin >> packChoice;
		cin.ignore(100, '\n');
	}

}



void getNumberSongs(double &downloadSongs)
{
	cout << "How many songs did you download this month? ";
	cin >> downloadSongs;
	cin.ignore(100, '\n');

	cout << fixed << showpoint << setprecision(2);


	while ((fmod(downloadSongs, 1) != 0) || (downloadSongs < 0))
	{
		if ((fmod(downloadSongs, 1) != 0) && (downloadSongs < 0))
		{
			cout << "\t Please enter a WHOLE POSITIVE number. Please try again: ";
			cin >> downloadSongs;
			cin.ignore(100, '\n');
		}

		else
		{
			cout << "\t Please enter a " << ((fmod(downloadSongs, 1) != 0) ? "WHOLE " : "POSITIVE ")
				<< "number. Please try again: ";

			cin >> downloadSongs;
			cin.ignore(100, '\n');
		}
	}

}



//void printPackage()
//{
//	
//
//
//
//}
