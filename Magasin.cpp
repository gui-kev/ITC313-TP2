
#include <iostream>
#include <cstring>
#include "Magasin.h"

Magasin::Magasin(std::vector<Product*> prod, std::vector<Client*> clt)
				 //std::vector<Order*> cmd)
{
	m_products=prod;
	m_clients=clt;
	//m_orders=cmd;
}

void Magasin::addProduct(Product p){
	m_products.push_back(&p);
}

void Magasin::displayProduct(){
	int a = m_products.size();
	for (int i=0; i<a; i++){
		std::cout<< *m_products.at(i)<<std::endl;
	}
}

void Magasin::displaySelectP(std::string title){
	if (m_products.empty())
			std::cout<<"Magasin vide"<<std::endl;
	else{
		int a = m_products.size();
		for (int i=0; i<a; i++){
			if (title.compare(m_products.at(i)->getTitle())==1)
				std::cout<< *m_products.at(i)<<std::endl;
			else std::cout<<"Pas de produit "<<title<<"."<<std::endl;
		}
	}
}

void Magasin::updateProduct(std::string title, int new_qtt){
	if (m_products.empty())
		std::cout<<"Magasin vide"<<std::endl;
	else{
		int a = m_products.size();
		for (int i=0; i<a; i++){
			if (title.compare(m_products.at(i)->getTitle())==1)
				m_products.at(i)->setQtt(new_qtt);
		}
	}
}

void Magasin::addClient(Client c){
	m_clients.push_back(&c);
}