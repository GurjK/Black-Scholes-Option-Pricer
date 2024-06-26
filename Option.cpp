/*
This is a base options class which defines functions such as setters and getters as well the private member data and matrix/vector functions
GK.1.15.24

*/




#include "Option.h"
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::math;

void Option::init()
{

	// Default values
	r = 0.05;
	sig = 0.2;
	S = 100.0;
	K = 110.0;
	T = 0.5;

	b = r;			// Black and Scholes stock option model (1973)

	Type = "C";		// European Call Option (this is the default type)
}

// Default Construcotr that accepts the 
Option::Option() : r(.05), sig(.2), S(100.0), K(110.0), T(0.5), b(0.5), Type("C")
{


}

// Copy constructor
Option::Option(const Option& O) : r(O.r),sig(O.sig),K(O.K),T(O.T),b(O.b),S(O.S),Type(O.Type)
{ 


}
//intial constructor
Option::Option(const string& optionType)
{	// Create option type

	init();
	Type = optionType;
	if (Type == "c")
		Type = "C";
}
//destroyer
Option::~Option() 
{
	
}

// Setting the Time Function
void Option::Time(double newT)
{
	T = newT;
}

//Getting the Time to maturity
double Option::Time() const
{
	return T;
}

//Setting the Strike Function
void Option::Strike(double newK)
{
	K = newK;
}

//Getting the Strike to maturity
double Option::Strike() const
{
	return K;
}

//Setting the Volatility Function
void Option::Sigma(double newsig)
{
	sig = newsig;
}

//Getting the Volatility to maturity
double Option::Sigma() const
{
	return sig;
}

//Setting the Risk Free Rate Function
void Option::Rate(double newr)
{
	r = newr;
}

//Getting the Risk Free Rate to maturity
double Option::Rate() const
{
	return r;
}

//Setting the Stock Price Function
void Option::Stock_Price(double newS)
{
	S = newS;
}

//Getting the Stock Price to maturity
double Option::Stock_Price() const
{
	return S;
}


//Setting the Cost of Carry Function
void Option::Cost_Carry(double newb)
{
	b = newb;
}

//Getting the Cost of Carry to maturity
double Option::Cost_Carry() const
{
	return b;
}

//Setting the Option Type Function
void Option::Option_Type(string newType)
{
	Type = newType;
}

//Getting the Option Type to maturity
string Option::Option_Type() const
{
	return Type;
}

// Functions that calculate option price and sensitivities
double Option::Price() const
{

	return 1;
}

// Functions that calculate option price and sensitivities
double Option::Delta() const
{

	return 1;
}

// Functions that calculate option price and sensitivities
double Option::Gamma() const
{

	return 1;
}

// Functions that calculate option price and sensitivities
double Option::CallDelta() const
{

	return 1;
}

// Functions that calculate option price and sensitivities
double Option::PutDelta() const
{

	return 1;
}

// Kernel Functions (Haug)
double Option::CallPrice() const
{


	return 2;
}

double Option::PutPrice() const
{


	return 4;
}

//Assignment Operator
Option& Option::operator = (const Option& source)
{

	if (this == &source) return *this;

	r = source.r;
	sig = source.sig;
	K = source.K;
	T = source.T;
	b = source.b;
	S = source.S;
	Type = source.Type;

	return *this;
}


//options vector functions which accepts a vector and prints out the price
vector<double> Option::Option_Vector_Price(const vector<double>& t, const string& C_P)
{
	vector<double> t2;
	for (int i = 0; i < t.size(); i++)
	{
		if (C_P == "C")
		{
			S = t[i];
			double x = CallPrice();
			t2.push_back(x);
		}
		else
		{
			S = t[i];
			double x = PutPrice();
			t2.push_back(x);

		}


	}
	return t2;
}


//matrix function which accepts a matrix and prints out a vector/matrix of stock prices
vector<vector<double>> Option::Option_Matrix(const vector<vector<double>>& parameter_matrix, const string& C_P, const string& TR,const string& OptionType)
{
	vector<vector<double>> Result;
	vector<double> tmp;
	if (OptionType == "European") { //checking if european or american

		if (C_P == "C") //checking if call or put. if european call then this 
		{
			for (int i = 0; i < parameter_matrix.size(); i++)
			{
				double value;
				T = parameter_matrix[i][0];
				K = parameter_matrix[i][1];
				sig = parameter_matrix[i][2];
				r = parameter_matrix[i][3];
				S = parameter_matrix[i][4];
				b = parameter_matrix[i][5];
				if (TR == "Price") {
					value = CallPrice();
				}
				else if (TR == "Delta")
				{
					value = CallDelta();
				}
				else if (TR == "Gamma")
				{
					value = Gamma();
				}

				else
				{
					cout << "You have entered a type not supported for the last arguement, Please Enter either Price, Delta, Gamma" << endl; //can only accept price,delta,gamma for european options
					break;
				}
				tmp.push_back(value);

			}

		}
		else //if european put then this
		{
			for (int i = 0; i < parameter_matrix.size(); i++)
			{
				double value;
				T = parameter_matrix[i][0];
				K = parameter_matrix[i][1];
				sig = parameter_matrix[i][2];
				r = parameter_matrix[i][3];
				S = parameter_matrix[i][4];
				b = parameter_matrix[i][5];
				if (TR == "Price") {
					value = PutPrice();
				}
				else if (TR == "Delta")
				{
					value = PutDelta();
				}
				else if (TR == "Gamma")
				{
					value = Gamma();
				}

				else
				{
					cout << "You have entered a type not supported for the second to last arguement, Please Enter either Price, Delta, Gamma" << endl; //can only accept price,delta,gamma for european options
					break;
				}
				tmp.push_back(value);

			}

		}
	}
	else if (OptionType == "American")
	{
		if (C_P == "C") //if american call then this
		{
			for (int i = 0; i < parameter_matrix.size(); i++)
			{
				double value;
				K = parameter_matrix[i][0];
				sig = parameter_matrix[i][1];
				r = parameter_matrix[i][2];
				S = parameter_matrix[i][3];
				b = parameter_matrix[i][4];
				if (TR == "Price") {
					value = CallPrice();
				}
				else
				{
					cout << "You have entered a type not supported for the second to last arguement, Please Enter either Price if this is an American Option" << endl; //can only accept price for american options
					break;
				}
				tmp.push_back(value);

			}

		}
		else //if american put then this
		{
			for (int i = 0; i < parameter_matrix.size(); i++)
			{
				double value;
				K = parameter_matrix[i][0];
				sig = parameter_matrix[i][1];
				r = parameter_matrix[i][2];
				S = parameter_matrix[i][3];
				b = parameter_matrix[i][4];
				if (TR == "Price") {
					value = PutPrice();
				}
				else
				{
					cout << "You have entered a type not supported for the second to last arguement, Please Enter either Price if this is an American Option" << endl; //can only print price for american options
					break;
				}
				tmp.push_back(value);

			}
		}
	}

	else
	{
		cout << "You have entered a type not supported for the last arguement, Please Enter either American or European" << endl; //only supports american and european options
	}
		Result.push_back(tmp);
		return Result;

	}

//Function for printing the delta of an option
vector<double> Option::Option_Vector_Delta(const vector<double>& t, const string& C_P)
{
	vector<double> t2;
	for (int i = 0; i < t.size(); i++)
	{
		if (C_P == "C")
		{
			S = t[i];
			double x = CallDelta();
			t2.push_back(x);
		}
		else
		{
			S = t[i];
			double x = PutDelta();
			t2.push_back(x);

		}


	}
	return t2;
}