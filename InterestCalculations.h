#ifndef AIRGEAD_INTERESTCALCULATIONS_H
#define AIRGEAD_INTERESTCALCULATIONS_H





#include<vector>

#include "DataInput.h"

using namespace std;

class InterestCalculations {
private: 
	// declare private members
	double m_year = 0;
	double m_yearEndBalance = 0;
	double m_yearEndInterest = 0;
	
	
	double m_monthlyDeposits = 0;
	double m_annualInterest = 0;
	double m_initialInvestment= 0;
public:
	 // declare functionst to calculate the year end balances for interest with and without monthly deposits
	InterestCalculations();
	InterestCalculations(DataInput t_userInput);
	
	void balanceWithOutMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposits, double t_annualInterest, int t_numOfYears);
	void balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposits, double t_annualInterest, int t_numOfYears);
};


#endif // AIRGEAD_INTERESTCALCULATIONS_H

