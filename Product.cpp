
#include <iostream>
#include <string>
#include "Product.h"

Product::Product(){} // Crée un produit vide

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
std::ostream &operator << (std::ostream &output, Product &p){
	output <<" Title : "<< p.m_title <<" - Description : "<< p.m_desc<<
			" - Quantity : "<< p.m_qtt <<" - Price : "<< p.m_price<<"£" << std::endl;
	return output; 
}