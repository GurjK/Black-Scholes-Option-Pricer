#pragma once
/*
This is a class for definining a European Option with Greeks included

*/
#ifndef European_Option_H
#define European_Option_H

#include <iostream>
#include <string>
#include <vector>
#include "Option.h"
using namespace std;



class European_Option: public Option
{
private:


	//Member data functions that are used to calculate the price are private
	double n(double x) const; //n which is the pdf
	double N(double x) const; //N which is the cdf


	// These are internal functions that do not need to be public
	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;

public:

//Constructors
	European_Option();//Constructor
	virtual ~European_Option();//Destructor
	European_Option(const string& optionType);//Initalizer
	European_Option(const European_Option& EO);//Copy Constructor

//Accessing Functions 
	 European_Option& operator=(const European_Option& EO); //assigment operator
	 


//Modifiers


	 // Functions that calculate option price and sensitivities
	 double Price() const;
	 double Delta() const;
	 double Gamma() const;

	 double Delta_Differences(double h) ; //difference delta function that inputs a small h
	 double Gamma_Differences(double h) ; //difference gamma function that inputs a small h

	 //Put Call Paraity Functions
	 double Put_Call_Parity() const; //returns opposite value that satisfies put call parity
	 bool Put_Call_Parity(const double& Price) const; //accepts a valye which checking if put call parity is satisfied

	 


};


#endif // !European_Option_H

