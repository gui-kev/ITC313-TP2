
#ifndef _product_h
#define _product_h

#include <string>

class Product
{
public:
	Product(std::string title="PS4",
			std::string desc="Console de jeu de marque Sony",//qtt=quantité disponible
			int qtt=10, float price=249.99); //desc= description produit
	std::string getTitle() const;
	std::string getDesc() const;
	int getQtt() const;
	float getPrice() const;
	int setQtt(int new_qtt);// setQtt permet de modifier la quantité disponible.

private:
	std::string m_title;
	std::string m_desc;
	int m_qtt;
	float m_price;

};
std::ostream &operator <<(std::ostream &ouput, Product &p);


#endif