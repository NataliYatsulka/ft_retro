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
#include <ncurses.h>

Player::Player(void)
{
	return ;
}

Player::Player(Player const & src)
{
	*this = src;
}

Player::Player(int x, int y)
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
	if (this->_y == e.getY())
	{
		mvaddch(e.getY(), e.getX(), ' ' | A_INVIS);
		e.random_set_cord();
	}
}

void Player::move_left()
{
	if (this->_x > MIN_Y)
		this->_x -= 1;
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

int Player::check_if_no_touch(Enemy &e)
{
	if ((abs(this->getX() - e.getX()) + abs(this->getY() - e.getY()))< 2)
		return (-1);
	return (1);
}
