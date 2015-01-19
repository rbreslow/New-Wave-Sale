#include <string>
#include "Product.h"

Product::Product(std::string name, double unitPrice) 
{ 
	this->name = name;
	this->unitPrice = unitPrice;
}
Product::Product()
{
	this->name = "";
	this->unitPrice = 0.00;
}
std::string Product::getName() 
{ 
	return name; 
}
double Product::getUnitPrice() 
{ 
	return this->unitPrice; 
}
double Product::getPriceForQuantity(int quantity) {
	return this->unitPrice * quantity; 
}