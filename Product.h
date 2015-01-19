#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
	std::string name;
	double unitPrice;

public:
	Product();
	Product(std::string name, double unitPrice);

	std::string getName();
	double getUnitPrice();
	virtual double getPriceForQuantity(int quantity) = 0;
};

#endif