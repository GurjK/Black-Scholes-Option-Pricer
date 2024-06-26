#pragma once
/*
This is a class for definining a an American option which is derived from the base class
GK.1.15.24
*/
#ifndef American_Option_H
#define American_Option_H

#include <iostream>
#include <string>
#include <vector>
#include "Option.h"
using namespace std;



class American_Option : public Option
{
private:

	double y1() const; //y1 value which is needed to price american call options
	double y2() const; //y2 valye which is needed to price american put options



	// These are internal functions that do not need to be public
	double CallPrice() const;
	double PutPrice() const;

public:

	//Constructors
	American_Option();//Constructor
	virtual ~American_Option();//Destructor
	American_Option(const string& optionType);//Initalizer
	American_Option(const American_Option& AO);//Copy Constructor

	//Accessing Functions 
	American_Option& operator=(const American_Option& AO); //assignment operator



	//Modifiers
	// Functions that calculate option price and sensitivities
	double Price() const;


};


#endif // !European_Option_H