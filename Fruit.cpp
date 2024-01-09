#include "Fruit.h"


Fruit::Fruit() { 
	cout << "the  fruit product is on" << endl;
	this->_typeOfAgriculturalProduct = 2;
	this->setAmountOfSugar();
}

void Fruit::setAmountOfSugar() { 
	double num;
	int flag = 0;
	cout << "please select the amount of suger in the fruit - (per 100 gram)" << endl;

	do {
		flag = 0;
		cin >> num;
		if (cin.fail()) {
			flag = 1;
			cin.clear();
			cin.ignore();
			cout << "the num must be a positive number " << endl;
		}
		else if (num < NULL) {
			flag = 1;
			cout << "the num must be a positive number " << endl;
		}

		else {
			double amount = (num / 100);
			this->_amountOfSugar = amount;
		}
	} while (flag != 0);
}

double Fruit::setPriceOfProduct(double num) const { 
	return (AgriculturalProduct::setPriceOfProduct(num) + (this->getAmountOfSugar() / 2));
}
void Fruit::printProduct()const { 
	StoreDetails::printProduct();
	cout << this->getNameOfAgriculturalProduct() << "(" << this->getTypeOfAgriculturalProduct() << "," << this->getNumOfYearSeasons() << "," << this->getNumOfSuppliers() << ")" << "(" << this->getAmountOfSugar() << ")" << endl;
}

void Fruit::writeToFile(ofstream& out) const {
	StoreDetails::writeToFile(out);
	out << this->getNameOfAgriculturalProduct() << "(" << this->getTypeOfAgriculturalProduct() << "," << this->getNumOfYearSeasons() << "," << this->getNumOfSuppliers() << ")" << "(" << this->getAmountOfSugar() << ")" << endl;

}


Fruit::~Fruit() { 
	cout << "**this fruit has been added successfully**" << endl;
}