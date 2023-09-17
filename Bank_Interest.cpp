/*
Programmer’s name : N/A

Programmer : N/A

Date : 9 / 12 / 2023

Version : 1.6

This is a program that asks for the beginning balance and the number of checks written. Then computes and displays youre balence after serveise fees. 
- Has logic and error handleing for miss imputs and incorrect negtive numbers.
- Is able to tell you if you are going to be overdrafted by service fees
- Uses 'for' and 'while' loops for prossing/converting numbers and is able to be used more then once if user inputs to do so.  
*/


#include <iostream>

using namespace std;

int main()
{
	//declarations
	int ChecksWritten, CliantDollar,CliantCents, CliantDollarsAfterFees = 0, CliantCentsAfterFees = 0, CheckFees = 0;
	bool CoolLoop = true;
	char LoopDecider;

	//i like my loops
	for (CoolLoop = true; CoolLoop;) {

		//greeting
		string Greeting1 = "Please enter the amount in dollars first then hit enter. \n(e.g. 12345 or -12345)";
		string Greeting2 = "Now input any cents you have \n(e.g. 00 to 99)";
		string Greeting3 = "Now enter the number of checks you have written so far.\n(e.g. 123)";

		cout << Greeting1 << "\n-->";
		cin >> CliantDollar;

		cout << Greeting2 << "\n-->";
		cin >> CliantCents;

		//Checks for proper syntax
		if (CliantDollar > 0 && CliantCents < 0) {
			cout << "ERROR, Invalid cents entered \nPlease try again. ";
			continue; //loop restart i rememebred about
		}
		else if (CliantCents <=-100 || CliantCents >= 100) {//if cents are are over thresshold
			cout << "ERROR,Cents should be between -99 and 99. \nPlease try again. ";
			continue; //loop restart i rememebred about
		}
		else if (CliantDollar <= -1 && CliantCents >= 1) {
			CliantCents = -CliantCents;
		}

		cout << Greeting3 << "\n-->";
		cin >> ChecksWritten;

		//syntax check 2
		if (ChecksWritten < 0) {//if a negative number was entered
			cout << "ERROR, Invalid number if checks written. \nPlease try again. ";
			continue; //loop restart i rememebred about
		}

		//under thresshoold? + monthly fee
		if (CliantDollar >= 400) {
			CliantDollarsAfterFees = CliantDollar - 10;
		}
		else {
			CliantDollarsAfterFees = CliantDollar - 25;
		}

		//written check math. I know there is a better way to do this but i cant think of it at this moment
		if (ChecksWritten < 20) {//if under 20 checks
			CheckFees = ChecksWritten * 10;
		}
		else if (ChecksWritten >= 20 && ChecksWritten <= 39) {//if between 20-39 checks
			CheckFees = ChecksWritten * 8;
		}
		else if (ChecksWritten >= 40 && ChecksWritten <= 59) {//if between  40-59 checks
			CheckFees = ChecksWritten * 6;
		}
		else if (ChecksWritten >= 60) {//if grater then 60 checks
			CheckFees = ChecksWritten * 4;
		}

		//calculating the difference
		CliantCentsAfterFees -= CheckFees;

		//convert cents to dollars if cents are 100 or more
		while (CliantCentsAfterFees >= 100) {
			CliantDollarsAfterFees++;
			CliantCentsAfterFees -= 100;
		}

		//convert dollars to cents if cents are negative
		while (CliantCentsAfterFees < 0) {
			CliantDollarsAfterFees--;
			CliantCentsAfterFees += 100;
		}

		//is over drafted?
		if (CliantDollar < 0) {//over by dollars
			string OverdraftWarning = "WARNING! This account is currently over drafted by: ";
			string FeeWarning = "After fees your current balance will be: ";
			cout << OverdraftWarning << CliantDollar <<'.'<< CliantCents << endl;
			cout << FeeWarning << CliantDollarsAfterFees << '.' << CliantCentsAfterFees << endl;
		}
		else if (CliantCents < 0) {//over by cents
			string OverdraftWarning = "WARNING! This account is currently over drafted by: ";
			string FeeWarning = "After fees your current balance will be: ";
			cout << OverdraftWarning << CliantDollar << '.' << CliantCents << endl;
			cout << FeeWarning << CliantDollarsAfterFees << '.' << CliantCentsAfterFees << endl;
		}
		//overdrafted by fees
		else if (CliantDollarsAfterFees < 0) {//over by dollars from fees
			cout << "WARNING! This account is at risk of being overdrafted" << endl;
			string FeeWarning = "After fees your current balance will be: ";
			cout << FeeWarning << CliantDollarsAfterFees << '.' << CliantCentsAfterFees << endl;
		}
		else if (CliantCentsAfterFees < 0) {//over by cents from fees
			cout << "WARNING! This account is at risk of being overdrafted" << endl;
			string FeeWarning = "After fees your current balance will be: ";
			cout << FeeWarning << CliantDollarsAfterFees << '.' << CliantCentsAfterFees << endl;
		}
		else {
			cout << "After fees your account balance will be: " << CliantDollarsAfterFees << '.' << CliantCentsAfterFees << endl;
		}

		// loop check
		cout << "Would you like to check another bank account of ours? \n(e.g. y/n)\n-->";
		cin >> LoopDecider;
		if (LoopDecider == 'Y' || LoopDecider == 'y') {
			CoolLoop = true;
			cout << "Welcome back! ";
		}
		else {
			CoolLoop = false;
		}
	}
	return 0;
}