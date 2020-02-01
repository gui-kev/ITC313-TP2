
#include <iostream>
#include "Magasin.h"

//créer un objet vide de type magasin
Magasin::Magasin(){}

//destructor
Magasin::~Magasin(){
	int a = m_clients.size();
	int b = m_products.size();
	int c = m_orders.size();
	for (int i = 0; i < a; i++){
		delete m_clients.at(i);
		m_clients.at(i) = nullptr;
	}
	for (int i = 0; i < b; i++){
		delete m_products.at(i);	
		m_products.at(i) = nullptr;
	}
	for (int i = 0; i < c; i++){
		delete m_orders.at(i);	
		m_orders.at(i) = nullptr;
	}
	std::cout << std::endl << "	😈😈Destructor😈😈" << std::endl;
	std::cout << "	Cool 😜 😜 😜 cool " << std::endl;
}

// Ajouter un nouveau produit au magasin
void Magasin::add_product(std::string title, std::string desc, int qtt, float price){
	Product* p = new Product(title, desc, qtt, price);
	m_products.push_back(p);
	//std::cout<<" Product add. "<<std::endl;
}


// Afficher à lécran tous les produits du magasin
void Magasin::display_product(){
	std::cout <<" ___________________________________________________________________________________ " << std::endl
			  <<"|  Products                                                                         |" << std::endl
			  <<" ___________________________________________________________________________________ " << std::endl
			  <<"| Title               Description                             Quantity    Price     |" << std::endl;
	int a = m_products.size();
	for (int i=0; i<a; i++){
		std::cout<< *m_products.at(i)<<std::endl;
	}
	std::cout <<" ___________________________________________________________________________________ " << std::endl;
}

// Afficher un produit à partir de son nom 
void Magasin::display_select_product(std::string title){
	if (m_products.empty())
			std::cout<<" No Product."<<std::endl;
	else{
		int a = m_products.size();
		Product* p = nullptr;
		for (int i=0; i<a; i++){
			if (title.compare(m_products.at(i)->getTitle()) == 1)
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
			if (title.compare(m_products.at(i)->getTitle())==1)
				m_products.at(i)->setQtt(new_qtt);
		}
	}
}

// Ajout d'un client au magasin
void Magasin::add_client(std::string nom, std::string prenom){
	static int count = 0;
	int id = count++;
	std::vector<Product* > panier;
	Client* c = new Client(id, prenom, nom, panier);
	m_clients.push_back(c);
}

// Afficher à l'écran tous les clients du magasin
void Magasin::display_client(){
	int a = m_clients.size();

	std::cout <<" ___________________________________________________________________________________ " << std::endl
		  	  <<"|  Clients                                                                          |" << std::endl
		 	  <<" ___________________________________________________________________________________ " << std::endl
			  <<"| Uid	Identity  " << std::endl;
	for (int i=0; i<a; i++){
		std::cout<< "| "<< m_clients.at(i)->getUid() <<" 	"<< m_clients.at(i)->getNom() <<" "<< m_clients.at(i)->getPrenom() << std::endl;	
	}
	std::cout <<" ___________________________________________________________________________________ " << std::endl;
}

// Afficher un client à partir de son nom, prénom
void Magasin::display_select_clt(std::string nom, std::string prenom){
	if (m_clients.empty())
		std::cout<<" No client named : "<< nom <<std::endl;
	else {
		int a = m_clients.size();
		Client* c = nullptr;
		for (int i=0; i<a; i++){
			if(nom.compare(m_clients.at(i)->getNom())==1 || prenom.compare(m_clients.at(i)->getPrenom())==1)
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
			if (title.compare( m_products.at(i)->getTitle())==1)
				p = m_products.at(i);
		return p;
	}
}

// Ajoute un produit au panier d'un client sélectionné à partir de son nom
void Magasin::add_product_clt(std::string title, std::string& nom_clt, std::string& prenom_clt){
	if (m_clients.empty()){
		add_client(prenom_clt, nom_clt); // ajout du client
		m_clients.front()->add_product(return_product(title)); // ajout du produit sélectionner par son titre au panier du client  
	}
	int a =m_clients.size();
	for (int i=0; i<a; i++)
		if(nom_clt.compare(m_clients.at(i)->getNom())==1){
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
void Magasin::del_product_clt(std::string& title,std::string& nom_clt, std::string& prenom_clt){
	if (m_clients.empty())
		std::cout<<" No product to delete."<<std::endl;
	else {
		int a = m_clients.size();
		for (int i=0; i<a; i++)
			if (nom_clt.compare(m_clients.at(i)->getNom()) == 1 && prenom_clt.compare(m_clients.at(i)->getPrenom()) == 1)
				m_clients.at(i)->del_product(title);
		std::cout << "Deletion of the product "<< title << "from cart. " << std::endl;
	}		
}

// modifier la quantiter de produit du panier d'un client
void Magasin::qtt_product_clt(std::string& title, std::string& nom_clt, std::string& prenom_clt, int new_qtt){
	if (m_clients.empty())
		std::cout<<" Nothing to do. "<<std::endl;
	else {
		int a = m_clients.size();
		for (int i=0; i<a; i++)
			if (nom_clt.compare(m_clients.at(i)->getNom()) == 1 && prenom_clt.compare(m_clients.at(i)->getPrenom()) == 1)
				m_clients.at(i)->modify_product(title, new_qtt);	
	}
}

// validation d'une commande
void Magasin::valide_commande(int id_clt){
	static int count2 = 0;
	int id = count2++;
	int a = 0;
	std::cout << "Voulez-vous valider la Commande (1 pour oui / 0 pour non) : ";
	std::cin >> a;
	if (a == 1){
		Commande* order = new Commande(id); // clt);
		int b = m_clients.size();
		for (int i=0; i < b ; i++){
			if (m_clients.at(i)->getUid() == id_clt){
				order->setProduct(m_clients.at(i)->getPanier()); //copie du contenu du panier dans les produits de la commande 
				order->setClient(m_clients.at(i));
				order->setStatus(false);
				m_clients.at(i)->clear_panier(); // Vidange du panier du client
			}
		}
		m_orders.push_back(order);
		std::cout << "Commande éffectuée. "<< std::endl;
	}
}

// mise à jour le statut d'une commande
void Magasin::statut_commande(int id_com){
	int a = 0;
	int b = m_orders.size();
	std::cout << " La commande a été livrée (1 pour oui / 0 pour non) :  ";
	std::cin >> a;
	if (a == 1)
		for (int i=0; i < b; i++){
			if(m_orders.at(i)->getUid() == id_com)
				m_orders.at(i)->setStatus(true);
		}
}

//Affichage à l'écran de toutes les commandes passées
void Magasin::display_orders(){
	int b = m_orders.size();
	if(b > 0)
		for (int i=0; i < b; i++)
			std::cout << *m_orders.at(i);
}

// affichage des commandes d'un client donné
void Magasin::display_orders_clt(int id_clt){
	int b = m_orders.size();
	for (int i=0; i < b ; i++){
		Client* clt = m_orders.at(i)->getClient();
		if ( clt->getUid() == id_clt)
			std::cout <<  *clt << std::endl;
	}
}

Client* Magasin::return_client(std::string nom, std::string prenom){
	Client *c = nullptr;
	if (!m_clients.empty()){
		int a = m_clients.size();
		for (int i=0; i<a; i++){
			if(nom.compare(m_clients.at(i)->getNom()) == 1 || prenom.compare(m_clients.at(i)->getPrenom()) == 1)
				c = m_clients.at(i);
		}
	}
	return c;
}

