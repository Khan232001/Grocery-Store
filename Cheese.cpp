#include "Cheese.h"


Cheese::Cheese() { 
	this->_typeOfMilkProduct = 3;
	this->setNumOfExtraCheese();

}
void Cheese::setNumOfExtraCheese() { 
	int num;
	int flag = 0;

	cout << "please select number of extra" << endl;

	do {
		flag = 0;

		cin >> num;

		if (cin.fail()) {
			flag = 1;
			cin.clear();
			cin.ignore();
			cout << "the num of extra cheese should be a integer positive number - please choose again" << endl;
		}
		else if (num < NULL)
		{
			flag = 1;
			cout << "the num of extra cheese should be a integer positive number - please choose again" << endl;
		}

		else
			this->_numOfExtraCheese = num;
	} while (flag != 0);

}

double Cheese::setPriceOfProduct(double num) const { 

	return (MilkProduct::setPriceOfProduct(num) + this->getNumOfExtraCheese());
}

void Cheese::printProduct()const { 
	MilkProduct::printProduct();
	cout << "(" << this->getNumOfExtraCheese() << ")" << endl;

}

void Cheese::writeToFile(ofstream& out)const {
	MilkProduct::writeToFile(out);
	out << "(" << this->getNumOfExtraCheese() << ")" << endl;

}

Cheese::~Cheese() { 
	cout << "**Adding cheese product is successfully completed**" << endl;
}
