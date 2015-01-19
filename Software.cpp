#include <string>
#include <vector>
#include "Product.h"
#include "Software.h"

double Software::getPriceForQuantity(int quantity)
{
	printf("Hello from Software's method!  Also Jerry is a faggot!\n"); 
	
	if (quantity == 1) {
		return 34.98 * quantity;
	}
	else if (quantity == 2) {
		return 32.98 * quantity;
	}
	else if (quantity == 3) {
		return 30.98 * quantity;
	}
	else if (quantity == 4) {
		return 28.98 * quantity;
	}
	else if (quantity == 5) {
		return 26.98 * quantity;
	}
	else if (quantity == 6) {
		return 24.98 * quantity;
	}
	else if (quantity == 7) {
		return 22.98 * quantity;
	}
	else if (quantity >= 8) {
		return 15.98 * quantity;
	}
	else {
		return 0.00;
	}
}