#include "Account.h"

double Account::Balance(double balance, double intRate, double mthlyDeposit) {
	
	if (intRate > 0.0) {
		balance += (balance + (12 * mthlyDeposit)) * (intRate / 100);
	}
	else {
		balance += (balance + (12 * mthlyDeposit));
	}
	return balance;
}

double Account::InterestEarned(double balance, double origBalance) {
	double intEarned;

	intEarned = (balance - origBalance) - GetMthlyDeposit();

	return intEarned;
}