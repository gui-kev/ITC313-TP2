#include <string>
#include <iostream>
#include "Commande.h" 

// 
Commande::Commande(int uid, Client* clt, std::vector<Product*> products, bool status) : m_uid(uid) {
	m_client = clt;
	m_products = products;
	m_status = status;
}



std::ostream &operator << (std::ostream& output, Commande& order){
	output<< "ID Order : " << order.m_uid << " -  Nom client : " << order.m_client->getNom()
			 << " -  ID client : " <<order.m_client->getUid() << " -  Status : " << order.m_status 
			 << " -  Products : ";
	int a = order.m_products.size(); 
	if (a>0)	
		for (int i=0; i<a; i++)
			std::cout<< *order.m_products.at(i)<<std::endl;
	return output;
}
