
#include <iostream>
#include <cstring>
#include "Product.h"

//Product::Product(){} // Crée un produit vide

Product::Product(std::string title, std::string desc, int qtt, float price){
	m_title=title;
	m_desc=desc;
	m_qtt=qtt;
	m_price=price;
}

std::string Product::getTitle() const{
	return m_title;
}

std::string Product::getDesc() const{
	return m_desc;
}

int Product::getQtt() const{
	return m_qtt;
}

float Product::getPrice() const{
	return m_price;
}

// setQtt permet de modifier la quantité de produit disponible
void Product::setQtt(int new_qtt){
	m_qtt=new_qtt;
}

//surcharge de l'opérateur << pour afficher un pproduit
std::ostream &operator << (std::ostream &output, Product& p){
	int a = std::strlen(p.m_title.c_str());
	int b = std::strlen(p.m_desc.c_str());
	std::string s = std::to_string(p.m_qtt);
	int c = std::strlen(s.c_str());
	if (a < 20)
		p.m_title.resize(20,' ');
	if (b < 40)
		p.m_desc.resize(40,' ');
	if (c < 12){
		s.resize(c+1,')');
		s.resize(12,' ');
	}
	output << "| " << p.m_title << p.m_desc
		   << "(" << s  << p.m_price << " € |";
	return output; 
}