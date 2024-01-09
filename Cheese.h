#ifndef CHEESE_H
#define CHEESE_H
#include "MilkProduct.h"
#include <iostream>

class Cheese :public MilkProduct { 
//cheese Class  include: Everything that in MilkProduct class,num of extra cheese

private:
	int _numOfExtraCheese;
public:

	Cheese();

	void setNumOfExtraCheese(); 
	int getNumOfExtraCheese()const { return this->_numOfExtraCheese; }

	virtual void printProduct()const; 
	virtual void writeToFile(ofstream& out)const;

	virtual double setPriceOfProduct(double num = 3.0) const; 

	virtual ~Cheese(); 


};
#endif


