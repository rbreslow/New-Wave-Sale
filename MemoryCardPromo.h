#ifndef MEMPROMO_H
#define MEMPROMO_H

#include <string>
#include "Cart.h"
#include "Promotion.h"

class MemoryCardPromo : public Promotion
{
public:
	Cart calculate(Cart cart);
};

#endif