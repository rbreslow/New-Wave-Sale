#include <string>
#include "Product.h"
#include "Cart.h"
#include "MemoryCardPromo.h"

Item getItemFromCart(Cart cart, std::string name) {
	for (int i = 0; i < cart.getTotalItems(); i++) {
		Item item = cart.getItem(i);

		Product product = item.getProduct();

		if (product.getName() == name) {
			return item;
		}
	}

	return Item(Product(), 0);
}
int numberOfProductsInCart(Cart cart, std::string name) {
	int num = 0;

	for (int i = 0; i < cart.getTotalItems(); i++) {
		Item item = cart.getItem(i);

		Product product = item.getProduct();

		if (product.getName() == name) {
			num += item.getQuantity();
		}
	}

	return num;
}
bool itemIsInCart(Cart cart, std::string name) {
	for (int i = 0; i < cart.getTotalItems(); i++) {
		Item item = cart.getItem(i);

		Product product = item.getProduct();

		if (product.getName() == name) {
			return true;
		}
	}

	return false;
}
Cart MemoryCardPromo::calculate(Cart cart) {
	std::vector<Item> contents = cart.getContents();
	int diskDrives = numberOfProductsInCart(cart, "Disk Drive");
	int numberOfFreeMemoryCards = diskDrives / 3;

	// if there aren't any free cards we stop here
	if (numberOfFreeMemoryCards > 0) {
		// how many already in cart?
		int memoryCardsInCart = numberOfProductsInCart(cart, "Memory Card");

		// there are less than there should be
		if (memoryCardsInCart < numberOfFreeMemoryCards) {
			// there aren't enough cards. add them.
			if (itemIsInCart(cart, "Memory Card")) {
				// get the item from the cart and modify the contents to be
				// the right quantity
				Item item = getItemFromCart(cart, "Memory Card");
				item.setQuantity(memoryCardsInCart + numberOfFreeMemoryCards);
			}
			else {
				// there aren't any memory cards in cart so need to add them
				contents.insert(contents.begin(), Item(Product("Memory Card", 0.00), numberOfFreeMemoryCards));
			}

			// some of the cards are free but not all
		}
		else if (memoryCardsInCart > numberOfFreeMemoryCards) {
			Item item = getItemFromCart(cart, "Memory Card");
			item.setQuantity(item.getQuantity());
			item.setPrice(item.getProduct().getPriceForQuantity(item.getQuantity() - numberOfFreeMemoryCards));
		}
		else if (memoryCardsInCart == numberOfFreeMemoryCards) {
			Item item = getItemFromCart(cart, "Memory Card");
			item.setPrice(0.00);
		}
	}

	cart.setContents(contents);
	return cart;
}
