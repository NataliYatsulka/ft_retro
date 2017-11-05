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


void		scr_init( void )
{
	// int			max_y, max_x;

	// initscr();
	// curs_set(0); /* Hide cursor */
	// start_color();
 //    use_default_colors();
	// getmaxyx(stdscr, max_y, max_x);
	// if ( max_x < MAX_X || max_y < MAX_Y + 1 )
	// {
	// 	endwin();
	// 	printf( "Screen must be at least %dpx / %dpx\n", MAX_X * 8, MAX_Y * 16 );
	// 	exit(0);
	// }
	// // atexit( scr_end );
	// noecho();
	// keypad(stdscr, TRUE);
	// timeout(0);

}

int	main(void)
{
	// bool b = TRUE;
	time_t e_move;	

	Enemy mas_e[10];

	for (int i = 0; i < 10; i++)
	{
		Enemy(mas_e[i].getX(), mas_e[i].getY());
		mas_e[i].move_left();
		// std::cout << i << " " << mas_e[i].getX() << ", " << mas_e[i].getY() << std::endl;
	}

	
	// while (p.check_if_no_touch() > 0)
	// {

	// }


	// p.move_right();

	initscr(); /* Start curses mode */

	

	int row, col;
	getmaxyx(stdscr, row,col);
	Player p(0, row / 2);
	// printw("rwo= %d, col=%d", row, col);
	noecho();	
	curs_set(0);
	timeout(0);

	time(&e_move);
	while (1)
	{
		for (int i = 0; i < 10; i++)
		{
			if (p.check_if_no_touch(p, mas_e[i]) == 0)
			{
				printw("%d, px=%d,%d; ex=%d, %d", i, p.getX(), p.getY(), mas_e[i].getX(), mas_e[i].getY());
				timeout(-1);
				getch();
				exit (-1);
			}
		}

		if (difftime(time(0), e_move) >= 1)
		{
			for (int i = 0; i < 10; i++)
			{
				mvaddch(mas_e[i].getY(), mas_e[i].getX(), ' ' | A_INVIS);
				mas_e[i].move_left();
				mvaddch(mas_e[i].getY(), mas_e[i].getX(), 'X' | A_BOLD);
			}
			time(&e_move);
		}
		int ch = getch(); /* Wait for user input */
		// printw("ch=%d", ch);
		mvprintw(p.getY(), p.getX(), "   ");	
		// mvaddch(p.getY(), p.getX(), ' ' | A_INVIS);
		// mvaddch(p.getY()-1, p.getX(), ' ' | A_INVIS);
		// mvaddch(p.getY()+1, p.getX(), ' ' | A_INVIS);

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
		}
		mvprintw(p.getY(), p.getX(), "|*>");

		// mvaddch(p.getY(), p.getX(), '+' | A_REVERSE);
		// mvaddch(p.getY()-1, p.getX(), '-' | A_REVERSE);
		// mvaddch(p.getY()+1, p.getX(), '+' | A_REVERSE);
		refresh(); /* Print it on to the real screen */
 		
	}
	endwin(); /* End curses mode */
	p.shoot();
	return 0;
}
