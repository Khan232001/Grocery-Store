#include "MilkProduct.h"


MilkProduct::MilkProduct() { // type,name,color and numOfFat
	cout << "MILK PRODUCT CONSTRACOT IS ON" << endl;
	this->_typeOfProduct = 3;
	this->setNameOfMilkProduct();
	this->setNumOfFat();

}
void MilkProduct::setNameOfMilkProduct() { 
	string name;
	cout << "please select the name of the milk product" << endl;
	cin >> name;
	this->_nameOfMilkProduct = name;
}

void MilkProduct::setNumOfFat() { 
	double num;
	int flag = 0;

	cout << "please select the number of fat" << endl;
	do {
		flag = 0;
		cin >> num;

		if (cin.fail()) {
			flag = 1;
			cin.clear();
			cin.ignore();
			cout << "the num of fat shuold be a positive number - please choose again" << endl;
		}
		else if (num < NULL) {
			flag = 1;
			cout << "the num of fat shuold be a positive number - please choose again" << endl;
		}

		else
			this->_numOfFat = num;

	} while (flag != 0);
}
double MilkProduct::setPriceOfProduct(double num) const { 

	return (((StoreDetails::setPriceOfProduct(num)) - this->getNumOfFat()) * this->getTypeOfProduct());
}
void MilkProduct::printProduct()const { 
	StoreDetails::printProduct();
	cout << this->getNameOfMilkProduct() << " (" << this->getTypeOfMilkProduct() << "," << this->getNumOfFat() << ") ";

}

void MilkProduct::writeToFile(ofstream& out)const {
	StoreDetails::writeToFile(out);
	out << this->getNameOfMilkProduct() << " (" << this->getTypeOfMilkProduct() << "," << this->getNumOfFat() << ") ";

}


MilkProduct::~MilkProduct() { 
	cout << "**this milkProduct is successfully added**" << endl;
}