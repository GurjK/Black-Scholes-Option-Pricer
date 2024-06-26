/*
This is an american option derived class that is derived from the base option class. Used to price american perpeutal options
GK.1.15.24

*/

#include "American_Option.h"
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
using namespace boost::math;





// Default Construcotr that accepts the 
American_Option::American_Option() : Option()
{


}

American_Option::American_Option(const American_Option& EO) : Option(EO)
{ // Copy constructor

}

//
American_Option::American_Option(const string& optionType) : Option(optionType)
{	// Create option type


}

//Destructor
American_Option::~American_Option()
{

}

//Assignment Operator
American_Option& American_Option::operator = (const American_Option& AO)
{

	if (this == &AO) return *this;

	r = AO.r;
	sig = AO.sig;
	K = AO.K;
	T = AO.T;
	b = AO.b;
	S = AO.S;
	Type = AO.Type;

	return *this;
}
//Defining the constant y1 which is used for the calculation of the call american options
double American_Option::y1() const 
{
	double t1 = b / (sig * sig);
	double t2 = .5 - t1;
	double t3 = pow((t1 - .5), 2);
	double t4 = (2 * r) / (sig * sig);
	double t5 = sqrt(t3 + t4);

	return t2 + t5;
}
//Defining the constant y2 which is used for the calculation of the call american options

double American_Option::y2() const
{
	double t1 = b / (sig * sig);
	double t2 = .5 - t1;
	double t3 = pow((t1 - .5), 2);
	double t4 = (2 * r) / (sig * sig);
	double t5 = sqrt(t3 + t4);

	return t2 - t5;
}
//Defining call price 
double American_Option::CallPrice() const
{
	return (K / (y1() - 1)) * (pow((((y1() - 1) / y1()) * (S / K)), y1()));
}
//Defining put price 

double American_Option::PutPrice() const
{
	return (K / (1 - y2())) * (pow((((y2() - 1) / y2()) * (S / K)), y2())) ;
}

// price function that uses callprice and putprice
double American_Option::Price() const
{


	if (Type == "C")
	{
		cout << "calling call\n";
		return CallPrice();
	}
	else
	{
		cout << "calling put\n";
		return PutPrice();
	}
}