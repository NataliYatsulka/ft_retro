// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 18:54:33 by nyatsulk          #+#    #+#             //
//   Updated: 2017/11/04 18:54:33 by nyatsulk         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"
// #include "Enemy.hpp"

Player::Player(void)
{
	return ;
}

Player::Player(Player const & src)
{
	*this = src;
}

Player::Player(int x, int y)// : _x(x), _y(y) {}
{
	this->_x = x;
	this->_y = y;
}

Player& Player::operator=(Player const & src)
{
	this->_x = src.getX();
	this->_y = src.getY();
	return (*this);
}

Player::~Player()
{
	std::cout << "Player dead." << std::endl;
}

void Player::shoot()
{
	std::cout << "SHOOOT" << std::endl;
}

void Player::shoot(Enemy &e)
{
	if (this->_x == e.getX())
	{
		e.setX(-1);
		e.setY(-1);
	}
	std::cout << "SHOOOT" << std::endl;
}

void Player::move_right()
{
	if (this->_x < MAX_X)
		this->_x += 1;
}

void Player::move_up()
{
	if (this->_y > 0)
		this->_y -= 1;
}

void Player::move_down()
{
	if (this->_y < MAX_Y)
		this->_y += 1;
}

int Player::check_if_no_touch(Player &p, Enemy &e)
{
	if (abs(p.getX() - e.getX()) < 2)
		return (-1);
	if (abs(p.getY() - e.getY()) < 2)
		return (-1);
	return (1);
}
