#ifndef YOGURT_H
#define YOGURT_H
#include "MilkProduct.h"


#include "MilkProduct.h"
class Yogurt : public MilkProduct {

public:

	Yogurt(); 

	
	virtual void printProduct() const; 
	virtual void writeToFile(ofstream& out) const;
	virtual double setPriceOfProduct(double num = 3.0) const; 


	virtual ~Yogurt(); 
};
#endif

