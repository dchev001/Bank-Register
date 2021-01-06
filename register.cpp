#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// class declaration
class Register
{
	private:
		int checkNum;
		string transaction;
		double amount;
		int month, day, year;

	public:
		// check number get
		int getCheckNum()
		{
			return checkNum;
		}

		// check number set
		void setCheckNum(int num)
		{
			checkNum = num;
		}

		// amount get method
		double getAmount()
		{
			return amount;
		}

		// amount set method
		void setAmount(double num)
		{
			amount = num;
		}

		// transaction get method
		string getTransaction()
		{
			return transaction;
		}

		// transaction set method
		void setTransaction(string trans)
		{
			transaction = trans;
		}

		// month get method
		int getMonth()
		{
			return month;
		}

		// month set method
		void setMonth(int m)
		{
			month = m;
		}

		// day get method
		int getDay()
		{
			return day;
		}

		// day set method
		void setDay(int d)
		{
			day = d;
		}

		// year get method
		int getYear()
		{
			return year;
		}

		// year set method
		void setYear(int y)
		{
			year = y;
		}

		// display info
		string displayInfo()
		{
			return to_string(this->getCheckNum()) + ", " + to_string(this->getMonth()) + "/" + to_string(this->getDay()) + "/"
				+ to_string(this->getYear()) + ", \"" + this->getTransaction() + "\", " + to_string(this->getAmount()) + "\n";
		}
};

int main()
{
	// variables
	Register temp;
	int num;
	double amount;
	string trans;
	int month, day, year;

	// file declaration and open
	ofstream outfile;
	outfile.open("register.csv", ios::app);

	// get information from user
	cout << "Please type in transaction: ";
	getline(cin, trans);
	temp.setTransaction(trans);

	cout << "Please type in check number: ";
	cin >> num;
	temp.setCheckNum(num);

	cout << "Please type in amount: ";
	cin >> amount;
	temp.setAmount(amount);

	cout << "Please type in month: ";
	cin >> month;
	temp.setMonth(month);

	cout << "Please type in day: ";
	cin >> day;
	temp.setDay(day);

	cout << "Please type in year: ";
	cin >> year;
	temp.setYear(year);

	// write information to file
	outfile << temp.displayInfo();

	// close file
	outfile.close();

	return 0;
}
