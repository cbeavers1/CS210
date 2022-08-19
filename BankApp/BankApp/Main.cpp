/*
Name: Charles Beavers
Date: 7/31/2022
Class: CS-210
*/

#include <iomanip>
#include <iostream>
#include <vector>
#include "Account.h"
#include <exception>

using namespace std;

// Method to repeat characters for menu formatting 
string MenuFormat(char menuChar, int length ) {
	string format;

	for (int i = 0; i < length; ++i) {
		format = format + menuChar;
	}

	return format;
}

// Method for printing data on table
void PrintTable(Account account, string with) {
	double balance = account.GetInitial();

	cout << fixed << setprecision(2) << endl;
	cout << "    Balance and Interest " << with << " Additional Monthly Deposits" << endl;
	cout << MenuFormat('*', 64) << endl;
	cout << MenuFormat('-', 64) << endl;
	cout << "  Year        Year End Balance     Year End Earned Interest" << endl;
	cout << MenuFormat('-', 64) << endl;
	for (int i = 0; i < account.GetNumYears(); ++i) {
		double origBalance = balance;
		balance = account.Balance(balance, account.GetAnnualRate(), account.GetMthlyDeposit());
		double intEarned = account.InterestEarned(balance, origBalance);
		cout << "    " << i + 1 << MenuFormat(' ', 15) << "$" << balance << MenuFormat(' ', 18) << "$" << intEarned << endl;
	}

}

// Initial menu for gathering input
void InputMenu(Account& account) {
	double initialInv; 
	double deposit; 
	double interest;
	double years;
	exception error;

	// Loop to gather input with try blocks for is==kkkkkv
	while (true) {
		try {
			cout << MenuFormat('*', 34) << endl;
			cout << MenuFormat('*', 11) << " Data Input " << MenuFormat('*', 11) << endl;
			cout << "Initial Investment: $";
			cin >> initialInv;
			if (!cin) {
				throw error;
			}
			cout << endl;
			cout << "Monthly Deposit: $";
			cin >> deposit;
			if (!cin) {
				throw error;
			}
			cout << endl;
			cout << "Annual Interest: %";
			cin >> interest;
			if (!cin) {
				throw error;
			}
			cout << endl;
			cout << "Number Of Years: ";
			cin >> years;
			if (!cin) {
				throw error;
			}
			cout << endl;
		}
		catch (exception error) {
			// Display error message and restart loop for new data
			cout << "Invalid input. Try again." << endl;
			system("pause");

			cin.clear(); // Clear error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
			system("cls");

			continue;
		}
		break;
	}

	account.SetAnnualRate(interest);
	account.SetInitial(initialInv);
	account.SetMthlyDeposit(deposit);
	account.SetNumYears(years);
}



int main() {
	
	while (true) {
		string with;

		Account account;
		InputMenu(account);

		system("pause");
		system("cls");

		if (account.GetMthlyDeposit() <= 0.0) {
			with = "without";
		}
		else {
			with = "with";
		}

		// Print table with data given for the account
		PrintTable(account, with);
		system("pause");
		system("cls");

		// Check for additional values
		char data; 
		cout << "Would you like to try with different data? (Y/N)" << endl;
		cin >> data;
		if (data == 'Y' || data == 'y') {
			system("cls");
			continue; // Re-enter loop
		}
		else {
			cout << "Goodbye" << endl;
			break;
		}
	}


	return 0;
}