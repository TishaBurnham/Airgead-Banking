#include <iostream>
#include<iomanip>
#include "InterestCalculations.h"


using namespace std;

InterestCalculations::InterestCalculations() {
	m_year = 0;
	m_monthlyDeposits = 0;
	m_annualInterest = 0;
	m_initialInvestment = 0;
	
} // define default constructor

InterestCalculations::InterestCalculations(DataInput t_userInput) {
	m_year = t_userInput.getYears();
	m_monthlyDeposits = t_userInput.getMonthlyDeposits();
	m_annualInterest = t_userInput.getAnnualInterest();
	m_initialInvestment = t_userInput.getInitialnvestment();
}

/**
 * Calculates and returns an end of year balance for given number of years
 *
 * @param initialInvestment dollar amount of initial investment
 * @param interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param numberOfYears number of years to calculate balance for
 *
 */
// Function calculates te year end balance with no monthly deposits. Uses input for DataInput class
void InterestCalculations::balanceWithOutMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposits, double t_annualInterest, int t_numOfYears) {
	//print table for values

	const int M_MONTHS_IN_YEAR = 12;
	double m_compoundInterest;
	double m_yearEndInterest;
	double m_endOfYearBalance = t_initialInvestment;

	// Outputs menu header and formats the outputs in chart form
	cout << endl << endl;
	cout << setw(70) << setfill('=') << endl;
	cout << setw(70) << left << setfill(' ') << "    Balance and Interest Without Additional Monthly Deposits  " << endl;
	cout << string(70, '=') << endl;
	//cout << setw(70) << setfill('=') << "\n" << endl;

	cout << " Year " << "                    Year End Balance" << setw(35) << right << "  Year End Earned Interest" << endl;
	//cout << setw(70) << setfill('-') << endl;


	// loops through values to print balances for each year bases on input
	for (int currentYear = 1; currentYear <= t_numOfYears; currentYear++) {
		m_compoundInterest = m_endOfYearBalance * (t_annualInterest / 100) / M_MONTHS_IN_YEAR;
		m_yearEndInterest = m_compoundInterest * M_MONTHS_IN_YEAR;
		m_endOfYearBalance = static_cast<float>(m_yearEndInterest) + m_endOfYearBalance;

		cout << fixed << setprecision(2);
		cout << setw(10) << currentYear;
		cout << setw(25) << "$" << m_endOfYearBalance << setw(25) << "$" << m_yearEndInterest << endl;
	}
}
// Function calculates te year end balance with a continous/unchanged monthly deposits. Uses input for DataInput class
// currently output incorrect values 
//                                                    FIXME
//
/**
 * Calculates and returns an end of year balance for a given number of years
 *
 * @param initialInvestment dollar amount of initial investment
 * @param monthlyDeposit dollar amount added into the investment each month
 * @param interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param numberOfYears number of years to calculate balance for
 *
 */
	void InterestCalculations::balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposits, double t_annualInterest, int t_numOfYears) {
		//print table for values

		const int M_MONTHS_IN_YEAR = 12;
		double m_compoundInterest;
		double m_yearEndInterest;
		double m_endOfYearBalance = t_initialInvestment;
		

		// sets chart for inputs
		cout << endl << endl;
		cout << setw(70) << setfill('=') << endl;
		cout << setw(70) << left << setfill(' ') << "    Balance and Interest With An Additional Monthly Deposits  " << endl;
		cout << string(70, '=') << endl;
		//cout << setw(70) << setfill('=') << "\n" << endl;

		cout << "     Year " << "                    Year End Balance" << setw(35) << right << "  Year End Earned Interest" << endl;
		
		
		m_yearEndInterest = 0;
		m_compoundInterest = 0;
		// loops through and calculates the value for each year
		for (int currentYear = 1; currentYear <= t_numOfYears; ++currentYear) {
			m_compoundInterest = (t_monthlyDeposits + m_endOfYearBalance) * ((t_annualInterest / 100) / M_MONTHS_IN_YEAR);
			m_yearEndInterest = (m_yearEndInterest + m_compoundInterest) * 12;
			//value check FIXME
			/*cout << "loop " << currentYear << " compund inter =" << m_compoundInterest << " yearEndInterest = " << m_yearEndInterest 
				<< " end of year " << m_endOfYearBalance<< endl;*/ 
			m_endOfYearBalance = m_endOfYearBalance + m_yearEndInterest + (t_monthlyDeposits * 12);

			cout << fixed << setprecision(2);
			cout << setw(10) << currentYear;
			cout << setw(25) << "$" << m_endOfYearBalance << setw(25) << "$" << m_yearEndInterest << endl;
		}
		
}