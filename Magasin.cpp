
#include <iostream>
#include "Magasin.h"

//créer un objet vide de type magasin
Magasin::Magasin(){}

//destructor
Magasin::~Magasin(){
	int a = m_clients.size();
	int b = m_products.size();
	for (int i = 0; i < a; i++){
		delete m_clients.at(i);
		m_clients.at(i) = nullptr;
	}
	for (int i = 0; i < b; i++){
		delete m_products.at(i);	
		m_products.at(i) = nullptr;
	}

	std::cout << std::endl << "	Cool 😜 😜 😜 cool " << std::endl;
	std::cout << "🤔🤔🤔 je te laisse la QUESTION 8" << std::endl;
}

// Ajouter un nouveau produit au magasin
void Magasin::add_product(std::string title, std::string desc, int qtt, float price){
	Product* p = new Product(title, desc, qtt, price);
	m_products.push_back(p);
	std::cout<<" Product add. "<<std::endl;
}


// Afficher à lécran tous les produits du magasin
void Magasin::display_product(){
	int a = m_products.size();
	for (int i=0; i<a; i++){
		std::cout<< *m_products.at(i)<<std::endl;
	}
}

// Afficher un produit à partir de son nom 
void Magasin::display_select_product(std::string title){
	if (m_products.empty())
			std::cout<<" No Product."<<std::endl;
	else{
		int a = m_products.size();
		Product* p = nullptr;
		for (int i=0; i<a; i++){
			if (title == m_products.at(i)->getTitle())
				p = m_products.at(i);
		}
		if (p != nullptr)
			std::cout<< *p <<std::endl;
		else 
			std::cout << "No product : " << title << std::endl;
	}
}

// Mettre à jour la quantité d'un produit à partir de son nom
void Magasin::update_product_quantity(std::string title, int new_qtt){
	if (m_products.empty())
		std::cout<<"No product to update."<<std::endl;
	else{
		int a = m_products.size();
		for (int i=0; i<a; i++){
			if (title == m_products.at(i)->getTitle())
				m_products.at(i)->setQtt(new_qtt);
		}
	}
}

// Ajout d'un client au magasin
void Magasin::add_client(std::string nom, std::string prenom){
	static int count = 0;
	int id = count++;
	std::vector<Product* > panier;
	Client* c = new Client(id, nom, prenom, panier);
	m_clients.push_back(c);
}

// Afficher à l'écran tous les clients du magasin
void Magasin::display_client(){
	int a = m_clients.size();
	for (int i=0; i<a; i++)
		std::cout<< *m_clients.at(i)<<std::endl;
}

// Afficher un client à partir de son nom, prénom
void Magasin::display_select_clt(std::string nom, std::string prenom){
	if (m_clients.empty())
		std::cout<<" No client named : "<< nom <<std::endl;
	else {
		int a = m_clients.size();
		Client* c = nullptr;
		for (int i=0; i<a; i++){
			if(nom == m_clients.at(i)->getNom() || prenom == m_clients.at(i)->getPrenom())
				c = m_clients.at(i);
		}
		if(c == nullptr) std::cout<<" No client named : "<< nom <<std::endl;
		else 	std::cout<<" Display client - "<< *c <<std::endl;
	}
}

// Afficher un client à partir de son identifiant
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
		else std::cout<< " Display client - "<<*c <<std::endl;
	}
}

// retourne un produit à partir de son titre
Product* Magasin::return_product(std::string& title){
	Product* p = nullptr;
	if (m_products.empty()){
		std::cout<<" No product to return. "<<std::endl;
		return p;
	}
	else {
		int a = m_products.size();
		for (int i=0; i<a; i++)
			if (title == m_products.at(i)->getTitle())
				p = m_products.at(i);
		return p;
	}
}

// Ajoute un produit au panier d'un client sélectionné à partir de son nom
void Magasin::add_product_clt(std::string title, std::string prenom_clt, std::string nom_clt){
	if (m_clients.empty()){
		add_client(prenom_clt, nom_clt); // ajout du client
		m_clients.front()->add_product(return_product(title)); // ajout du produit sélectionner par son titre au panier du client  
	}
	int a =m_clients.size();
	for (int i=0; i<a; i++)
		if(m_clients.at(i)->getNom() == nom_clt){
			if (return_product(title) != nullptr){
				m_clients.at(i)->add_product(return_product(title));
				std::cout<<" Adding product " << title << " to cart of " << nom_clt << std::endl;
			}
			else 
				std::cout << "No product "<< title << std::endl;
		}
}

// Ajoute un produit au panier d'un client sélectionné à partir de son identifiant
void Magasin::add_product_clt(std::string title, int id_clt){
	if (m_clients.empty()){
		std::cout<<" No client id :#"<< id_clt <<std::endl;
	}
	int a = m_clients.size();
	for (int i=0; i<a; i++)
		if(m_clients.at(i)->getUid() == id_clt){
			if (return_product(title) != nullptr){
				m_clients.at(i)->add_product(return_product(title));
				std::cout<<" Adding product "<< title <<" to cart of client"<< id_clt << std::endl;
			}
			else 
				std::cout << "No product "<< title << std::endl;
		}
}

// supprimer un produit du panier d'un client 
void Magasin::del_product_clt(std::string& title,std::string& prenom_clt, std::string& nom_clt){
	if (m_clients.empty())
		std::cout<<" No product to delete."<<std::endl;
	else {
		int a = m_clients.size();
		for (int i=0; i<a; i++)
			if (m_clients.at(i)->getNom() == nom_clt && m_clients.at(i)->getPrenom() == prenom_clt)
				m_clients.at(i)->del_product(title);
		std::cout << "Deletion of the product "<< title << "from cart. " << std::endl;
	}		
}

// modifier la quantiter de produit du panier d'un client
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
