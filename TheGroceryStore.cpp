#include <fstream>
#include "TheGroceryStore.h"
using namespace std;
TheGroceryStore::TheGroceryStore() { 
	this->_arrOfProducts = NULL;
	this->numOfProductsInTheStore = NULL;
	this->nameOfStore = " 'At your Door'";
	this->factorOfStore = 3;

}
void TheGroceryStore::calPriceOfAllProduct() const { 
	double sum = 0;
	ifstream in("prices.txt");
	double price;
	if (in.is_open()) {
		while (!in.eof())
		{
			in >> price;
			sum += price;
		}
	}
	in.close();
	for (int i = 0; i < this->getNumOfProductsInTheStore(); i++) {
		sum += _arrOfProducts[i]->setPriceOfProduct(this->getFactorOfStore());
	}
	cout << "-------------------------------" << endl;
	if (sum < NULL) {
		cout << "Total Price : the factor of store must be suitable for this product" << endl;
		cout << "-----------------------------" << endl;
	}
	else {
		cout << "Total Price : " << sum << endl;
		cout << "-----------------------------" << endl;
	}
}
void TheGroceryStore::printDetailsOfStore() const { 
	string produtDetails = "";
	int count = this->getNumOfProductsInTheStore();
	// read from file
	const string filename = "products.txt";
	ifstream in(filename);
	string line;
	if (in.is_open()) {
		while (!in.eof())
		{
			getline(in, line);
			count++;
			produtDetails += line + "\n";
		}
		count--;
	}
	cout << "the Name Of the Store is: " << this->getNameOfStore() << endl;
	cout << "The numbers of the products in the store is: " << count << endl;
	cout << "the factor of the store is : " << this->getFactorOfStore() << endl;
	cout << "the products that in store are:" << endl;

	if (!count)
		cout << "the store is empty" << endl;
	else {
		cout << produtDetails;
		for (int i = 0; i < this->getNumOfProductsInTheStore(); i++)
			this->_arrOfProducts[i]->printProduct();
	}
	cout << "\n";
}
void TheGroceryStore::changeFactorOfStore() { 
	double factor;
	int flag = 0;
	cout << "please select the new factor of the store" << endl;


	do {
		flag = 0;
		cin >> factor;

		if (cin.fail()) {
			flag = 1;
			cin.clear();
			cin.ignore();
			cout << "the factor must be a positive number" << endl;
		}
		else if (factor <= NULL) {
			flag = 1;
			cout << "the factor must be a positive number" << endl;
		}

		else
			this->factorOfStore = factor;

	} while (flag != 0);
}

void TheGroceryStore::printAllPrices() const { 
	int flag = 0;
	int count = this->getNumOfProductsInTheStore();
	ifstream in("prices.txt");
	double price;
	int i = 1;
	if (in.is_open()) {
		char ch;
		while (!in.eof())
		{
			in >>ch>> price;
			cout << "the price of product number " << i << " is: " << price << endl;
			i++;
			count++;
		}
	}
	in.close();
	if (count == 0) {
		cout << "-------------------------" << endl;
		cout << "No products in the store" << endl;
		cout << "--------------------------" << endl;
	}
	else {
		flag = 1;
		cout << "---------------------------" << endl;
		for (int i = 0; i < this->getNumOfProductsInTheStore(); i++) {
			double num = this->_arrOfProducts[i]->setPriceOfProduct(this->getFactorOfStore());
			if (num < NULL)
				cout << "the price of product number " << i + 1 << " is: " << "the factor of store must be suitable for this product " << endl;
			else
				cout << "the price of product number " << i + 1 << " is: " << this->_arrOfProducts[i]->setPriceOfProduct(this->getFactorOfStore()) << endl;
		}
	}
	if (flag == 1)
		cout << "------------------------------" << endl;
}
void TheGroceryStore::saveAllPrices()const {
	ofstream out("prices.txt", ios::out | ios::app);
	if (!out.is_open()) {
		cout << "Unable to open prices file\n";
		return;
	}
	for (int i = 0; i < this->getNumOfProductsInTheStore(); i++) {
		double num = this->_arrOfProducts[i]->setPriceOfProduct(this->getFactorOfStore());
		out<<"Total price of which you have selected: " <<'$'<< this->_arrOfProducts[i]->setPriceOfProduct(this->getFactorOfStore()) << endl;
	}
	out.close();
}

void TheGroceryStore::addProductToarr() { 

	int flag = 0;
	int choice;
	StoreDetails** temp = new StoreDetails * [this->getNumOfProductsInTheStore() + 1];
	for (int i = 0; i < this->getNumOfProductsInTheStore(); i++)
		temp[i] = this->_arrOfProducts[i];
	// deleting previous products
	delete[] this->_arrOfProducts;

	cout << "Product Type : " << endl;
	cout << "0) Vegtable" << endl;
	cout << "1) Fruit" << endl;
	cout << "2) Cheese" << endl;
	cout << "3) Yogurt" << endl;
	cout << "4) Other Milk Product" << endl;
	cout << "5) Product Package" << endl;
	cout << "your choice :";


	do {
		flag = 0;
		cin >> choice;

		if (cin.fail()) {
			flag = 1;
			cin.clear();
			cin.ignore();
			cout << "the num should be a integer positive number - please choose again" << endl;
		}
		else if (choice < 0 || choice > 6) {
			flag = 1;
			cout << "the number should be between 0 to 5" << endl;
		}

	} while (flag != 0);

	switch (choice)
	{
	case 0:
		temp[this->getNumOfProductsInTheStore()] = new Vegetable;
		break;
	case 1:
		temp[this->getNumOfProductsInTheStore()] = new Fruit;
		break;
	case 2:
		temp[this->getNumOfProductsInTheStore()] = new Cheese;
		break;
	case 3:
		temp[this->getNumOfProductsInTheStore()] = new Yogurt;
		break;
	case 4:
		temp[this->getNumOfProductsInTheStore()] = new OtherMilkProduct;
		break;
	case 5:
		temp[this->getNumOfProductsInTheStore()] = new ProductPackage;
		break;
	default:
		cout << "Please try again" << endl;
		return;
	}
	this->numOfProductsInTheStore++;
	this->_arrOfProducts = temp;

	if (this->checkSerialNumber(this->_arrOfProducts[this->getNumOfProductsInTheStore() - 1]->getSerialNumber())) {
		cout << "----------------------------------" << endl;
		cout << "This product is already exist! - the product has been deleted by system" << endl;
		cout << "----------------------------------" << endl;
		_arrOfProducts[this->getNumOfProductsInTheStore() - 1]->~StoreDetails();
		delete[] _arrOfProducts[this->getNumOfProductsInTheStore() - 1];
		this->numOfProductsInTheStore--;
	}
}
bool TheGroceryStore::checkSerialNumber(int serial) const { 
	for (int i = 0; i < this->getNumOfProductsInTheStore() - 1; i++)
		if (this->_arrOfProducts[i]->getSerialNumber() == serial)
			return true;
	return false;
}
void TheGroceryStore::setNameOfStore() { 
	string name;

	cout << "please select the new name of the store" << endl;
	cin.ignore();
	getline(cin, name);
	this->nameOfStore = name;
}
void TheGroceryStore::addnewemployee() {
	char choice = 'y';
	Employee e;
	while (1)
	{
		if (choice == 'n')break;


		else
		{
			cout << "Enter details about the new Employee:" << endl;
			cin >> e;
			cout << "Information Succesfully registered" << endl;
			em.push_back(e);


		}
		cout << "Do you want to hire an another employee again?[y/n]:" << endl;
		cin >> choice;
	}

}
void TheGroceryStore::searchemployee()
{
	char choice = 'y';
	while (1)
	{
		if (choice == 'n')
		{
			break;

		}
		else

		{

			string n;
			cout << "Enter Employee's Name:" << endl;
			cin >> n;
			int flag = 0;
			for (int i = 0; i < em.size(); i++)
			{
				if (n == em[i].name)
				{
					cout << "The employee's details are:" << endl;
					cout << em[i];
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cout << "There is no one here in this name " << endl;
			}
		}
		cout << "DO you want to search again?[y/n]:" << endl;
		cin >> choice;
	}
}
void TheGroceryStore::showallemployee()
{
	if (em.size() == 0)
	{
		cout << "No employees are hired till now" << endl;
	}
	else
	{
		for (int i = 0; i < em.size(); i++)
		{
			cout << em[i];
		}
	}
}

void TheGroceryStore::writeEmployeesToFile() const {
	const string filename = "employees.txt";

	ofstream out(filename);
	if (!out.is_open()) {
		cout << "Error: unable to open output file for employees.\n";
		return;
	}
	for (int i = 0; i < em.size(); i++)
	{
		out << em[i].name << " " << em[i].gender << " " << em[i].age << " " << em[i].salary << endl;
	}
	out.close();
}

void TheGroceryStore::readEmployeesFromFile() {
	const string filename = "employees.txt";
	ifstream in(filename);
	if (!in.is_open()) {
		cout << "Error: unable to open output file for employees.\n";
		return;
	}
	Employee emp;
	while (!in.eof()) {
		in >> emp.name >> emp.gender >> emp.age >> emp.salary;
		em.push_back(emp);
	}
	in.close();
}

void TheGroceryStore::menu() { //the menu of the program 
	int flag = 0;
	this->readEmployeesFromFile();
	int choice;
	while (1)
	{
		cout << "..::::::::MENU::::::::.." << endl;
		cout << "Welcome To " << this->getNameOfStore() << " Grocery Stores" << endl;
		cout << "1) change the name of the store" << endl;
		cout << "2) Hire a new employee" << endl;
		cout << "3) Search Employee" << endl;
		cout << "4) show all Employee" << endl;
		cout << "5) Add a new Product" << endl;
		cout << "6) Calc total prices" << endl;
		cout << "7) change factor of store" << endl;
		cout << "8) Print all prices" << endl;
		cout << "9) Print all store" << endl;
		cout << "10) EXIT" << endl;
		cout << "Your choice : ";

		do {
			flag = 0;
			cin >> choice;

			if (cin.fail()) {
				flag = 1;
				cin.clear();
				cin.ignore();
				cout << "the num should be a integer positive number - please choose again" << endl;
			}
			else if (choice < 0 || choice > 11) {
				flag = 1;
				cout << "the number should be between 1 to 10" << endl;
			}

		} while (flag != 0);

		switch (choice)
		{
		case 1:
			this->setNameOfStore();
			break;
		case 2:
			this->addnewemployee();
			break;
		case 3:
			this->searchemployee();
			break;
		case 4:
			this->showallemployee();
			break;
		case 5:
			this->addProductToarr();
			break;
		case 6:
			this->calPriceOfAllProduct();
			break;
		case 7:
			this->changeFactorOfStore();
			break;
		case 8:
			this->printAllPrices();
			break;
		case 9:
			this->printDetailsOfStore();
			break;
		case 10:
			this->saveAllProductsToFile();
			this->writeEmployeesToFile();
			this->saveAllPrices();
			cout << "All update data has been written to file.\n";
			cout << "Good BYE" << endl;
		
			return;
		default:
			cout << "Please try again" << endl;
			break;
		}
	}


}
void TheGroceryStore::saveAllProductsToFile()const {
	const string filename = "products.txt";
	// ofstream outFile(filename);

	ofstream outFile(filename, ios::out | ios::app);
	if (!outFile.is_open()) {
		cout << "Error: unable to open input file\n";
		return;
	}
	for (int i = 0; i < this->getNumOfProductsInTheStore(); i++) {
		this->_arrOfProducts[i]->writeToFile(outFile);
	}
	outFile.close();
}
TheGroceryStore::~TheGroceryStore() { 
	if (this->_arrOfProducts != NULL) {
		for (int i = 0; i < this->getNumOfProductsInTheStore(); i++) {
			delete[] this->_arrOfProducts[i];
		}
		delete this->_arrOfProducts;
	}
}