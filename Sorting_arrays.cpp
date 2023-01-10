#include <iostream>
#include <string>
using namespace std;

class sorting
{

	int num[100];
	int newmun;
	int value;

public:

	void get_number();
	void sort_number();
	void printbanner();
	
};




void sorting::printbanner()
{
	system("color fc");
	cout << "\n"
		<< "\t\t This is a sorting program"
		<< "\n"
		<< ".............................................\n" ;

}
void sorting::get_number()
{
	cout << "Enter a list of numbers you would like to be sorted:  \n";
	for (int i = 0; i < 5; i++)
	{
		cin >> num[i];
	}
}
void sorting::sort_number()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (num[i] < num[j])
			{
				newmun = num[i];
				num[i] = num[j];
				num[j] = newmun;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << " " << num[i] << endl;
	}
}

int main()
{
	while (true)
	{
		sorting sort;
		sort.printbanner();
		sort.get_number();
		sort.sort_number();
		
		system("pause");
	}
}
