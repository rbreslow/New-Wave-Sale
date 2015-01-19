#include <iostream>
#include <string>
#include "Product.h"
#include "Cart.h"
#include "Invoice.h"
#include "NWPC.h"
#include "Software.h"

//product constructor format is: name, price
Product products[] = {
	NWPC("NW-PC", 675.00),
	Product("Memory Card", 69.95),
	Product("Disk Drive", 198.50),
	Software("Software", 34.98),
};

int main()
{
	printf("Starting Sasha's debug thing.\n");

	NWPC thing1("NW-PC", 675.00);
	Product thing2("Memory Card", 69.95);
	Product thing3("Disk Drive", 198.50);
	Software thing4("Software", 34.98);

	thing1.getPriceForQuantity(0);
	thing2.getPriceForQuantity(0);
	thing3.getPriceForQuantity(0);
	thing4.getPriceForQuantity(0);

	printf("Ending Sasha's debug thing.\n");

	//create a new cart object
	Cart cart = Cart();
	std::string customerName;

	std::cout << "Customer name: ";
	getline(std::cin, customerName);

	//add products to cart
	for (Product product : products) {
		std::cout << "Quantity of " + product.getName() + ": ";

		int quantity;
		std::cin >> quantity;

		if (quantity > 0) {
			cart.addToCart(product, quantity);
		}
	}

	//generate our invoice with the cart and print it
	Invoice invoice = Invoice(cart, customerName);
	invoice.print();

	while (true);
}