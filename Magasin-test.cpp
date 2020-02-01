
#include <iostream>
#include <vector>
#include "Magasin.h"

int main(){	
	Magasin my_easystore;

	// Add new clients
	my_easystore.add_client("Dominique", "Ginhac");
	my_easystore.add_client("Bill", "Gates");
	my_easystore.add_client("Richard", "Stallman");
	my_easystore.add_client("Alan", "Turing");
	my_easystore.add_client("Steve", "Jobs");

	// Add products to the store with Title, Description, Price and Quantity
	my_easystore.add_product("PS4","Console de jeu Sony", 10,249.99);
	my_easystore.add_product("Switch", "Console de jeu Nintendo", 30, 299.99);
	my_easystore.add_product("Xbox one", "Console de jeu Microsoft", 15, 179.99);

	// Products registration
	//my_easystore.writeProduct("product");

	std::string rep ="";
	do{
		system("clear");
		char choix0 = '0';
		std::cout <<"------------👋👋👋 BIENVENU SUR CETTE MERVEILLEUSE APPLI DE GESTION DE MAGASIN ( EASYSTORE )👋👋👋----------- "<< std::endl;
		std::cout <<"Vous etes gestionnaire (1) ou client (2) ?  "; // << std::endl;
		do {
			std::cout <<" Choix : ";
			std::cin >> choix0;
		} while(choix0 != '1' && choix0 !='2');
		std::cout << std::endl;

		if(choix0 == '1'){
			int choix =0;
			std::cout << " ___________________________________________________________ " << std::endl
					  << "|__________________________ Menu ___________________________|" << std::endl
					  << "| 1. gestion du magasin                                     |" << std::endl
					  << "| 2. gestion des clients                                    |" << std::endl
					  << "| 3. gestion des commandes                                  |" << std::endl
					  << "| 0. Quitter                                                |" << std::endl 
					  << "|___________________________________________________________|" << std::endl
					  << "Choix : ";
			std::cin >> choix;
			std::cout << std::endl;

			if (choix == 0)
				std::cout << "	Good Bye" << std::endl;
			else {
				if (choix == 1){ //gestion du magasin
					int choix1 = 0;
					std::cout << " ___________________________________________________________ " << std::endl
							  << "|Souhaitez vous :                                           |" << std::endl
							  << "| 1. Ajout d'un produit au magasin                          |" << std::endl
							  << "| 2. modifier la quantité d'un produit                      |" << std::endl
							  << "| 0. Quitter                                                |" << std::endl 
							  << "|___________________________________________________________|" << std::endl
							  << "	Choix : ";
					std::cin >> choix1;
					std::cout << std::endl;
					std::string rep1 ="";
					std::string title, desc;
					int qtt = 0; int price =0;
					switch(choix1){	
						case 0 : break;
								
						case 1 :
							do {
								std::cout<<"veillez entrer les informations du produit : "<<std::endl;
								std::cout <<"Title : ";
								std::cin>>title;
								std::cout<<"Description : ";
								std::cin>>desc;
								std::cout<<"Quantité : ";
								std::cin>>qtt;
								std::cout<<"Price : ";
								std::cin>>price;
								my_easystore.add_product(title,desc,qtt,price);
								std::cout << "Voulez-vous ajouter un autre produit ? (o/n) : "; 
								std::cin >> rep1;
							} while(rep1 == "O" || rep1 == "o" || rep1 == "OUI" || rep1 == "oui");
							break;
						case 2 :
							do {
								std::cout<<"Titre du produit : ";
								std::cin>>title;
								std::cout<<"Quantité : ";
								std::cin>>qtt;
								my_easystore.update_product_quantity(title,qtt);
								std::cout << "Voulez-vous modifier la quantité d'un autre produit ? (o/n) : ";
								std::cin >> rep1;
							} while(rep1 == "O" || rep1 == "o" || rep1 == "OUI" || rep1 == "oui");
							break;	
					}
				}

				if (choix == 2){ //gestion des clients
					int choix2 = 0;
					int id =0;
					std::string nom, prenom;
					std::string rep2 = "";
					std::cout << "	 ___________________________________________________________ " << std::endl
							  << "	| 1. Ajout d'un client au magasin                           |" << std::endl
							  << "	| 2. Afficher la liste des client du magasin                |" << std::endl
							  << "	| 3. Afficher les informations sur d'un client              |" << std::endl
							  << "	| 0. Quitter                                                |" << std::endl 
							  << "	|___________________________________________________________|" << std::endl
							  << "	Choix : ";
					std::cin >> choix2;
					std::cout << std::endl;
					switch(choix2){	
						case 0 : break;
						 
						case 1 :
							do{
								std::cout<<" Nom du client : ";
								std::cin>>nom;
								std::cout<<" Prenom du client : ";
								std::cin>>prenom;
								my_easystore.add_client(nom,prenom);
								std::cout << "Voulez-vous ajouter un autre client ? (o/n) : "; 
							} while(rep2 == "O" || rep2 == "o" || rep2 == "OUI" || rep2 == "oui");
							break;

						case 2 :
							my_easystore.display_client();
							break;

						case 3 :
							std::cout <<"A partir de son identifiant (o/n) ? : ";
							std::cin >> rep2;
							if (rep2 == "O" || rep2 == "o" || rep2 == "OUI" || rep2 == "oui"){
								std::cout << "Tapez son ID : ";
								std::cin >> id;
								my_easystore.display_select_clt(id);
							}
							else{
								std::cout<<" Nom du client : ";
								std::cin>>nom;
								std::cout<<" Prenom du client : ";
								std::cin>>prenom;
								my_easystore.display_select_clt(nom,prenom);
							}
							break;
					}
				}

				if(choix == 3){ //gestion des commandes
					int choix3 = 0;
					int id_statut = 0;
					std::cout << "	 ___________________________________________________________ " << std::endl
							  << "	| 1. Modifier le statut  d'une commande                     |" << std::endl
							  << "	| 2. Lister les commandes                                   |" << std::endl
							  << "	| 0. Quitter                                                |" << std::endl 
							  << "	|___________________________________________________________|" << std::endl
							  << "	Choix : ";
					std::cin >> choix3;
					std::cout << std::endl;
					switch(choix3){	
						case 0 : break;
			
						case 1 :
							std::cout<<"Entrez l'identifiant de la commande : ";
							std::cin>>id_statut;
							my_easystore.statut_commande(id_statut);
		       				break;

		       			case 2 : 
							my_easystore.display_orders();
							break;
					}
				}
			}
		}

		if (choix0 == '2'){
			std::string nom, prenom, titleProduct;
			int choix4 = 0;
			int newqtt = 0;
			std::cout<<"Entrez votre nom : ";
			std::cin>> nom;
			std::cout<<"Entrez le prenom : ";
			std::cin>> prenom;
			Client *c = my_easystore.return_client(nom, prenom);
			if (c == nullptr)
				my_easystore.add_client(nom,prenom);
			std::cout<<"voici la liste de nos produits"<<std::endl;
			my_easystore.display_product();
			std::cout << " ___________________________________________________________ " << std::endl
		        	  << "|Souhaitez vous :                                           |" << std::endl
		        	  << "| 1. Ajouter un produit a mon panier                        |" << std::endl
					  << "| 2. supprimer un produit du panier                         |" << std::endl
					  << "| 3. Modifier la quantité d'un produit                      |" << std::endl
					  << "| 4. Valider ma commande                                    |" << std::endl
					  << "| 0. Quitter                                                |" << std::endl 
					  << "|___________________________________________________________|" << std::endl
					  << "Choix : ";
			std::cin >> choix4;
			std::cout << std::endl;
			switch(choix4){	
				case 0 : break;
	 
				case 1 :
					std::cout << "Entrez le titre du produit desiré : ";
					std::cin >> titleProduct;
					my_easystore.add_product_clt(titleProduct, c->getUid());
					break;

				case 2 : 
					std::cout<<"Entrez le titre du produit que vous desirez supprimer ";
					std::cin>>titleProduct;
					my_easystore.del_product_clt(titleProduct, nom, prenom);
					break;

				case 3 :
					std::cout<<"Entrez le titre du produit que vous desirez modifier : ";
					std::cin>>titleProduct;
					std::cout<<"Entrez la nouvelle quantité : ";
					std::cin>>newqtt;
					my_easystore.qtt_product_clt(titleProduct, nom, prenom, newqtt);
					break;

				case 4 :
					my_easystore.valide_commande(c->getUid());
					break;
			}
		}

		std::cout << "Voulez-vous enregistrer les modifications ? (o/n) : ";
		std::cin >> rep;
	} while(rep == "N" || rep == "n" || rep == "NON" || rep == "non");

	//my_easystore.readProduct("product");
	std::cout<<" Run ok "<<std::endl;

	return 0;
}