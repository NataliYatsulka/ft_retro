// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 18:54:38 by nyatsulk          #+#    #+#             //
//   Updated: 2017/11/04 18:54:38 by nyatsulk         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_HPP
# define PLAYER_HPP
 
# include "Unit.hpp"
class Player : public Unit
{

public:
	Player(void);
	Player(int x, int y);
	Player(Player const & src);
	Player& operator=(Player const & src);
	~Player();

	void shoot();
	void move_right();
	void move_up();
	void move_down();

};

#endif
