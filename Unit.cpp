// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Unit.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 18:54:47 by nyatsulk          #+#    #+#             //
//   Updated: 2017/11/04 18:54:48 by nyatsulk         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Unit.hpp"

Unit::Unit()
{
	return ;
}
	
Unit::~Unit()
{
	return ;
}
	
Unit::Unit(Unit const & src)
{
	*this = src;
}

Unit& Unit::operator=(Unit const & src)
{
	this->_x = src.getX();
	this->_y = src.getY();
	return (*this);
}

int Unit::getX() const
{
	return this->_x;
}

int Unit::getY() const
{
	return this->_y;
}

void Unit::setX(int amount)
{
	this->_x = amount;
}

void Unit::setY(int amount)
{
	this->_y = amount;
}
