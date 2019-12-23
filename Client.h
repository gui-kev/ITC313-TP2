//Déclaration de la classe chambre

#ifndef _client_h
#define _client_h

#include <string>
#include <vector>
#include "Product.h"

class Client
{
public:
	Client(int uid=1, std::vector <Product* > panier={ },
		   std::string nom="GUIFFO", std::string prenom="Kevin");
	int getUid() const;
	std::string getNom() const;
	std::string getPrenom() const;
	friend std::ostream &operator << (std::ostream &ouput, Client &c);
	//friend std::istream &operator >> (std::istream &input, Client &c);

private:
	const int m_uid;
	std::string m_nom;
	std::string m_prenom;
	std::vector <Product* > m_panier;
};

#endif