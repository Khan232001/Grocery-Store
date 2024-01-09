#ifndef MILKPRODUCT_H
#define MILKPRODUCT_H
#include "StoreDetails.h"

class MilkProduct : public StoreDetails { 
//milkProduct Class include: name,numofColors,NumOfFat (defualt type = 2)

private:
	string _nameOfMilkProduct;
	double _numOfFat;

protected:
	int _typeOfMilkProduct;

public:

	MilkProduct(); 


	int getTypeOfMilkProduct()const { return this->_typeOfMilkProduct; } 
	void setNameOfMilkProduct();
	string getNameOfMilkProduct()const { return this->_nameOfMilkProduct; }


	void setNumOfFat();
	double getNumOfFat() const { return this->_numOfFat; }


	
	virtual void printProduct()const; 
	virtual void writeToFile(ofstream& out)const;

	virtual double setPriceOfProduct(double num = 3.0) const; 


	virtual ~MilkProduct(); 
};
#endif

