#include "Vegetable.h"


Vegetable::Vegetable() { 
	cout << "VegtableProduct is on" << endl;
	this->_typeOfAgriculturalProduct = 1;
	this->setNumOfVitamins();
}

void Vegetable::setNumOfVitamins() { 
	int num;
	int flag = 0;

	cout << "please select number of vitamins" << endl;

	do {
		flag = 0;

		cin >> num;


		if (cin.fail()) {
			flag = 1;
			cin.clear();
			cin.ignore();
			cout << "the number of vitamins must be a positive number up by 0" << endl;
		}
		else if (num < NULL) {
			flag = 1;
			cout << "the number of vitamins must be a positive number up by 0" << endl;
		}
		else
			this->_numOfVitamins = num;

	} while (flag != 0);
}
double Vegetable::setPriceOfProduct(double num) const { 
	return (AgriculturalProduct::setPriceOfProduct(num) + (2 * this->getNumOfVitamins()));
}
void Vegetable::printProduct()const { 
	StoreDetails::printProduct();
	cout << this->getNameOfAgriculturalProduct() << "(" << this->getTypeOfAgriculturalProduct() << "," << this->getNumOfYearSeasons() << "," << this->getNumOfSuppliers() << ")" << "(" << this->getNumOfVitamins() << ")" << endl;

}

void Vegetable::writeToFile(ofstream& out) const {
	StoreDetails::writeToFile(out);
	out << this->getNameOfAgriculturalProduct() << "(" << this->getTypeOfAgriculturalProduct() << "," << this->getNumOfYearSeasons() << "," << this->getNumOfSuppliers() << ")" << "(" << this->getNumOfVitamins() << ")" << endl;

}


Vegetable::~Vegetable() { 
	cout << "**this vegetable product is successfully added**" << endl;
}