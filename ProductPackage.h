#ifndef PRODUCTPAKAGE_H
#define PRODUCTPAKAGE_H

#include "StoreDetails.h"


class ProductPackage : public StoreDetails { 
//productPackege Class include: everything that in BasicDetails class, numOfProducts,Names,numofcolors 

private:
	int _numOfProducts;

	double _numOfColors;
	string* _namesOfProducts;
public:

	ProductPackage(); 

	
	void setNumOfProducts();
	double getNumOfProducts()const { return this->_numOfProducts; }
	void setNamesOfProducts();
	void printNamesOfProducts() const;
	void writeNamesOfProducts(ofstream& out) const;
	void setNumOfColors();
	double getNumOfColors() const { return this->_numOfColors; }



	virtual double setPriceOfProduct(double num = 3.0) const; 
	virtual void printProduct()const; 
	virtual void writeToFile(ofstream& out) const;

	virtual ~ProductPackage(); 

	
};
#endif