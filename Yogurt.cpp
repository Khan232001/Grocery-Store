#include "Yogurt.h"


Yogurt::Yogurt() { 
	cout << "the  yogurt is on" << endl;
	this->_typeOfMilkProduct = 2;
}
void Yogurt::printProduct()const { 
	MilkProduct::printProduct();
	cout << endl;
}
void Yogurt::writeToFile(ofstream& out) const {
	MilkProduct::writeToFile(out);
	out << endl;
}
double Yogurt::setPriceOfProduct(double num) const { 
	return (MilkProduct::setPriceOfProduct(num));
}


Yogurt::~Yogurt()
{
	cout << "this yogurt product is successfully added" << endl;
}
