
#include <iostream>
#include <vector>
#include "Magasin.h"

int main()
{
	Product p1;
	std::vector<Product*> vectprod;
	Magasin m1(vectprod);
	m1.addProduct(p1);
	m1.addProduct();
	m1.displayProduct();
	m1.displaySelectP("Kaspersky");
	std::cout<<"Run ok"<<std::endl;
	return 0;
}