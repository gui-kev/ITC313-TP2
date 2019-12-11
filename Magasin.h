
#ifndef _magasin_h
#define _magasin_h

#include <vector>

class Magasin
{
public:
	Magasin(std::vector<Product> prod,
			std::vector<Client> clt,
			std::vector<Order> cmd);

private:
	std::vector<Product*> m_products;
	std::vector<Client*> m_clients;
	std::vector<Order*> m_orders;	
};

#endif