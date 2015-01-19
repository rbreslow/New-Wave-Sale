#include <string>
#include <vector>
#include "Product.h"
#include "Item.h"
#include "Cart.h"

void Cart::addToCart(Product product, int quantity) 
{
	this->contents.insert(this->contents.begin(), Item(product, quantity));
};
std::vector<Item> Cart::getContents() 
{
	return this->contents; 
};
void Cart::setContents(std::vector<Item> contents)
{
	this->contents = contents;
};
double Cart::getTotalRegPrice()
{
	double totalRegPrice = 0.00;

	for (Item item : contents) {
		totalRegPrice += item.getProduct().getUnitPrice() * item.getQuantity();
	}

	return totalRegPrice;
};