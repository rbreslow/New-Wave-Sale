#ifndef INVOICE_H
#define INVOICE_H

#include <string>
#include <vector>
#include "Product.h"
#include "Item.h"
#include "Cart.h"

class Invoice
{
	Cart cart;
	std::string customerName;
	double origPrice;

public:
	Invoice(Cart cart, std::string customerName);

	void print();
};

#endif