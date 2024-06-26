
#pragma once
/*
This is a helper file which can be used to store global functions which are needed frequently throughout the project

*/
#ifndef Helper_Functions_H
#define Helper_Functions_H


#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

std::vector<double> Option_Parameter_Vector(const double& h, const int& size, const double& start_paramter)

{
	vector<double> v1;
	for (int i = 0; i < size; ++i)
	{
		v1.push_back(start_paramter + i * h);

	}


	return v1;
}

//Creating a matrix is mx6 from vector that were created using Option_Parameter_Vector function
std::vector < vector<double>> Option_Matrix_Parameters(const vector<double>& Time, const vector<double>& Strike, const vector<double>& Sig, const vector<double> r, const vector<double> S, const vector<double>& b)

{

	if ((Time.size() == Strike.size()) && (Strike.size() == Sig.size()) && (Sig.size() == r.size()) && (r.size() == S.size()) && (S.size() == b.size()))
	{
		vector<vector<double>> Stock_Parameters;
		for (int i = 0; i < Time.size(); i++)
		{
			vector<double>Temp;
			Temp.push_back(Time[i]);
			Temp.push_back(Strike[i]);
			Temp.push_back(Sig[i]);
			Temp.push_back(r[i]);
			Temp.push_back(S[i]);
			Temp.push_back(b[i]);

			Stock_Parameters.push_back(Temp);
		}
		return Stock_Parameters;
	}
	else
	{
		cout << "Matrix parameter vectors are not the same size. Please make sure they are equal" << endl;

	}

}

std::vector < vector<double>> Option_Matrix_Parameters(const vector<double>& Strike, const vector<double>& Sig, const vector<double> r, const vector<double> S, const vector<double>& b)

{

	if ((Strike.size() == Sig.size()) && (Sig.size() == r.size()) && (r.size() == S.size()) && (S.size() == b.size()))
	{
		vector<vector<double>> Stock_Parameters;
		for (int i = 0; i < Strike.size(); i++)
		{
			vector<double>Temp;
			Temp.push_back(Strike[i]);
			Temp.push_back(Sig[i]);
			Temp.push_back(r[i]);
			Temp.push_back(S[i]);
			Temp.push_back(b[i]);

			Stock_Parameters.push_back(Temp);
		}
		return Stock_Parameters;
	}
	else
	{
		cout << "This should be used for American Options.Matrix parameter vectors are not the same size. Please make sure they are equal" << endl;

	}

}


void Print_Vector(const vector<double>& V)
{
	for (int i = 0; i < V.size(); ++i)
	{
		cout << V[i] << " ";
	}
	cout << endl;
}


void Print_Matrix(const vector<vector<double>>& M)
{
	for (int i = 0; i < M.size(); i++)
	{
		for (int j = 0; j < M[i].size(); j++)
		{
			cout << M[i][j] << " ";
		}

		cout << endl;
	}
	cout << endl;
}


#endif