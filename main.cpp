// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 17:34:45 by nyatsulk          #+#    #+#             //
//   Updated: 2017/11/04 17:34:46 by nyatsulk         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Unit.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

int	main(void)
{
	Player p(12, 2);

	p.move_right();
	p.shoot();
	return 0;
}