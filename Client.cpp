
#include<iostream>
#include<string>
#include "Client.h"

Client::Client(int uid,std::vector<Product* > panier,
			   std::string nom, std::string prenom) : m_uid(uid) {
	m_nom=nom;
	m_prenom=prenom;
	m_panier=panier;
}

int Client::getUid() const {
	return m_uid;
}

std::string Client::getNom() const { 
	return m_nom;
}

std::string Client::getPrenom() const { 
	return m_prenom;
}

std::ostream &operator << (std::ostream &output, Client &c){
	output << " ID : "<<c.m_uid<<" -  Prenom : "<<c.m_prenom<<" -  Nom : "<< c.m_nom << std::endl;
	return output; 
}

/*std::istream &operator >> (std::istream &input, Client &c) {
	std::cout << "Id : "; input >> c.m_uid;
	std::cout << "Nom? "; input >> c.m_nom;
	std::cout << "m_prenom? "; input >> c.m_prenom;
	return input;
}*/