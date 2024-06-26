#pragma once
/*
This is a base options class that is used to define the basic option. It is abstract and cannot be used as an object. The purpose is to define common functions that are needed for every option

GK 1.15.24
*/
#ifndef Option_H
#define Option_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Option {
protected:
	double T; //Time to Expiry in years
	double K; //Strike Price
	double sig; //Volatility
	double r; //Risk free interest rate
	double S; //Stock Price
	double b;		// Cost of carry
	string Type; //Type of Option

	// These are internal functions that do not need to be public
	virtual double CallPrice() const;
	virtual double PutPrice() const;
	virtual double CallDelta() const;
	virtual double PutDelta() const;

	void init();	// Initialise all default values
public:
	//Constructors

	Option();//Constructor
	virtual ~Option();//Destructor
	Option(const string& optionType);//Initalizer
	Option(const Option& O);//Copy Constructor


	// Setters
	void Time(double newT); 
	void Strike(double newK);
	void Sigma(double newsig);
	void Rate(double newr);
	void Stock_Price(double newS);
	void Cost_Carry(double newb);
	void Option_Type(string newType);

	// getters
	double Time() const;
	double Strike() const;
	double Sigma() const;
	double Rate() const;
	double Stock_Price() const;
	double Cost_Carry() const;
	string Option_Type() const;



	// Functions that calculate option price and sensitivities
	virtual double Price() const; 
	virtual double Delta() const;
	virtual double Gamma() const;

	Option& operator = (const Option& source); //assignment operator

	vector<double> Option_Vector_Price(const vector<double>& t, const string& C_P); //Returns a vector of stock prices by entering the stock price and call/put type
	vector<vector<double>> Option_Matrix(const vector<vector<double>>& parameter_matrix, const string& C_P, const string& TR, const string& OptionType); //Input a matrix of parameters and return a matrix of prices( i.e stock prices of m*1)
	vector<double> Option_Vector_Delta(const vector<double>& t, const string& C_P); //Returns a vector of stock prices by entering the stock price and call/put type
};	

#endif