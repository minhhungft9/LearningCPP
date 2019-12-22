#ifndef STOCK_H
#define STOCK_H

#include "stock.h"
#endif

#include <iomanip>

Stock::Stock() {
	revenue = 0;
	list = new map<string, Item>();
}

Stock::~Stock() {
	delete list;
}

void Stock::addItem(string name, float price, int amount) {
	Item i;
	map<string, Item>::iterator find;
	find = list->find(name);
	if (find != list->end()) {	
		cout << "Stock already has the item." << endl;
	}
	else {
		i.setName(name);
		i.setPrice(price);
		i.setAmount(amount);
		(*list)[name] = i;
	}
}

void Stock::Sell(string name, int n) {
	map<string, Item>::iterator find;
	find = list->find(name);
	if (find != list->end()) {
		revenue = revenue + find->second.sell(n);
	}
	else {
		cout << "Can't find item!" << endl; 
	}
}

void Stock::Replenish(string name, int n) {
	map<string, Item>::iterator find;
	find = list->find(name);
	if (find != list->end()) {
		find->second.add(n);
	}
	else {
		cout << "Can't find item!" << endl;
	}
}

void Stock::Clear() {
	list->clear();
}

void Stock::Find(string n) {
	cout << "Result:" << endl;
	int result = 0;
	cout << left << setw(20) << "ITEM" << left << setw(15) << "PRICE(euro)" << left << setw(15) << "AMOUNT" << left << setw(15) << "SOLD\n" << endl;
	for (map<string, Item>::iterator i = list->begin(); i != list->end(); i++) {
		if (i->second.getName().find(n) != string::npos) {
			i->second.printItem();
			++result;
		}
	}
	if (result == 0)
	{
		cout << "Not found!" << endl;
	}
	result = 0;
}

void Stock::printList() {
	cout << left << setw(20) << "ITEM" << left << setw(15) << "PRICE(euro)" << left << setw(15) << "AMOUNT" << left << setw(15) << "SOLD\n" << endl;
	for (map<string, Item>::iterator i = list->begin(); i != list->end(); i++) {
		i->second.printItem();
	}
	cout << "\nTotal revenue: " << revenue << "e" << endl;
}

/*
void Stock::loadMoney() {
	ifstream mymoney("money.txt");
	string money;
	if (mymoney.is_open()) {
		getline(mymoney, money);
		if (money.empty()) {
			revenue = 0;
		}
		else
		{
			revenue = stof(money);
		}
	}
}

void Stock::saveMoney() {
	ofstream mymoney("money.txt");
	mymoney << revenue;
}
*/

ostream &operator<<(ostream& out, const Stock& s) {
	out << s.revenue << endl;
	for (map<string, Item>::iterator i = s.list->begin(); i != s.list->end(); i++) {
		out << i->second;
	}
	return out;
}

istream &operator >> (istream& in, Stock& s) {
	Item i;
	string revenue;
	int length = 0;
	char c = '\0';

	delete s.list;
	s.list = new map<string, Item>();

	getline(in, revenue);
	//cout << "Revenue: " << revenue << endl;
	if (revenue.empty()) {
		s.revenue = 0;
	}
	else
	{
		s.revenue = stof(revenue);
	}

	while (in >> i) {
		(*s.list)[i.getName()] = i;
	}
	return in;
}