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
#include <ncurses.h>
#include <ctime>

int	main(void)
{
	time_t e_move;

	Enemy mas_e[ENEMY];

	for (int i = 0; i < ENEMY; i++)
	{
		Enemy(mas_e[i].getX(), mas_e[i].getY());
		mas_e[i].move_left();
	}
	initscr();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	int row, col;
	getmaxyx(stdscr, row, col);
	Player p(0, row / 3);
	noecho();	
	curs_set(0);
	timeout(0);

	time(&e_move);
	while (1)
	{
		for (int i = 0; i < ENEMY; i++)
		{
			if (p.check_if_no_touch(mas_e[i]) < 0)
			{
				for (int i = 0; i < ENEMY; i++)
				{
					mvaddch(mas_e[i].getY(), mas_e[i].getX(), ' ' | A_INVIS);
				}
				mvprintw(p.getY(), p.getX(), "   ");
				attron(COLOR_PAIR(3));
				mvprintw(0, 0, "GAME OVER");
				attroff(COLOR_PAIR(3));
				timeout(-1);
				getch();
				exit (-1);
			}
		}

		if (difftime(time(0), e_move) >= 1)
		{
			for (int i = 0; i < ENEMY; i++)
			{
				mvaddch(mas_e[i].getY(), mas_e[i].getX(), ' ' | A_INVIS);
				mas_e[i].move_left();
				attron(COLOR_PAIR(1));
				mvaddch(mas_e[i].getY(), mas_e[i].getX(), '*' | A_BOLD);
				attroff(COLOR_PAIR(1));
			}
			time(&e_move);
		}

		int ch = getch();
		mvprintw(p.getY(), p.getX(), "   ");
		switch(ch)
		{
			case (27):
				endwin();
				exit(-1);
				break;
			case 'w':
				p.move_up();
				break;
			case 's':
				p.move_down();
				break;
			case 'a':
				p.move_left();
				break;
			case 'd':
				p.move_right();
				break;
			case 'p':
			{
				for (int i = 0; i < ENEMY; i++) {p.shoot(mas_e[i]);}
				break;
			}
		}
		attron(COLOR_PAIR(2));
		mvprintw(p.getY(), p.getX(), "|*>" );
		attroff(COLOR_PAIR(2));
		refresh();
	}
	endwin();
	p.shoot();
	return 0;
}
