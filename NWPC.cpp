#include <string>
#include <vector>
#include "Product.h"
#include "NWPC.h"

double NWPC::getPriceForQuantity(int quantity)
{
	if (quantity >= 3 && quantity <= 5) {
		return (this->getUnitPrice() - (this->getUnitPrice() * 0.05)) * quantity;
	}
	else if (quantity > 5) {
		return (this->getUnitPrice() - (this->getUnitPrice() * 0.10)) * quantity;
	}
	else {
		return this->getUnitPrice() * quantity;
	}
}