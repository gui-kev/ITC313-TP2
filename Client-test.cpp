
#include<iostream>
#include<vector>
#include<string>
#include "Client.h"

int main(){
	Client cl1;
	Product p1;
	Product p2("XBOX","Console de jeu",1,249.99);
	std::vector<Product* > panier;
	panier.push_back(&p1);
	panier.push_back(&p2);
	Client cl2(1,panier,"Gladys", "___");
	std::vector <Client* > vector_client;
	vector_client.push_back(&cl2);
	std::cout<<cl2;
	return 0;
}