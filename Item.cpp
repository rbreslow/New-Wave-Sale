#include <string>
#include "Item.h"

Item::Item(Product product, int quantity)
{
	this->product = product;
	this->quantity = quantity;
	this->price = product.getPriceForQuantity(this->quantity);
}
Product Item::getProduct() { 
	return this->product; 
}
int Item::getQuantity() { 
	return this->quantity; 
}
void Item::setQuantity(int quantity) 
{ 
	this->quantity = quantity; 
}
double Item::getPrice() 
{ 
	return this->price; 
}
void Item::setPrice(double price)
{ 
	this->price = price; 
}