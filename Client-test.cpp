
#include<iostream>
#include<vector>
#include<string>
#include "Client.h"

int main(){
	Client cl1;
	std::vector<Product* > p;
	Client cl2(1,p,"Gladys", "___");
	std::vector <Client* > vector_client;
	vector_client.push_back(&cl2);
	std::cout<<cl2;
	return 0;
}