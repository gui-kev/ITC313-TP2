
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
	void addProduct(Product p); //méthode permettant d'ajouter un produit au magasin
	void displayProduct();//affiche tous les produits du magasin
	void displaySelectP(std::string title);// displaySelectP: permet d'afficher un produit sélectionné
	void updateProduct(std::string title, int qtt);//met à jour la quantité d'un produit 
	void addClient(Client c); //ajoute un client au magasin
	void displayClient();// affiche tous les clients du magasin
	void displaySelectClt(int id, std::string nom); //affiche un client à partir de son nom ou de son identifiant
	void addprodClt(Product p, Client* c); //méthode permettant d'ajouter un produit au panier d'achat d'un client

private:
	std::vector<Product*> m_products;
	std::vector<Client*> m_clients;
	//std::vector<Order*> m_orders;	
};

#endif