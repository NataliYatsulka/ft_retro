// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 18:54:22 by nyatsulk          #+#    #+#             //
//   Updated: 2017/11/04 18:54:23 by nyatsulk         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Unit.hpp"

class Enemy : public Unit
{

public:
	Enemy(void);
	Enemy(int x, int y);
	Enemy(Enemy const & src);
	Enemy& operator=(Enemy const & src);
	~Enemy();

	void random_set_cord();
	void move_left();

};

#endif
