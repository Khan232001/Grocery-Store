#ifndef AGRICULTURALPRODUCT_H
#define AGRICULTURALPRODUCT_H
#include "StoreDetails.h"
class AgriculturalProduct : public StoreDetails { 
//AgriculturalProduct  class include: Name,Num of Seasons and name of suppliers 

private:
	string _nameOfAgriculturalProduct;
	int _numOfYearSeasons;
	int _numOfSuppliers;

protected:
	int _typeOfAgriculturalProduct; //two types : Fruit and Vegtable

public:
	AgriculturalProduct(); 

	void setTypeOfAgriculturalProduct(int num); 
	int getTypeOfAgriculturalProduct() const { return this->_typeOfAgriculturalProduct; }
	void setNameOfAgriculturalProduct();
	string getNameOfAgriculturalProduct() const { return this->_nameOfAgriculturalProduct; }
	void setNumOfSuppliers();
	int getNumOfSuppliers() const { return this->_numOfSuppliers; }
	virtual double setPriceOfProduct(double num = 3.0) const; 
	void setNumOfYearSeasons();
	int getNumOfYearSeasons() const { return this->_numOfYearSeasons; }


	virtual void printProduct()const; 
	virtual void writeToFile(ofstream& out)const;

	virtual ~AgriculturalProduct(); 
};
#endif 