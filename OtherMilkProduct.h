#ifndef OTHERMILKPRODUCT_H
#define OTHERMILKPRODUCT_H
#include"MilkProduct.h"


class OtherMilkProduct : public MilkProduct { 
//other milk product Include: every thing that in MilkProduct class,numOfParve and the Names of num of parve 
private:
	int _numOfParve;
	string* _namesOfParveComponents;

public:

	OtherMilkProduct(); 

	void setNumOfParve(); 
	int getNumOfParve() const { return this->_numOfParve; }
	void setNamesOfParveComponents();
	void printNamesOfParveComponents() const;
	void writeNamesOfParveComponents(ofstream& out)const;

	
	virtual double setPriceOfProduct(double num = 3.0) const; 
	virtual void printProduct()const; 
	virtual void writeToFile(ofstream& out) const;

	virtual ~OtherMilkProduct(); 

};
#endif

