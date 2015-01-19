#include <string>
#include <vector>
#include "Product.h"
#include "Item.h"
#include "Cart.h"

void Cart::addToCart(Product product, int quantity) 
{
	this->contents.insert(this->contents.begin(), Item(product, quantity));
}
Item Cart::getItem(int i) 
{
	return this->contents[i];
}
int Cart::getTotalItems()
{
	return this->contents.size();
}
void Cart::setContents(std::vector<Item> contents)
{
	this->contents = contents;
}
double Cart::getTotalRegPrice()
{
	double totalRegPrice = 0.00;

	for (Item item : contents) {
		totalRegPrice += item.getProduct().getUnitPrice() * item.getQuantity();
	}

	return totalRegPrice;
}