// include libraries
#include <iostream>
#include "DataInput.h"
#include <stdexcept>

using namespace std;
 
//default constructor
DataInput::DataInput() {
	m_annualInterest = 0;
	m_initialInvestment = 0;
	m_monthlyDeposits = 0;
	m_years = 0;
	
} // accessors and mutators
const double DataInput::getInitialnvestment() {
	return m_initialInvestment;
}
void DataInput::setInitialInvestment(double t_initialInvestment) {
	t_initialInvestment = m_initialInvestment;
}
const double DataInput::getMonthlyDeposits() {
	return m_monthlyDeposits;

}
void DataInput::setMonthlyDeposits(double t_monthlyDeposits) {
	m_monthlyDeposits = t_monthlyDeposits;
}
const double DataInput::getAnnualInterest() {
	return m_annualInterest;
}
void DataInput::setAnnualInterest(double t_annualInterest) {
	t_annualInterest = m_annualInterest;
}
const double DataInput::getYears() {
	return m_years;
}
void DataInput::setYears(double t_years) {
	t_years = m_years;
}

 void DataInput::dataInputMenu(double &t_initialInvestment, double &t_monthlyDeposit, double &t_annualInterest, int &t_years) {
	
	
	
	// prints menu for preview of inputs
	cout << string(34, '*') << endl;
	cout << string(9, '*') << " MY DATA INPUT " << string(9, '*') << endl;

	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
	cin.clear();

	
	
	if (continueButton()) // checks for it user continues 
	{
		system("cls"); // clear screen
	}
	
	// print menu and accept user input 
		cout << string(34, '*') << endl;
		cout << string(9, '*') << " MY DATA INPUT " << string(9, '*') << endl;
		try {
			cout << "Initial Investment Amount: $";
			cin >> t_initialInvestment;
			if (t_initialInvestment < 0) {
				throw runtime_error("Invalid investment amount.");
			}

			cout << "Monthly Deposit: $";
			cin >> t_monthlyDeposit;
			if (t_monthlyDeposit < 0) {
				throw runtime_error("Invalid deposit value.");
			}

			cout << "Annual Interest: %";
			cin >> t_annualInterest;
			if (t_annualInterest < 0) {
				throw runtime_error("Invalid interest value.");
			}

			cout << "Number of years: ";
			cin >> t_years;
			if (t_years < 0) {
				throw runtime_error("Invalid number of years.");
			}
		}
			catch (runtime_error& excpt) {
				// Prints the error message passed by throw statement
				cout << excpt.what() << endl;
				cout << "Cannot compute." << endl;
			}
		

		cin.clear();

	continueButton();
	cout << string(34, '*') << endl;
	cout << string(34, '*') << endl;

	
		setInitialInvestment(t_initialInvestment);
		setMonthlyDeposits(t_monthlyDeposit);
		setAnnualInterest(t_annualInterest);
		setYears(t_years);

	




	

	
}
 // bool function for continue option
 bool DataInput::continueButton() {
	 char m_key;
	 bool m_continueKey;
	 cout << "*****Press 'c' to continue*****" << endl;
	 cin >> m_key;
	 
	 if (m_key == 'c' || m_key == 'C') {
		 m_continueKey = true;
	 }
	 else {
		 m_continueKey = false;
	 }
	 return m_continueKey;
 }


