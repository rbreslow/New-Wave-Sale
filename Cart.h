#ifndef CART_H
#define CART_H

#include <string>
#include <vector>
#include "Product.h"
#include "Item.h"

class Cart
{
	std::vector<Item> contents;

public:
	void addToCart(Product product, int quantity);
	std::vector<Item> getContents();
	void setContents(std::vector<Item> contents);
	double getTotalRegPrice();
};

#endif