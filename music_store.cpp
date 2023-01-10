// Creating a 2 validation functions, also creating a function to 
// do the calculations for the total bill of the music store,  
// and also creating a print banner function, as well as a 
// function to print the package choices
// Team Orange
// Date Modified: July 9, 2019, 1:50PM

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// Function declaration prototype
void printBanner();
void printPackageMenu(const string &packChoices, const double &packFee, const int &freeSongs, const double &feePerSong);
void getValidPack(char &userPackChoice);
void correctLowerToUpper(char &userLowerPackChoice);
void getPosInt(double &userDownloadSongs);
void getNum(double &userNumSongs);

int main() {

	system("title Online Music Store -- With Functions Group Lab Part 3 (Team Orange)");
	system("color E2");

	// Call print banner function
	printBanner();

	char packChoice;

	int songsToCharge, freeSongs;

	double downloadSongs, totalCharges,
		afterTax, chargesBeforeTax,
		chargePerSong, chargeNotFreeSongs,
		monthlyCharge;

	const int FREE_SONGS_A = 10, FREE_SONGS_B = 20, FREE_SONGS_C = 30;

	const double PACK_A_FEE = 4.99, PACK_B_FEE = 9.99, PACK_C_FEE = 14.99,
		FEE_PER_SONG_A = 0.99, FEE_PER_SONG_B = 0.59, FEE_PER_SONG_C = 0.29,
		TAX_RATE = 0.06;

	const string PACKAGE_A = "Package A", PACKAGE_B = "Package B", PACKAGE_C = "Package C";

	while (true) {

		cout << "Here are the posible option packages offered in our store: \n";

		// Call print package menu 3 times
		printPackageMenu(PACKAGE_A, PACK_A_FEE, FREE_SONGS_A, FEE_PER_SONG_A);
		printPackageMenu(PACKAGE_B, PACK_B_FEE, FREE_SONGS_B, FEE_PER_SONG_B);
		printPackageMenu(PACKAGE_C, PACK_C_FEE, FREE_SONGS_C, FEE_PER_SONG_C);

		cout << "\nPlease select the option package that you have by typing in the letter A, B, or C?: ";
		cin >> packChoice;
		cin.ignore(100, '\n');

		// Call the validate package choice function
		getValidPack(packChoice);

		cout << "How many songs did you download this month? ";
		cin >> downloadSongs;
		cin.ignore(100, '\n');

		cout << fixed << showpoint << setprecision(2);

		// Call validate if the song user entered is a positive number and a whole number
		getPosInt(downloadSongs);
		getNum(downloadSongs);

		// Call the function I added that informs the user if they used a lower case letter
		// and corrects the lower case into UPPER CASE. Not required just thought it was cool
		correctLowerToUpper(packChoice);

		switch (packChoice) {

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

		if (downloadSongs > freeSongs) {

			// For now we will not have a function to calculate the bill
			songsToCharge = downloadSongs - freeSongs;
			chargeNotFreeSongs = songsToCharge * chargePerSong;
			chargesBeforeTax = monthlyCharge + chargeNotFreeSongs;
			afterTax = chargesBeforeTax * TAX_RATE;
			totalCharges += afterTax;

			cout << "\t\tYour total bill for this month is $ " << chargesBeforeTax << " + $" << afterTax << " (for tax) = $" << chargesBeforeTax + afterTax << ". \n";
			cout << "\t\t You have $" << chargeNotFreeSongs << " extra charges for having " << songsToCharge << " more " << (songsToCharge > 1 ? "songs" : "song") << "\n";
			cout << "\t\t than your monthy limit of " << freeSongs << " free songs. \n\n";
		}

		else {

			// For now only keeping it in the main 
			totalCharges = monthlyCharge * TAX_RATE;

			cout << "Your total bill for this month is $" << monthlyCharge
				<< " + $" << totalCharges << " (for tax) = $"
				<< monthlyCharge + totalCharges << ". \n\n";
		}

		system("pause");

		cout << "\n\t\t*******************************************************************************\n\n";
	}

	return 0;
}

// Function definition to print banner
void printBanner() {

	cout << "\n"
		<< "\t\t\t          Adding functions to the Online Music Store for          \n"
		<< "\t\t\t        the validation of the package choice as well as if        \n"
		<< "\t\t\t     the user enters a negative number or decimal number will     \n"
		<< "\t\t\t                validate using created functions.                 \n"
		<< "\t\t\t             Music Store With FUNCTIONS -  Group Lab              \n"
		<< "\t\t\t                    By:  Team Orange                    \n\n\n";
}

// Function definition for the function that will print the package shoice menu
void printPackageMenu(const string &packChoices, const double &packFee, const int &freeSongs, const double &feePerSong) {

	cout << "\t"
		<< packChoices << ": Monthly fee $" << packFee << ". "
		<< freeSongs << " free songs and $" << feePerSong
		<< " per song after that. \n";
}

// Function definition for validating the package choice the user entered
void getValidPack(char &userPackChoice) {

	while (userPackChoice < 'A' || userPackChoice > 'C' && userPackChoice < 'a' || userPackChoice > 'c') {

		cout << "\n\t*** Sorry we do not offer that package. Please choose from A, B, or C: ";
		cin >> userPackChoice;
		cin.ignore(100, '\n');
	}
}

// Function definition for the function that will correct the user if they enter a lower case letter into an UPPER CASE letter
void correctLowerToUpper(char &userLowerPackChoice) {

	if (userLowerPackChoice >= 'a' && userLowerPackChoice <= 'c')
	{
		cout << "\t I would like you to enter an UPPERCASE A, B, or C! \n";
		cout << "\t The programmer has corrected the lowercase \'a\', \'b\', or \'c\' "
			<< "into the UPPERCASE \'" << (userLowerPackChoice -= ('a' - 'A'))
			<< "\' \n\n";
	}
}

// Function definition which will let the user know that we need a positive number of songs and you also need a whole number NO DECIMAL
void getPosInt(double &userDownloadSongs) {

	while ((fmod(userDownloadSongs, 1) != 0) || (userDownloadSongs < 0)) {

		if ((fmod(userDownloadSongs, 1) != 0) && (userDownloadSongs < 0)) {

			cout << "\t Please enter a WHOLE POSITIVE number. Please try again: ";
			cin >> userDownloadSongs;
			cin.ignore(100, '\n');
		}

		else
		{
			cout << "\t Please enter a " << ((fmod(userDownloadSongs, 1) != 0) ? "WHOLE " : "POSITIVE ")
				<< "number. Please try again: ";
			cin >> userDownloadSongs;
			cin.ignore(100, '\n');
		}
	}
}

// Function definition for a function which will validate if the user entered a digit for downloaded songs
void getNum(double &userNumSongs) {

	getPosInt(userNumSongs);

	while (!cin || ((fmod(userNumSongs, 1) != 0)) || (userNumSongs < 0)) {

		cout << "\t Please enter a " << (!cin ? "digit/number, and not spell out the number: " : "WHOLE POSITIVE number: ");
		cin.clear();
		cin.ignore(100, '\n');
		cin >> userNumSongs;
	}
}

