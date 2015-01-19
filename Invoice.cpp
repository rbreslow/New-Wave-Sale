#include <string>
#include <stdio.h>
#include "Product.h"
#include "Item.h"
#include "Cart.h"
#include "Invoice.h"
#include "Promotion.h"
#include "MemoryCardPromo.h"

Promotion promotions[] = {
	MemoryCardPromo(),
};

Invoice::Invoice(Cart cart, std::string customerName)
{
	this->cart = cart;
	this->customerName = customerName;

	for (Promotion promotion : promotions) {
		cart = promotion.calculate(cart);
	}

	this->origPrice = this->cart.getTotalRegPrice();
}
void Invoice::print()
{
	double totalPrice = 0.00;

	printf("\n*************************************************************\n");

	printf("\tNew Wave Computers\n\tCUSTOMER: %s\n\n", customerName.c_str());
	printf("%-15s %-30s %s\n", "Quantity", "ITEM", "COST");

	for (int i = 0; i < cart.getTotalItems(); i++) {
		Item item = cart.getItem(i);

		Product product = item.getProduct();
		int quantity = item.getQuantity();
		double price = item.getPrice();

		printf("%-15d %-30s %.2f\n", quantity, product.getName().c_str(), price);

		totalPrice += price;
	}

	printf("\n\t\t%-30s %.2f", "SUB TOTAL", totalPrice);
	totalPrice = totalPrice - (totalPrice * 0.10);
	printf("\n\t\t%-30s %.2f", "TOTAL WITH 10% DISCOUNT", totalPrice);
	printf("\n\t\t%-30s %.2f", "TAX", totalPrice * 0.06);
	totalPrice = totalPrice + (totalPrice * 0.06);
	printf("\n\t\t%-30s %.2f", "TOTAL", totalPrice);

	if (origPrice > totalPrice) {
		printf("\n\n\t\t\tYou saved $%.2f!", (origPrice - totalPrice));
	}
	else {
		printf("\n\n\t\t\tYou saved $0.00!");
	}

	printf("\n\n*************************************************************\n");
}