#ifndef THEGROCERYSTORE_H
#define THEGROCERYSTORE_H
#include<vector>
#include "Cheese.h"
#include "Yogurt.h"
#include "Vegetable.h"
#include "Fruit.h"
#include "OtherMilkProduct.h"
#include "ProductPackage.h"
#include"employee.h"



class TheGroceryStore { //the Shop Class Include: Manu,nameOfshop,factorOfshop,NumOFProducts

private:
	string nameOfStore;
	double factorOfStore;
	int numOfProductsInTheStore;
	StoreDetails** _arrOfProducts;
	vector<Employee>em;



public:
	TheGroceryStore(); //defualt C'tor


	void setNameOfStore(); 
	string getNameOfStore()const { return this->nameOfStore; }
	double getFactorOfStore() const { return this->factorOfStore; }
	int getNumOfProductsInTheStore()const { return this->numOfProductsInTheStore; }




	void menu(); 
	void printAllPrices() const; 
	void printDetailsOfStore() const; 
	void changeFactorOfStore();
	void addProductToarr(); 
	bool checkSerialNumber(int serial) const; 
	void calPriceOfAllProduct() const; 
	void addnewemployee();
	void searchemployee();
	void showallemployee();
	void saveAllProductsToFile()const;
	void writeEmployeesToFile() const;
	void saveAllPrices()const;
	void readEmployeesFromFile();
	~TheGroceryStore(); 
};
#endif