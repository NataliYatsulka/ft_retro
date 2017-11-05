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
	Player p(12, 2);

	Enemy mas_e[10];
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " " << mas_e[i].getX() << ", " << mas_e[i].getY() << std::endl;
	}

	
	// while (p.check_if_no_touch() > 0)
	// {

	// }


	// p.move_right();

	initscr(); /* Start curses mode */
	int row, col;
	getmaxyx(stdscr, row,col);
	printw("rwo= %d, col=%d", row, col);
	noecho();
	curs_set(0);
	timeout(0);
	while (1)
	{
		
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
