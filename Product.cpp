
#include <iostream>
#include <string>
#include "Product.h"

Product::Product(std::string title, std::string desc, int qtt, float price)
{
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


std::ostream &operator << (std::ostream &output, Product &p)
{
	output << p.getTitle() <<"-"<< p.getDesc() 
		   <<"-"<< p.getQtt() <<"-"<< p.getPrice()<<"£" << std::endl;
	return output; 
}