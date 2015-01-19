#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <string>
#include "Product.h"

class Software : public Product
{
public: 
	Software() : Product() {};
	Software(std::string name, double price) : Product(name, price) {};

	virtual double getPriceForQuantity(int quantity) = 0;
};

#endif