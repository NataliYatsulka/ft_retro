// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Unit.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 18:54:54 by nyatsulk          #+#    #+#             //
//   Updated: 2017/11/04 18:54:54 by nyatsulk         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef UNIT_HPP
# define UNIT_HPP

# include <iostream>
# include <string>
# include <cstdlib>

# define MAX_X 100
# define MAX_Y 50
# define MIN_X 0
# define MIN_Y 0
# define ENEMY 10

class Unit
{
public:
	Unit();
	~Unit();
	Unit(Unit const & src);
	Unit& operator=(Unit const & src);

	int getX() const;
	int getY() const;

	void setX(int amount);
	void setY(int amount);

protected:
	int _x;
	int _y;

};

#endif
