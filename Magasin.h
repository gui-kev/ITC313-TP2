
#ifndef _magasin_h
#define _magasin_h

#include <vector>
#include "Product.h"
#include "Client.h"
#include "Commande.h"

class Magasin
{
public:
	Magasin();
	~Magasin(); //destructor
	void add_product(std::string title, std::string desc, int qtt, float price); 	// permet d'ajouter un produit au magasin
	void display_product();									//affiche tous les produits du magasin
	void display_select_product(std::string title);				// display_select_product: permet d'afficher un produit sélectionné
	void update_product_quantity(std::string title, int qtt);		//met à jour la quantité d'un produit 
	void add_client(std::string nom, std::string prenom);	//ajoute un client au magasin
	void display_client();									// affiche tous les clients du magasin
	void display_select_clt(std::string nom, std::string prenom); 				//affiche un client à partir de son nom ou de son identifiant
	void display_select_clt(int id);
	void add_product_clt(std::string title, std::string nom_clt, std::string prenom_clt);	//méthode permettant d'ajouter un produit au panier d'achat d'un client
	void add_product_clt(std::string title, int id_clt);
	void del_product_clt(std::string& title, std::string& prenom_clt, std::string& nom_clt); 						//méthode permettant de supprimer un produit au panier d'achat d'un client
	void qtt_product_clt(std::string& title, std::string& prenom_clt, std::string& nom_clt, int new_qtt);		//permet de modifier la quantité d'un produit du panier
	Product* return_product(std::string& title); 			//permet de renvoyer pour l'ajouter au panier d'un client
	void valide_commande(int id); 		//permet de valider une commande
	void statut_commande(int id_com); // permet de modifier le statut d'une commande (livrée ou pas)
	void display_orders();
	void display_orders_clt(int id_clt); //permet d'afficher toutes les commandes d'un client donné

private:
	std::vector<Product*> m_products;
	std::vector<Client*> m_clients;
	std::vector<Commande*> m_orders;	
};

#endif