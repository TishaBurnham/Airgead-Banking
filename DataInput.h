#ifndef AIRGEAD_DATAINPUT_H
#define AIRGEAD_DATAINPUT_H

using namespace std;

// class for user input
// set private and public variables
class DataInput {
private:
	double m_initialInvestment=0;
	double m_monthlyDeposits=0;
	double m_annualInterest=0;
	double m_years=0;
	
	
public:
	DataInput();
	const double getInitialnvestment();
	const double getMonthlyDeposits();
	const double getAnnualInterest();
	const double getYears();
	void setInitialInvestment(double t_initialInvestment);
	void setMonthlyDeposits(double t_monthlyDeposits);
	void setAnnualInterest(double t_annualInterest);
	void setYears(double t_years);
	void dataInputMenu(double& t_initialInvestment, double& t_monthlyDeposit, double& t_annualInterest, int& t_years);
	bool continueButton();
};
#endif //AIRGEAD_DATAINPUT_H

