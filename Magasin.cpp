
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

void Magasin::displayClient(){
	int a = m_clients.size();
	for (int i=0; i<a; i++)
		std::cout<< *m_clients.at(i)<<std::endl;
}

void Magasin::displaySelectClt(int id, std::string nom){
	if (m_clients.empty())
		std::cout<<"Pas de client"<<std::endl;
	else {
		int a = m_clients.size();
		for (int i=0; i<a; i++)
			if(m_clients.at(i)->getUid()==id || nom.compare(m_clients.at(i)->getNom())==1)
				std::cout<<*m_clients.at(i)<<std::endl;
	}
}

void Magasin::addprodClt(Product p, Client* c){
	if (m_clients.empty()){
		m_clients.push_back(c);
		m_clients.front()->addProduct(p);
	}
	else {
		int a =m_clients.size();
		for (int i=0; i<a; i++)
			if(m_clients.at(i)->getUid()==c->getUid())
				m_clients.at(i)->addProduct(p);
	}
}

void Magasin::delprodClt(Product p, Client* c){
	if (m_clients.empty())
		std::cout<<"Rien à faire"<<std::endl;
	else {
		int a = m_clients.size();
		for (int i=0; i<a; i++)
			if (m_clients.at(i)->getUid()==c->getUid())
				m_clients.at(i)->delProduct(p.getTitle());
	}		
}