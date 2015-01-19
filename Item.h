#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Product.h"

class Item
{
	Product product;
	int quantity;
	double price;

public:
	Item(Product product, int quantity);

	Product getProduct();
	int getQuantity();
	void setQuantity(int quantity);
	double getPrice();
	void setPrice(double price);
};

#endif