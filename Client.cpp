
#include<iostream>
#include<cstring>
#include "Client.h"

Client::Client(int uid,std::string nom, std::string prenom,std::vector<Product* > panier) : m_uid(uid) {
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

std::vector<Product*> Client::getPanier() const{
	return m_panier;//.front(); //retourne l'adresse du premier élément du panier pour la commande
}

void Client::add_product(Product* p) {
	if (p != nullptr)
		m_panier.push_back(p);
}

void Client::clear_panier(){
	m_panier.clear();
}

void Client::modify_product(std::string titleProduct, int newqtt){
	if (m_panier.empty())
		std::cout<<" Nothing to do. "<<std::endl;
	else{
		int a = m_panier.size();
		for (int i=0; i<a; i++){
			if (titleProduct.compare(m_panier.at(i)->getTitle()) == 1)
				m_panier.at(i)->setQtt(newqtt);
		}
	}
}
/*void Client::add_product(std::string titleProduct) {
	int a = m_panier.size();
		for (int i=0; i<a; i++){
			if (titleProduct == m_panier.at(i)->getTitle())
				m_panier.push_back(m_panier.at(i));
		}
}*/

void Client::del_product(std::string title){
	if (m_panier.empty())
		std::cout<<" Nothing to do. "<<std::endl;
	else{
		int a = m_panier.size();
		for (int i=0; i<a; i++){
			if (title.compare(m_panier.at(i)->getTitle()) == 1)
				m_panier.erase(m_panier.begin()+i);		
		}
	}
}

std::ostream &operator << (std::ostream &output, Client& c){
	int b = std::strlen(c.m_nom.c_str());
	int e = std::strlen(c.m_prenom.c_str());
	if (b < 15)
		c.m_nom.resize(15,' ');
	if (e < 15)
		c.m_prenom.resize(15,' ');

	output << "| "<< c.m_uid <<"     "<< c.m_prenom << c.m_nom << std::endl <<"|		Panier : ";
	int a = c.m_panier.size(); 
	if (a>0)	
		for (int i=0; i<a; i++)
			output <<*c.m_panier.at(i);
	return output;
}

/*std::ostream &operator << (std::ostream &output, Client&  c){
	output << " ID : "<<c.m_uid<<" -  Prenom : "<< c.m_nom <<" -  Nom : "<< c.m_prenom <<" - Panier : ";
	int a = std::strlen(c.m_nom.c_str());
	int b = std::strlen(c.m_prenom.c_str());
	if (a < 15)
		c.m_nom.resize(15,' ');
	if (b < 15)
		c.m_prenom.resize(15,' ');

	output << "| " << p.m_title << p.m_desc
		   << "(" << s  << p.m_price << " € |";
	return output; 
}*/