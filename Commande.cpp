#include <string>
#include <iostream>
#include "Commande.h" 

// 
Commande::Commande(int uid): m_uid(uid) {}

int Commande::getUid() const {
	return m_uid;
}

Client* Commande::getClient() const{
	return m_client;
}

void Commande::setClient(Client* c){
	m_client = c;
}

void Commande::setProduct(std::vector<Product*> p) {
	int a = p.size();
//	if (p != nullptr)
//		m_products_order.push_back(p);
	for(int i = 0; i < a; i++)
		m_products_order.push_back(p.at(i));
}

void Commande::setStatus(bool s){
		m_status = s;
}

std::ostream &operator << (std::ostream& output, Commande& order){
	output<< "ID Order : " << order.m_uid << " -  Nom client : " << order.m_client->getNom()
			 << " -  ID client : " <<order.m_client->getUid() << " -  Status : " << order.m_status 
			 << " -  Products : ";
	int a = order.m_products_order.size(); 
	if (a>0)	
		for (int i=0; i<a; i++)
			std::cout<< *order.m_products_order.at(i)<<std::endl;
	return output;
}
