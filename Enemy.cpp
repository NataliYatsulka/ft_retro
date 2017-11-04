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
	return ;
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
	this->_x = random() % MAX_X;
	this->_y = MAX_X;
}

// void Enemy::check_cord()
// {

// }
