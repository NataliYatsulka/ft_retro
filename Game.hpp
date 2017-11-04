// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 19:06:48 by nyatsulk          #+#    #+#             //
//   Updated: 2017/11/04 19:06:49 by nyatsulk         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

# include "Unit.hpp"
# include "Enemy.hpp"
# include "Player.hpp"

class Game
{

private:
	Enemy mas_enemy[10];

public:
	Game(void);
	Game(Game const & src);
	// Game operator=(Game const & src);
	~Game();

};

#endif
