#ifndef _commande_h
#define _commande_h

#include "Client.h"
#include "Product.h"

class Commande 
{
public:
	Commande(int uid, Client* clt, std::vector<Product*> products, bool status);
	friend std::ostream& operator << (std::ostream &output, Commande& order); // surcharge de l'opérateur << pour afficher toutes les informations d'une commande

private: 
	const int m_uid;
	Client* m_client;
	std::vector<Product*> m_products;
	bool m_status;
};

#endif
