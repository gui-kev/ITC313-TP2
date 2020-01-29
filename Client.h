//Déclaration de la classe chambre

#ifndef _client_h
#define _client_h

#include <string>
#include <vector>
#include "Product.h"
//#include "Magasin.h"

class Client
{
public:
	Client(int uid, std::string nom="GUIFFO", std::string prenom="Kevin",std::vector <Product* > panier={ });
	int getUid() const;
	std::string getNom() const;
	std::string getPrenom() const;
	void add_product(Product* p); 	// permet d'ajouter un produit au panier d'achat du client
	void clear_panier(); 			// permet de vider le panier d'achat
	void modify_product(std::string title, int newqtt);	//permet de modifier la quantité du produit d'un panier d'achat
	void del_product(std::string title); 					//permet de supprimer un produit du panier d'achat
	friend std::ostream &operator << (std::ostream &ouput, Client &c);//surcharge de l'opérateur "<<" pour afficher toutes les informations du client

private:
	const int m_uid;
	std::string m_nom;
	std::string m_prenom;
	std::vector <Product* > m_panier;
};

#endif
