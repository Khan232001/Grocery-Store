#ifndef STOREDETAILS_H
#define STOREDETAILS_H


#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;


class StoreDetails { //BasicDetails "The product" class include: serial,row,area,quantity,type and price

private:
	int _serialNumber;
	char _rowOfPlaceProduct;
	int _ShelfOfProduct;
	double _quantityOfProduct;
	int _areaOfProductInTheStore;


protected:
	int _typeOfProduct;

public:

	StoreDetails(); 

	void setSerialNumber(); 
	int getSerialNumber()const { return this->_serialNumber; }
	void setRowOfPlaceProduct();
	char getRowOfPlaceProduct()const { return this->_rowOfPlaceProduct; }
	void setShelfOfProduct();
	int getShelfOfProduct()const { return this->_ShelfOfProduct; }
	void setQuantity();
	double getQuantity() const { return this->_quantityOfProduct; }
	int getTypeOfProduct()const { return this->_typeOfProduct; }
	void setTypeOfProduct();
	void setAreaOfProductInTheStore();
	int getAreaOfProductInTheStore() const { return this->_areaOfProductInTheStore; }

	void changeQuantity(); 

	
	virtual double setPriceOfProduct(double num = 3.0) const; 
	virtual void printProduct()const; 

	virtual void writeToFile(ofstream& out) const;
	virtual ~StoreDetails(); 

};
#endif 
