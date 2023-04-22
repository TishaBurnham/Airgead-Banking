//
//									AIRGEAD BANKING INTEREST CALCULATOR
// Latisha Burnham
// April 2023

#include <string>
#include <iostream>
#include "DataInput.h"
#include "InterestCalculations.h"

using namespace std;

int main(void) {

	// declare variables
	double initialInvestment;
	double monthlyDep;
	double yearlyInterest;
	int numOfYears;
	DataInput values;

	// obtain user input through DataInput class function
	values.dataInputMenu(initialInvestment, monthlyDep, yearlyInterest, numOfYears);

	// declare a InterestCalculations obj and print out the values using methods in the class
	InterestCalculations balances;
	balances.balanceWithOutMonthlyDeposit(initialInvestment, monthlyDep, yearlyInterest, numOfYears);
	balances.balanceWithMonthlyDeposit(initialInvestment, monthlyDep, yearlyInterest, numOfYears);

	return 0;
}