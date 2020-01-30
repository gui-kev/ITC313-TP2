
#include <iostream>
#include <vector>
#include "Magasin.h"

int main()
{
	Magasin my_easystore;
	// Add new clients
	my_easystore.add_client("Dominique", "Ginhac");
	my_easystore.add_client("Bill", "Gates");
	my_easystore.add_client("Richard", "Stallman");
	my_easystore.add_client("Alan", "Turing");
	my_easystore.add_client("Steve", "Jobs");

	// Display all the clients
	std::cout << std::endl << "__________Tous les clients__________"<< std::endl;
	my_easystore.display_client();

	// Display clients "Richard Stalman" and 4
	std::cout << std::endl << "__________ Affichege d'un client à partir de son nom __________"<< std::endl;
	my_easystore.display_select_clt("Richard", "Stallman");
	std::cout << std::endl << "__________ Affichege d'un client à partir de son id __________"<< std::endl;
	my_easystore.display_select_clt(2);

	// Add products to the store with Title, Description, Price and Quantity
	my_easystore.add_product("Play Station","Console de jeu Sony", 249.99,10);
	my_easystore.add_product("Switch", "Console de jeu Nintendo", 299.99,30);
	my_easystore.add_product("Xbox One", "Console de jeu Microsoft", 179.99,15);

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
	my_easystore.display_select_product(a);
	//my_easystore.display_client();
	std::cout<<" Run ok "<<std::endl;
	return 0;
}