#ifndef MEMPROMO_H
#define MEMPROMO_H

#include <string>
#include "Product.h"

class Software : public Product
{
	friend class Product;
public:
	double getPriceForQuantity(int quantity);
};

#endif