#ifndef PROMOTION_H
#define PROMOTION_H

#include <string>
#include "Cart.h"

class Promotion
{
	Cart cart;

public:
	virtual Cart calculate(Cart cart);
};

#endif