
#include<iostream>
#include<string>
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
			if (titleProduct.compare(m_panier.at(i)->getTitle())==1)
				m_panier.at(i)->setQtt(newqtt);
		}
	}
}

void Client::del_product(std::string title){
	if (m_panier.empty())
		std::cout<<" Nothing to do. "<<std::endl;
	else{
		int a = m_panier.size();
		for (int i=0; i<a; i++){
			if (title.compare(m_panier.at(i)->getTitle())==1)
				m_panier.at(i) = nullptr;			
		}
	}
}

std::ostream &operator << (std::ostream &output, Client &c){
	output << " ID : "<<c.m_uid<<" -  Prenom : "<< c.m_nom <<" -  Nom : "<< c.m_prenom <<" - Panier : ";
	int a = c.m_panier.size(); 
	if (a>0)	
		for (int i=0; i<a; i++)
			std::cout<<*c.m_panier.at(i)<<std::endl;
	return output;
}