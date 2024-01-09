#ifndef FRUIT_H
#define FRUIT_H

#include "AgriculturalProduct.h"

class Fruit : public AgriculturalProduct { 
//fruit class include: everything that in agriculturalProduct class, amount of sugar

private:
	double _amountOfSugar;

public:
	Fruit(); 

	void setAmountOfSugar(); 
	double getAmountOfSugar()const { return this->_amountOfSugar; }


	virtual void printProduct()const; 
	virtual void writeToFile(ofstream& out)const;
	virtual double setPriceOfProduct(double num = 3.0) const; 

	virtual ~Fruit(); 
};
#endif