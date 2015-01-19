#include <iostream>
#include <string>
#include "Product.h"
#include "Cart.h"
#include "Invoice.h"
#include "NWPC.h"
#include "Software.h"

//product constructor format is: name, price
Product* products[] = {
	new NWPC("NW-PC", 675.00),
	new Product("Memory Card", 69.95),
	new Product("Disk Drive", 198.50),
	new Software("Software", 34.98),
};

int main()
{
	printf("Starting Sasha's debug thing.\n");

	products[0]->getPriceForQuantity(0);
	products[1]->getPriceForQuantity(0);
	products[2]->getPriceForQuantity(0);
	products[3]->getPriceForQuantity(0);

	printf("Ending Sasha's debug thing.\n");

	//create a new cart object
	Cart cart = Cart();
	std::string customerName;

	std::cout << "Customer name: ";
	getline(std::cin, customerName);

	//add products to cart
	for (Product* product : products) {
		std::cout << "Quantity of " + product->getName() + ": ";

		int quantity;
		std::cin >> quantity;

		if (quantity > 0) {
			cart.addToCart(*product, quantity);
		}
	}

	//generate our invoice with the cart and print it
	Invoice invoice = Invoice(cart, customerName);
	invoice.print();

	while (true);
}