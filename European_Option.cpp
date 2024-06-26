/*
This is a derived European Option class that is used to price european options
GK.1.15.24
*/

#include "European_Option.h"
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::math;







// Default Construcotr that accepts the 
European_Option::European_Option() : Option() //just call the base option calss
{ 


}

European_Option::European_Option(const European_Option& EO): Option(EO)  //just call the base option calss
{ // Copy constructor

}

//
European_Option::European_Option(const string& optionType): Option(optionType)  //just call the base option calss
{	// Create option type


}

//Destructor
European_Option::~European_Option()  //just call the base option calss
{

}

//Assignment Operator
European_Option& European_Option::operator = (const European_Option& EO)
{

	if (this == &EO) return *this;

	r = EO.r;
	sig = EO.sig;
	K = EO.K;
	T = EO.T;
	b = EO.b;
	S = EO.S;
	Type = EO.Type;

	return *this;
}

//Calculating N
double European_Option::N(double x) const
{
	normal_distribution<> myNormal(0.0, 1.0);
		return cdf(myNormal, x);
}

//Calculation n
double European_Option::n(double x) const
{
	normal_distribution<> myNormal(0.0, 1.0);
	return pdf(myNormal, x);
}


// Kernel Functions (Haug)
//call price
double European_Option::CallPrice() const
{

	double tmp = sig * sqrt(T);

	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;
	return (S * exp((b - r) * T) * N(d1)) - (K * exp(-r * T) * N(d2));

}
//put price
double European_Option::PutPrice() const
{

	double tmp = sig * sqrt(T);
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;

	return (K * exp(-r * T) * N(-d2)) - (S * exp((b - r) * T) * N(-d1));

}
//call delta
double European_Option::CallDelta() const
{
	double tmp = sig * sqrt(T);

	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;


	return exp((b - r) * T) * N(d1);
}
//put delta
double European_Option::PutDelta() const
{
	double tmp = sig * sqrt(T);

	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;

	return exp((b - r) * T) * (N(d1) - 1.0);

}


// Functions that calculate option price and sensitivities
//using previously callprice and putprice function to create a price function
double European_Option::Price() const
{


	if (Type == "C")
	{
		
		return CallPrice();
	}
	else
	{
		
		return PutPrice();
	}
}

//Calculating the Delta of an Option
//using previously calldelta and putdelta function to create a price function

double European_Option::Delta() const
{
	if (Type == "C")
		return CallDelta();
	else
		return PutDelta();

}
//gamma is second derivate so only need one function
double European_Option::Gamma() const
{
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / (sig * sqrt(T));
	return (n(d1) * exp((b - r) * T)) / (S * sig * sqrt(T));
}

//Put Call Parity function that calculates the opposite
double European_Option::Put_Call_Parity() const
{
	if (Type == "C")
		return CallPrice() + (K * exp(-r * T)) - S;
	else
		return PutPrice() + S - (K * exp(-r * T));
}

//Boolean Test for Put and Call Parity
bool European_Option::Put_Call_Parity(const double& Price) const
{
	if (Type == "C")
		return bool(CallPrice() + (K * exp(-r * T)) == Price + S);
	else
		return bool(Price + (K * exp(-r * T)) == PutPrice() + S);
}

//creating a delta differences function to check values
double European_Option::Delta_Differences(double h) 
{
	European_Option EO1 = *this;
	European_Option EO2 = *this;

	EO1.Stock_Price(S + h);
	EO2.Stock_Price(S - h);
	return (EO1.Price() - EO2.Price()) / (2 * h);

}
//creating a gamma differences function to check valyes of h
double European_Option::Gamma_Differences(double h)
{
	European_Option EO1 = *this;
	European_Option EO2 = *this;

	EO1.Stock_Price(S + h);
	EO2.Stock_Price(S - h);
	return ((EO1.Price()-2*this->Price()+EO2.Price())/(h*h));



}




	


