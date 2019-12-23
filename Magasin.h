
#ifndef _magasin_h
#define _magasin_h

#include <vector>
#include "Product.h"
#include "Client.h"

class Magasin
{
public:
	Magasin(std::vector<Product*> prod, std::vector<Client*> clt);
			//std::vector<Order*> cmd);
	void addProduct(Product p);
	void displayProduct();
	void displaySelectP(std::string title);// displaySelectP: permet d'afficher un produit sélectionné
	void updateProduct(std::string title, int qtt);
	void addClient(Client c);

private:
	std::vector<Product*> m_products;
	std::vector<Client*> m_clients;
	//std::vector<Order*> m_orders;	
};

#endif