// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 18:54:15 by nyatsulk          #+#    #+#             //
//   Updated: 2017/11/04 18:54:16 by nyatsulk         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"

Enemy::Enemy(void)
{
	this->random_set_cord();
	return ;
}

Enemy::Enemy(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy& Enemy::operator=(Enemy const & src)
{
	this->_x = src.getX();
	this->_y = src.getY();
	return (*this);
}

Enemy::~Enemy()
{
	std::cout << "Enemy dead." << std::endl;
}

void Enemy::random_set_cord()
{
	this->_x = (random() % (MAX_X / 3)) + 2 * (MAX_X / 3 - 1) ;
	this->_y = (random() % MAX_Y);
}

// void Enemy::check_cord()
// {

// }
