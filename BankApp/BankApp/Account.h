#pragma once
class Account {
	
public:
	double Balance(double balance, double intRate, double mthlyDeposit);
	double InterestEarned(double balance, double origBalance);
	void SetInitial(double initial) { this->initialInv = initial; }
	double GetInitial() { return this->initialInv; }
	void SetMthlyDeposit(double deposit) { this->mthlyDeposit = deposit; }
	double GetMthlyDeposit() { return this->mthlyDeposit; }
	void SetNumYears(double years) { this->numYears = years; }
	double GetNumYears() { return this->numYears; }
	void SetAnnualRate(double rate) { this->annualRate = rate; }
	double GetAnnualRate() { return this->annualRate; }


private:
	double initialInv;
	double mthlyDeposit;
	double annualRate;
	double numYears;

};

