#ifndef VEGETABLE_H
#define VEGETABLE_H

#include "AgriculturalProduct.h"
#include <iostream>


class Vegetable : public AgriculturalProduct { 
//Vegtable Class include: everything that in Agricultural product,NumOfVitamins

private:
	int _numOfVitamins;

public:

	Vegetable(); 

	void setNumOfVitamins(); 
	int getNumOfVitamins()const { return this->_numOfVitamins; }

	
	virtual double setPriceOfProduct(double num = 3.0) const; 
	virtual void printProduct()const; 
	virtual void writeToFile(ofstream& out) const;

	virtual ~Vegetable(); 
};
#endif