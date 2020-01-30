
#ifndef _product_h
#define _product_h

#include <string>

class Product
{
public:
	Product();
	Product(std::string title="PS4", std::string desc="Console de jeu",int qtt=1, float price=249.99); //desc= description produit
	std::string getTitle() const;
	std::string getDesc() const;
	int getQtt() const;
	float getPrice() const;
	void setQtt(int new_qtt);// setQtt permet de modifier la quantité disponible.
	friend std::ostream &operator <<(std::ostream &ouput, Product &p); //surcharge de l'opérateur "<<" pour afficher un produit

private:
	std::string m_title;
	std::string m_desc;
	int m_qtt;
	float m_price;
};

#endif