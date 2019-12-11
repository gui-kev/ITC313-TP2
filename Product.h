
#ifndef _product_h
#define _product_h

#include <string>

class Product
{
public:
	Product(std::string title, std::string desc,//qtt=quantité disponible
			int qtt, float price); //desc= description produit
	std::string getTitle() const;
	std::string getDesc() const;
	int getQtt() const;
	int getPrice() const;
	int setQtt(int new_qtt);// setQtt permet de modifier la quantité disponible.


private:
	std::string m_title;
	std::string m_desc;
	int m_qtt;
	float price;
}

#endif