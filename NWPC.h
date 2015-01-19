#ifndef NWPC_H
#define NWPC_H

#include <string>
#include "Product.h"

class NWPC : public Product
{
public:
	NWPC() : Product() {};
	NWPC(std::string name, double price) : Product(name, price) {};

	virtual double getPriceForQuantity(int quantity);
};

#endif