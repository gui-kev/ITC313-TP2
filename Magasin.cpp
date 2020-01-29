
#include <iostream>
#include <cstring>
#include "Magasin.h"

Magasin::Magasin(){}

void Magasin::add_product(std::string title, std::string desc, int qtt, float price){
	Product p(title, desc, qtt, price);
	m_products.push_back(&p);
	std::cout<<" Product add. "<<std::endl;
}

void Magasin::display_product(){
	int a = m_products.size();
	for (int i=0; i<a; i++){
		std::cout<< *m_products.at(i)<<std::endl;
	}
}

void Magasin::display_select_product(std::string title){
	if (m_products.empty())
			std::cout<<" No Product."<<std::endl;
	else{
		int a = m_products.size();
		for (int i=0; i<a; i++){
			if (title.compare(m_products.at(i)->getTitle())==1)
				std::cout<< *m_products.at(i)<<std::endl;
			else std::cout<<" No product named : "<< title <<"."<<std::endl;
		}
	}
}

void Magasin::update_product_quantity(std::string title, int new_qtt){
	if (m_products.empty())
		std::cout<<"No product to update."<<std::endl;
	else{
		int a = m_products.size();
		for (int i=0; i<a; i++){
			if (title.compare(m_products.at(i)->getTitle())==1)
				m_products.at(i)->setQtt(new_qtt);
		}
	}
}

void Magasin::add_client(std::string nom, std::string prenom){
	static int count = 0;
	int id = count++;
	std::vector<Product* > panier;
	Client* c = new Client(id, nom, prenom, panier);
	m_clients.push_back(c);
}

void Magasin::display_client(){
	int a = m_clients.size();
	for (int i=0; i<a; i++)
		std::cout<< *m_clients.at(i)<<std::endl;
}

void Magasin::display_select_clt(std::string nom, std::string prenom){
	//if (m_clients.empty())
	//	std::cout<<" No client. "<<std::endl;
	//else {
		int a = m_clients.size();
		Client* c = nullptr;
		for (int i=0; i<a; i++){
			if(nom.compare(m_clients.at(i)->getNom())==1 || prenom.compare(m_clients.at(i)->getPrenom())==1)
				c = m_clients.at(i);
		}
		if(c == nullptr) std::cout<<" No client named : "<< nom <<std::endl;
		else 	std::cout<<" Display name "<< *c <<std::endl;
	//}
}

void Magasin::display_select_clt(int id_clt){
	if (m_clients.empty())
		std::cout<<" No client. "<<std::endl;
	else {
		int a = m_clients.size();
		Client* c = nullptr;
		for (int i=0; i<a; i++){
			if(m_clients.at(i)->getUid() == id_clt)
				c = m_clients.at(i);
		}
		if(c == nullptr) std::cout<<" No client id :#"<< id_clt <<std::endl;
		else std::cout<< " Display client "<<*c <<std::endl;
	}
}

Product* Magasin::return_product(std::string& title){
	Product* p = nullptr;
	/*if (m_products.empty()){
		std::cout<<" No product. "<<std::endl;
		return p;
	}
	else {*/
		int a = m_products.size();
		for (int i=0; i<a; i++)
			if (title.compare(m_products.at(i)->getTitle())==1)
				p = m_products.at(i);
		return p;
	//}
}

void Magasin::add_product_clt(std::string title, std::string prenom_clt, std::string nom_clt){
	if (m_clients.empty()){
		add_client(prenom_clt, nom_clt);
		m_clients.front()->add_product(return_product(title));
	}
	int a =m_clients.size();
	for (int i=0; i<a; i++)
		if(m_clients.at(i)->getNom() == nom_clt)
			m_clients.at(i)->add_product(return_product(title));
	std::cout<<" Product add to cart. "<<std::endl;
}

void Magasin::add_product_clt(std::string title, int id_clt){
	if (m_clients.empty()){
		std::cout<<" No client id :#"<< id_clt <<std::endl;
	}
	int a = m_clients.size();
	for (int i=0; i<a; i++)
		if(m_clients.at(i)->getUid() == id_clt)
			m_clients.at(i)->add_product(return_product(title));
	std::cout<<" Product add to cart. "<<std::endl;
}

void Magasin::del_product_clt(std::string& title,std::string& prenom_clt, std::string& nom_clt){
	if (m_clients.empty())
		std::cout<<" Nothing to do."<<std::endl;
	else {
		int a = m_clients.size();
		for (int i=0; i<a; i++)
			if (m_clients.at(i)->getNom() == nom_clt && m_clients.at(i)->getPrenom() == prenom_clt)
				m_clients.at(i)->del_product(title);
	}		
}

void Magasin::qtt_product_clt(std::string& title, std::string& prenom_clt, std::string& nom_clt, int new_qtt){
	if (m_clients.empty())
		std::cout<<" Nothing to do. "<<std::endl;
	else {
		int a = m_clients.size();
		for (int i=0; i<a; i++)
			if (m_clients.at(i)->getNom() == nom_clt && m_clients.at(i)->getPrenom() == prenom_clt)
				m_clients.at(i)->modify_product(title, new_qtt);	
	}
}
