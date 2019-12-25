
#include<iostream>
#include<string>
#include<array>
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

void Client::addProduct(Product p) {
	m_panier.push_back(&p);
}

void Client::clearPanier(){
	m_panier.clear();
}

void Client::modifyProduct(std::string titleProduct, int newqtt){
	if (m_panier.empty())
		std::cout<<"Rien à faire"<<std::endl;
	else{
		int a = m_panier.size();
		for (int i=0; i<a; i++){
			if (titleProduct.compare(m_panier.at(i)->getTitle())==1)
				m_panier.at(i)->setQtt(newqtt);
		}
	}
}

void Client::delProduct(std::string titleP){
	if (m_panier.empty())
		std::cout<<"Rien à faire"<<std::endl;
	else{
		int a = m_panier.size();
		for (int i=0; i<a; i++){
			if (titleP.compare(m_panier.at(i)->getTitle())==1)
				m_panier.erase(m_panier.begin()+i);
		}
	}
}

std::ostream &operator << (std::ostream &output, Client &c){
	int a = c.m_panier.size(); 
	output << " ID : "<<c.m_uid<<" -  Prenom : "<<c.m_prenom
		   <<" -  Nom : "<< c.m_nom
		   <<std::endl<<"*****Panier*****"<<std::endl;
	for (int i=0; i<a; i++)
		std::cout<<*c.m_panier.at(i);
	return output;
}