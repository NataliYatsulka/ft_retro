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

void Unit::move_left()
{
	if (this->_x > MIN_Y)
		this->_x -= 1;
}

// int check_if_no_touch(Player &p, Enemy &e)
// {
// 	if (abs(p.getX() - e.getX()) == 1)
// 		return (-1);
// 	if (abs(p.getY() - e.getY()) == 1)
// 		return (-1);
// 	return (1);
// }

int check_if_no_touch(int x_p, int y_p, int x_e, int y_e)
{
	if (abs(x_p - x_e) == 1)
		return (-1);
	if (abs(y_p - y_e) == 1)
		return (-1);
	return (1);
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
