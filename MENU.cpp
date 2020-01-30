#include <iostream>
#include <vector>
#include "Magasin.h"


using namespace std;


int main()
{
	
	Magasin easystore;
	int choix=0;

	cout<<"------------👋👋👋 BIENVENU SUR CETTE MERVEILLEUSE APPLI DE GESTION DE MAGASIN ( EASYSTORE )👋👋👋----------- "<<endl;

	cout<<"Vous etes gestionnaire (1) ou client (2) "<<endl;
	cin>>choix;
	        cout << " ___________________________________________________________ " << endl
	        	 << "|__________________________ Menu ___________________________|" << endl
	        	 << "| 1. GESTIONNAIRE                                           |" << endl
				 << "| 2. CLIENT                                                 |" << endl
				 << "| 0. Quitter                                                |" << endl 
				 << "|___________________________________________________________|" << endl
				 << "Choix : ";
	        cin >> choix;
	        cout << endl;
	switch(choix)
	        {	
	        	case 0 : break;
	 
				case 1 : //CAS DU GESTIONNAIRE
				

						int choix=0;
						        cout << " ___________________________________________________________ " << endl
						        	 << "|__________________________ Menu ___________________________|" << endl
						        	 << "| 1. gestion du magasin                                     |" << endl
									 << "| 2. gestion des utilisateurs                               |" << endl
									 << "| 3. gestion des commandes                                  |" << endl
									 << "| 0. Quitter                                                |" << endl 
									 << "|___________________________________________________________|" << endl
									 << "Choix : ";
						        cin >> choix;
						        cout << endl;
						switch(choix)
						        {	
						        	case 0 : break;
						 
									case 1 : 									
									
										int choix=0;
								        cout << " ___________________________________________________________ " << endl
								        	 << "|__________________________ Menu ___________________________|" << endl
								        	 << "| 1. Ajout d'un produit au magasin                          |" << endl
											 << "| 2. modifier la quantité d'un produit                      |" << endl
											 << "| 0. Quitter                                                |" << endl 
											 << "|___________________________________________________________|" << endl
											 << "Choix : ";
								        cin >> choix;
								        cout << endl;
										switch(choix)
									        	{	
									        	case 0 : break;
									 
												case 1 :
												string desc;
												string title;
												int price,qtt;
													cout<<"veillez entrer les informations du produit : "<<endl;
													cout <<"Title : ";
													cin>>title;
													cout<<"Description : "<<endl;
													cin>>desc;
													cout<<"Quantité : "<<endl;
													cin>>qtt;
													cout<<"Price : "<<endl;
													cin>>price;
													easystore.add_product(title,desc,qtt,price);
								            		choix = 0;
								            		break;

									            case 2 :
									            	  
									            	int new_qtt;
									            	cout<<"Titre du produit : "<<endl;
									             	cin>>title;
									             	cout<<"Quantité : "<<endl;
									             	cin>>new_qtt;
									             	easystore.update_product_quantity(title,new_qtt);
									             	choix=0;
									             	break;

												case 3 :
													string title;  
									            	int id;
									            	cout<<"entrez le titre du produit que vous desirez ajouter"<<endl;
									             	cin>>title;
									             	cout<<"entrez l'identifiant du client"<<endl;
									             	cin>>id;
													easystore.add_product_clt(title,id);

								            		choix = 0;
								            		break;


								            		}//gestion des utilisateurs
						 			
						 			case 2 : 
								 			int choix=0;
									        cout << " ___________________________________________________________ " << endl
									        	 << "|__________________________ Menu ___________________________|" << endl
									        	 << "| 1. Ajout d'un utilisateur au magasin                      |" << endl
												 << "| 2. Afficher la liste des client du magasin                |" << endl
												 << "| 3. Afficher les informations sur d'un client              |" << endl
												 << "| 0. Quitter                                                |" << endl 
												 << "|___________________________________________________________|" << endl
												 << "Choix : ";
									        cin >> choix;
									        cout << endl;
											switch(choix)
								        	{	
								        	case 0 : break;
								 
											case 1 :
											string nom,prenom;
											cout<<"entrez le nom du client que vous souhaitez ajouter à votre magasin"<<endl;
											cin>>nom;
											cout<<"entrez le prenom du client que vous souhaitez ajouter à votre magasin"<<endl;
											cin>>prenom;
											easystore.add_client(nom,prenom);

											choix=0;
											break;

											case 2 :

												easystore.display_client();
												choix=0;
												break;

											case 3 :
											string nom,prenom;
											cout<<"entrez le nom du client que vous souhaitez ajouter à votre magasin"<<endl;
											cin>>nom;
											cout<<"entrez le prenom du client que vous souhaitez ajouter à votre magasin"<<endl;
											cin>>prenom;

											easystore.display_select_clt(nom,prenom);
											choix=0;
												break;



											}

										//gestion de commande

						 			case 3 : 
								 			int choix=0;
									        cout << " ___________________________________________________________ " << endl
									        	 << "|__________________________ Menu ___________________________|" << endl
									        	 << "| 1. modifier le statut  d'une commande                     |" << endl
												 << "| 2. lister les commandes                                   |" << endl
												 << "| 0. Quitter                                                |" << endl 
												 << "|___________________________________________________________|" << endl
												 << "Choix : ";
									        cin >> choix;
									        cout << endl;
											switch(choix)
								        	{	

								        	case 0 : break;
								 
											case 1 :
													int  id_statut;
													cout<<"entrez l'identifiant de la commande"<<endl;
													cin>>id_statut;
													easystore.statut_commande(id_statut);
													choix = 0;
						           					break;

						           			case 2 : 
						           					easystore.display_orders();
						           					choix = 0;
						           					break;


											}
					           			choix = 0;
					           			break;


				case 2 : 
						//CAS DU CLIENT
						int id;
						string nom,prenom;
						cout<<"Entrez votre nom"<<endl;
						cin>> nom;
						cout<<"Entrez le prenom"<<endl;
						cin>> prenom; 
						cout<<"Entrez votre identifiant"<<endl;
						cin>> id;
						Client client(id,nom,prenom);
						cout<<"voici la liste de nos produits"<<endl;
						easystore.display_orders();

				       int choix=0;
					        cout << " ___________________________________________________________ " << endl
					        	 << "|__________________________ Menu ___________________________|" << endl
					        	 << "| 1. Ajouter un produit a mon panier                        |" << endl
								 << "| 2. supprimer un produit du panier                         |" << endl
								 << "| 3. Modifier la quantité d'un produit                      |" << endl
								 << "| 4. Valider ma commande                                    |" << endl
								 << "| 0. Quitter                                                |" << endl 
								 << "|___________________________________________________________|" << endl
								 << "Choix : ";
					        cin >> choix;
					        cout << endl;
									switch(choix)
						        	{	

						        	case 0 : break;
						 
									case 1 :
									string titre;
									cout<<"entrez le titre du produit desiré"<<endl;
									cin>>titre;
									client.add_product(titleProduct) ;
											
											choix = 0;
											break;

									case 2 : 
									string titre;
									cout<<"entrez le titre du produit que vous desirez supprimer"<<endl;
									cin>>titre;
									client.del_product(titre);
									choix =0;
									break;

									case 3 :
									string titleProduct;
									int newqtt;
									cout<<"entrez le titre du produit que vous desirez modifier"<<endl;
									cin>>titleProduct;
									cout<<"entrez la nouvelle quantité"<<endl;
									cin>>newqtt;
									client.modify_product(titleProduct,newqtt);
									choix =0;
									break;


									case 4 :
									int id;
									cout<<"Entrez votre identifiant"<<endl;
									cin>> id;
									easystore.valide_commande(id);
									choix =0;
									break;




								}
								choix =0;
									break;


			  }			 








	return 0;
}