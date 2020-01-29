
#include <iostream>
#include <vector>
#include "Magasin.h"

int main()
{
	Magasin my_easystore;
	// Add new clients
	my_easystore.add_client("Dom", "Ginhac");
	my_easystore.add_client("Bill", "Gates");
	my_easystore.add_client("Richard", "Stallman");
	my_easystore.add_client("Alan", "Turing");
	my_easystore.add_client("Steve", "Jobs");

	// Display all the clients
	my_easystore.display_client();

	// Display clients "Richard Stalman" and 4
	my_easystore.display_select_clt("Richard", "Stallman");
	my_easystore.display_select_clt(2);

	// Add products to the store with Title, Description, Price and Quantity
	my_easystore.add_product("Console de jeu Sony"," ", 249.99,10);
	my_easystore.add_product("Switch", "Console de jeu Nintendo", 299.99,30);
	my_easystore.add_product("Xbox One", "Console de jeu Microsoft", 179.99,15);

	// Add a product with its title and add to a client identified by his name	
	my_easystore.add_product_clt("Casque RV PS", "Richard", "Stallman");

	// Add a product with its title and add to a client identified by his uid
	//my_easystore.add_product_clt("Casque Audio", 4);

	// Display all the products
	//my_easystore.display_product();

	// Update quantity of a product
	//my_easystore.update_product_quantity("Switch", 20);

	// Display the updated product
	//my_easystore.display_select_product("Switch");

	std::string a = "Kaspersky";
	my_easystore.display_select_product(a);
	//my_easystore.display_client();
	std::cout<<" Run ok "<<std::endl;
	return 0;
}