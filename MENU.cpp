#include <iostream>
#include <vector>
#include "Magasin.h"


using namespace std;


int main()
{
	
	Magasin my_easystore;
	std::string desc, title, nom, prenom, titre, titleProduct ;
	int price, qtt, new_qtt, id, id_statut, newqtt ;

	int choix, choix1, choix2, choix3, choix4, choix5;

	std::cout<<"------------👋👋👋 BIENVENU SUR CETTE MERVEILLEUSE APPLI DE GESTION DE MAGASIN ( my_easystore )👋👋👋----------- "<<std::endl;

	std::cout<<"Vous etes gestionnaire (1) ou client (2) "<<std::endl;
	std::cin>>choix;
	        std::cout << " ___________________________________________________________ " << std::endl
	        	 << "|__________________________ Menu ___________________________|" << std::endl
	        	 << "| 1. GESTIONNAIRE                                           |" << std::endl
				 << "| 2. CLIENT                                                 |" << std::endl
				 << "| 0. Quitter                                                |" << std::endl 
				 << "|___________________________________________________________|" << std::endl
				 << "Choix : ";
	        std::cin >> choix;
	        std::cout << std::endl;
	switch(choix)
    {	
    	case 0 : break;

		case 1 : //CAS DU GESTIONNAIRE
			std::cout << " ___________________________________________________________ " << std::endl
				 << "|__________________________ Menu ___________________________|" << std::endl
				 << "| 1. gestion du magasin                                     |" << std::endl
				 << "| 2. gestion des utilisateurs                               |" << std::endl
				 << "| 3. gestion des commandes                                  |" << std::endl
				 << "| 0. Quitter                                                |" << std::endl 
				 << "|___________________________________________________________|" << std::endl
				 << "Choix : ";
			std::cin >> choix1;
			std::cout << std::endl;
			switch(choix1)
				{	
					case 0 : break;
			
					case 1 : 
				        std::cout << " ___________________________________________________________ " << std::endl
				        	 << "|__________________________ Menu ___________________________|" << std::endl
				        	 << "| 1. Ajout d'un produit au magasin                          |" << std::endl
							 << "| 2. modifier la quantité d'un produit                      |" << std::endl
							 << "| 0. Quitter                                                |" << std::endl 
							 << "|___________________________________________________________|" << std::endl
							 << "Choix : ";
				        std::cin >> choix2;
				        std::cout << std::endl;
						switch(choix2)
					        {	
						       	case 0 : break;
						 
								case 1 :
									std::cout<<"veillez entrer les informations du produit : "<<std::endl;
									std::cout <<"Title : ";
									std::cin>>title;
									std::cout<<"Description : "<<std::endl;
									std::cin>>desc;
									std::cout<<"Quantité : "<<std::endl;
									std::cin>>qtt;
									std::cout<<"Price : "<<std::endl;
									std::cin>>price;
									my_easystore.add_product(title,desc,qtt,price);
				            		choix2 = 0;
				            		break;
								case 2 :
						           	std::cout<<"Titre du produit : "<<std::endl;
						           	std::cin>>title;
						          	std::cout<<"Quantité : "<<std::endl;
						          	std::cin>>new_qtt;
						           	my_easystore.update_product_quantity(title,new_qtt);
					             	choix2 =0;
					             	break;
								/*case 3 :
						           	std::cout<<"entrez le titre du produit que vous desirez ajouter"<<std::endl;
					            	std::cin>>title;
						           	std::cout<<"entrez l'identifiant du client"<<std::endl;
					             	std::cin>>id;
									my_easystore.add_product_clt(title,id);
				            		choix = 0;
				            		break;*/
							}

			 		//gestion des utilisateurs 			
					case 2 : 
				        std::cout << " ___________________________________________________________ " << std::endl
				        	 << "|__________________________ Menu ___________________________|" << std::endl
				        	 << "| 1. Ajout d'un utilisateur au magasin                      |" << std::endl
							 << "| 2. Afficher la liste des client du magasin                |" << std::endl
							 << "| 3. Afficher les informations sur d'un client              |" << std::endl
							 << "| 0. Quitter                                                |" << std::endl 
							 << "|___________________________________________________________|" << std::endl
							 << "Choix : ";
				        std::cin >> choix3;
				        std::cout << std::endl;
						switch(choix3)
				    	{	
				        	case 0 : break;
				 
							case 1 :
								std::cout<<"entrez le nom du client que vous souhaitez ajouter à votre magasin"<<std::endl;
								std::cin>>nom;
								std::cout<<"entrez le prenom du client que vous souhaitez ajouter à votre magasin"<<std::endl;
								std::cin>>prenom;
								my_easystore.add_client(nom,prenom);
								choix3 = 0;
								break;

							case 2 :

								my_easystore.display_client();
								choix3 = 0;
								break;

							case 3 :
								std::cout<<"entrez le nom du client que vous souhaitez ajouter à votre magasin"<<std::endl;
								std::cin>>nom;
								std::cout<<"entrez le prenom du client que vous souhaitez ajouter à votre magasin"<<std::endl;
								std::cin>>prenom;
								my_easystore.display_select_clt(nom,prenom);
								choix3 = 0;
								break;
						}

						//gestion des commandes
						case 3 : 
					        std::cout << " ___________________________________________________________ " << std::endl
					        	 << "|__________________________ Menu ___________________________|" << std::endl
					        	 << "| 1. modifier le statut  d'une commande                     |" << std::endl
								 << "| 2. lister les commandes                                   |" << std::endl
								 << "| 0. Quitter                                                |" << std::endl 
								 << "|___________________________________________________________|" << std::endl
								 << "Choix : ";
					        std::cin >> choix4;
					        std::cout << std::endl;
							switch(choix4)
				        	{	
					        	case 0 : break;
					 
								case 1 :
										std::cout<<"entrez l'identifiant de la commande"<<std::endl;
										std::cin>>id_statut;
										my_easystore.statut_commande(id_statut);
										choix4 = 0;
				       					break;

				       			case 2 : 
				       					my_easystore.display_orders();
				       					choix4 = 0;
				       					break;
							}
				choix1 = 0;
			   	break;
				}

		case 2 : 
			//CAS DU CLIENT
			std::cout<<"Entrez votre nom"<<std::endl;
			std::cin>> nom;
			std::cout<<"Entrez le prenom"<<std::endl;
			std::cin>> prenom; 
			std::cout<<"Entrez votre identifiant"<<std::endl;
			std::cin>> id;
			Client client(id,nom,prenom);
			std::cout<<"voici la liste de nos produits"<<std::endl;
			my_easystore.display_orders();

		        std::cout << " ___________________________________________________________ " << std::endl
		        	 << "|__________________________ Menu ___________________________|" << std::endl
		        	 << "| 1. Ajouter un produit a mon panier                        |" << std::endl
					 << "| 2. supprimer un produit du panier                         |" << std::endl
					 << "| 3. Modifier la quantité d'un produit                      |" << std::endl
					 << "| 4. Valider ma commande                                    |" << std::endl
					 << "| 0. Quitter                                                |" << std::endl 
					 << "|___________________________________________________________|" << std::endl
					 << "Choix : ";
		        std::cin >> choix5;
		        std::cout << std::endl;
						switch(choix5)
			        	{	
							case 0 : break;
				 
							case 1 :
								std::cout<<"entrez le titre du produit desiré"<<std::endl;
								std::cin>>titre;
								client.add_product(titleProduct) ;	
								choix5 = 0;
								break;

							case 2 : 
								std::cout<<"entrez le titre du produit que vous desirez supprimer"<<std::endl;
								std::cin>>titre;
								client.del_product(titre);
								choix5 =0;
								break;

							case 3 :
								std::cout<<"entrez le titre du produit que vous desirez modifier"<<std::endl;
								std::cin>>titleProduct;
								std::cout<<"entrez la nouvelle quantité"<<std::endl;
								std::cin>>newqtt;
								client.modify_product(titleProduct,newqtt);
								choix5 =0;
								break;

							case 4 :
								std::cout<<"Entrez votre identifiant"<<std::endl;
								std::cin>> id;
								my_easystore.valide_commande(id);
								choix5 =0;
								break;

						}
					choix =0;
					break;
	}			 

	/*// Display all the clients
	std::cout << std::endl << "__________Tous les clients__________"<< std::endl;
	my_easystore.display_client();

	// Display clients "Richard Stalman" and 4
	std::cout << std::endl << "__________ Affichege d'un client à partir de son nom __________"<< std::endl;
	my_easystore.display_select_clt("Richard", "Stallman");
	std::cout << std::endl << "__________ Affichege d'un client à partir de son id __________"<< std::endl;
	my_easystore.display_select_clt(2);

	

	// Add a product with its title and add to a client identified by his name	
	std::cout << std::endl << "__________ Commande éfectuée par un client __________"<< std::endl;
	my_easystore.add_product_clt("Casque RV PS", "Richard", "Stallman");

	// Add a product with its title and add to a client identified by his uid
	my_easystore.add_product_clt("Casque Audio", 4);

	//validates the customer's order
	std::cout << std::endl << "__________ Validation d'une commande __________"<< std::endl;
	my_easystore.valide_commande(4);

	//changes the order status
	my_easystore.statut_commande(1);

	//display all orders
	std::cout << std::endl << "__________ Toutes les commandes __________"<< std::endl;
	my_easystore.display_orders();

	// Display all the products
	my_easystore.display_product();

	// Update quantity of a product
	std::cout << std::endl << "__________ Mise à jour de la quantité du produit Switch __________"<< std::endl;
	my_easystore.update_product_quantity("Switch", 20);

	// Display the updated product
	my_easystore.display_select_product("Switch");

	std::string a = "Kaspersky";
	my_easystore.display_select_product(a);*/

	return 0;
}