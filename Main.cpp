/*
Main function which tests the functionality of an american, european, and option class for Group A+B

*/


#include "European_Option.h"
#include "Option.h"
#include "Helper_Functions.h"
#include "American_Option.h"
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include <iostream>

using namespace std;




int main()
{
	

	//Batch 1 Testing 
	cout << endl << "Group a Testing European" << endl;

	European_Option BatchOption1;
	//Setting the parameters for batch 1
	BatchOption1.Time(1.45); 
	BatchOption1.Strike(120.0);
	BatchOption1.Sigma(.51);
	BatchOption1.Rate(0.045);
	BatchOption1.Stock_Price(108.0);
	BatchOption1.Cost_Carry(0);
	
	//Calculating the call price for bathc1
	//BatchOption1.Option_Type("C");
	//cout << "Call Option on a stock: " << BatchOption1.Price() << endl;
	BatchOption1.Option_Type("P");
	cout << "Put Option on a stock: " << BatchOption1.Price() << endl;
	cout << BatchOption1.Delta() << endl; //checking for right result
	cout << BatchOption1.Gamma() << endl; //checking for right result


/*
	//Calculating the put price for batch 1
	BatchOption1.Option_Type("P");
	cout << "Put Option on a stock: " << BatchOption1.Price() << endl;
	cout << "Put Call Parity Test " << BatchOption1.Put_Call_Parity() << endl; //Testing put call parity
	
	
	//Testing the Put call Parity Bool Test
	double t4 = 34;
	cout << BatchOption1.Put_Call_Parity(3.0) << endl; //0
	cout << BatchOption1.Put_Call_Parity(BatchOption1.Put_Call_Parity()) << endl; //1
	
	
	//Batch 2 Testing

	//seting parameters for batch2
	European_Option BatchOption2;
	BatchOption2.Time(1.0);
	BatchOption2.Strike(100.0);
	BatchOption2.Sigma(.20);
	BatchOption2.Rate(0.0);
	BatchOption2.Stock_Price(100.0);
	BatchOption2.Cost_Carry(BatchOption2.Rate());

	BatchOption2.Option_Type("C");
	cout << "Call Option on a stock: " << BatchOption2.Price() << endl; //printing call price for batch 2

	BatchOption2.Option_Type("P");
	cout << "Put Option on a stock: " << BatchOption2.Price() << endl; //pritning put price for batch 2

	//Batch 3 Testing
	//setting paramters for batch3
	European_Option BatchOption3;
	BatchOption3.Time(1.0);
	BatchOption3.Strike(10.0);
	BatchOption3.Sigma(.50);
	BatchOption3.Rate(0.12);
	BatchOption3.Stock_Price(5.0);
	BatchOption3.Cost_Carry(BatchOption3.Rate());

	BatchOption3.Option_Type("C");
	cout << "Call Option on a stock: " << BatchOption3.Price() << endl;  //printing call price for batch 3

	BatchOption3.Option_Type("P");
	cout << "Put Option on a stock: " << BatchOption3.Price() << endl; // pritning put price for batch 3

	//Batch 4 Testing

	//setting parameters for batch 4
	European_Option BatchOption4;
	BatchOption4.Time(30.0);
	BatchOption4.Strike(100.0);
	BatchOption4.Sigma(.30);
	BatchOption4.Rate(0.08);
	BatchOption4.Stock_Price(100.0);
	BatchOption4.Cost_Carry(BatchOption4.Rate());

	BatchOption4.Option_Type("C");
	cout << "Call Option on a stock: " << BatchOption4.Price() << endl;  //printing call price for batch 4

	BatchOption4.Option_Type("P");
	cout << "Put Option on a stock: " << BatchOption4.Price() << endl;  // pritning put price for batch 4
	
	
	
	//Part B Testing

	cout << endl << "Group b Testing European" << endl;

	//testing the put call parity functions
	cout << BatchOption1.Put_Call_Parity(3.0) << endl; //0
	cout << BatchOption1.Put_Call_Parity(BatchOption1.Put_Call_Parity()) << endl; //1


	//PART C TESTING
	cout << endl << "Group c Testing European" << endl;

	vector<double> Vector_1=Option_Parameter_Vector(5,3,60); //testing the vector helper function
	vector<double> Stock_Prices_Test = BatchOption1.Option_Vector_Price(Vector_1,"P"); //testing the vector prices function

	Print_Vector(Stock_Prices_Test); //pritning result
	

	
	//Part D Testing
	cout << endl << "Group d Testing European" << endl;
	//creating vector parameters
	vector<double> Time_Parameters = Option_Parameter_Vector(.25, 3, .25);
	vector<double> Strike_Parameters = Option_Parameter_Vector(0, 3, 100);
	vector<double> Sig_Parameters = Option_Parameter_Vector(.1, 3, .2);
	vector<double> Rate_Parameters = Option_Parameter_Vector(.03, 3, .02);
	vector<double> Stock_Parameters = Option_Parameter_Vector(5, 3, 75);
	vector<double> Carry_Parameters = Option_Parameter_Vector(.03, 3, .02);



	vector<vector<double>> Stock_Parameters_Matrix_Test1 = Option_Matrix_Parameters(Time_Parameters, Strike_Parameters, Sig_Parameters, Rate_Parameters, Stock_Parameters, Carry_Parameters); //testing helper matrix function
	Print_Vector(Time_Parameters); //checking the results
	Print_Matrix(Stock_Parameters_Matrix_Test1); //checking the results
	
	European_Option e1;
	vector<vector<double>> resutls= e1.Option_Matrix(Stock_Parameters_Matrix_Test1, "P","Price","American"); //testing the pricing function for a matrix in the option base class
	Print_Matrix(resutls);
	
	//////////////////////////////////////////////////////
	

	//Greeks a Testing
	cout << endl << "Group a Testing Greeks" << endl;

	//setting parameters
	European_Option Gamma_Option_test;
	Gamma_Option_test.Time(0.5);
	Gamma_Option_test.Strike(100.0);
	Gamma_Option_test.Sigma(.36);
	Gamma_Option_test.Rate(0.1);
	Gamma_Option_test.Stock_Price(105.0);
	Gamma_Option_test.Cost_Carry(0.0);

	Gamma_Option_test.Option_Type("C");
	cout << Gamma_Option_test.Delta() << endl; //checking for right result

	Gamma_Option_test.Option_Type("P");
	cout << Gamma_Option_test.Delta() << endl;  //checking for right result


	//Greeks B Testing
	cout << endl << "Group b Testing Greeks" << endl;

	vector<double> Vector2 = Option_Parameter_Vector(5, 3, 60);
	vector<double> Stock_Delta_Test = BatchOption1.Option_Vector_Delta(Vector2, "P"); //checking vector function that shows delta in option base class

	Print_Vector(Stock_Delta_Test); //chekcking the result
	
	
	//Greeks C Testing
	cout << endl << "Group c Testing Greeks" << endl;
	//setting vector paramters
	vector<double> Time_Parameters2 = Option_Parameter_Vector(.25, 3, .25);
	vector<double> Strike_Parameters2 = Option_Parameter_Vector(0, 3, 100);
	vector<double> Sig_Parameters2 = Option_Parameter_Vector(.1, 3, .2);
	vector<double> Rate_Parameters2 = Option_Parameter_Vector(.03, 3, .02);
	vector<double> Stock_Parameters2 = Option_Parameter_Vector(5, 3, 75);
	vector<double> Carry_Parameters2 = Option_Parameter_Vector(.03, 3, .02);



	vector<vector<double>> Stock_Parameters_Matrix_Test3 = Option_Matrix_Parameters(Time_Parameters2, Strike_Parameters2, Sig_Parameters2, Rate_Parameters2, Stock_Parameters2, Carry_Parameters2); //testing the function
	Print_Vector(Time_Parameters2); //checking results
	Print_Matrix(Stock_Parameters_Matrix_Test3); //checking results

	European_Option e3;

	vector<vector<double>> GammaTest = e3.Option_Matrix(Stock_Parameters_Matrix_Test3, "C", "Gamma","European"); //seeing if it works correctly
	Print_Matrix(GammaTest);
	vector<vector<double>> DeltaTest = e3.Option_Matrix(Stock_Parameters_Matrix_Test3, "C", "Delta","European"); //seeing if it works correctly
	Print_Matrix(DeltaTest);
	vector<vector<double>> RhoTest = e3.Option_Matrix(Stock_Parameters_Matrix_Test3, "C", "Rho","European"); //Not supported should get a cout
	Print_Matrix(RhoTest);
	e1.Stock_Price(); 

	//Greeks D Testing
	cout << endl << "Group d Testing Greeks" << endl;

	Gamma_Option_test.Option_Type("C");

	cout << Gamma_Option_test.Delta_Differences(.05) << endl; //checking delta differences for call
	cout << Gamma_Option_test.Delta() << endl;

	Gamma_Option_test.Option_Type("P");
	cout << Gamma_Option_test.Delta_Differences(.05) << endl; //checking delta differences for a put
	cout << Gamma_Option_test.Delta() << endl;


	cout << Gamma_Option_test.Gamma_Differences(.05) << endl; //checking gamma differences
	cout << Gamma_Option_test.Gamma() << endl;


	///////////////////////////////

		//Group B Test B
	cout << endl << "Group a+b Testing American" << endl;

	American_Option Test1;
	Test1.Strike(100.0);
	Test1.Sigma(.10);
	Test1.Rate(.1);
	Test1.Stock_Price(110.0);
	Test1.Cost_Carry(.02);
	Test1.Option_Type("C");
	cout << Test1.Price() << endl; //checking prices and class

	Test1.Option_Type("P");
	cout << Test1.Price() << endl; //checking price and class

	//Group B Test C
	cout << endl << "Group c Testing American" << endl;
	//setting parameters for vectors
	vector<double> Strike_Parameters1 = Option_Parameter_Vector(0, 3, 100.0);
	vector<double> Sig_Parameters1 = Option_Parameter_Vector(.1, 3, .10);
	vector<double> Rate_Parameters1 = Option_Parameter_Vector(.03, 3, .1);
	vector<double> Stock_Parameters1 = Option_Parameter_Vector(5, 3, 110.0);
	vector<double> Carry_Parameters1 = Option_Parameter_Vector(.03, 3, .02);

	vector<vector<double>> Stock_Parameters_Matrix_Test2 = Option_Matrix_Parameters(Strike_Parameters1, Sig_Parameters1, Rate_Parameters1, Stock_Parameters1, Carry_Parameters1); //checking to see if overloaded method works
	Print_Vector(Strike_Parameters1);
	Print_Matrix(Stock_Parameters_Matrix_Test2); //cehcking resylts

	//Group B Test D
	cout << endl << "Group d Testing American" << endl;

	American_Option A1;
	vector<vector<double>> Results1 = A1.Option_Matrix(Stock_Parameters_Matrix_Test2, "C", "Price", "American"); //shoudl work
	vector<vector<double>> Results2 = A1.Option_Matrix(Stock_Parameters_Matrix_Test2, "P", "Price", "American"); //should work
	vector<vector<double>> Results3 = A1.Option_Matrix(Stock_Parameters_Matrix_Test2, "P", "Gamma", "American"); //not possible since gamma isn't defined
	vector<vector<double>> Results4 = A1.Option_Matrix(Stock_Parameters_Matrix_Test2, "P", "Delta", "American"); //not possible since delta isn't defined


	Print_Matrix(Results1); //should print
	Print_Matrix(Results2); //should print

	//comparing results from function to ensure functionality

	American_Option Test2;
	Test2.Strike(100.0);
	Test2.Sigma(.2);
	Test2.Rate(.13);
	Test2.Stock_Price(115.0);
	Test2.Cost_Carry(.05);
	Test2.Option_Type("P");
	cout << Test2.Price() << endl;


	American_Option Test3;
	Test3.Strike(100.0);
	Test3.Sigma(.30);
	Test3.Rate(.16);
	Test3.Stock_Price(120.0);
	Test3.Cost_Carry(.08);
	Test3.Option_Type("P");
	cout << Test3.Price() << endl;
	*/
	return 0;
}