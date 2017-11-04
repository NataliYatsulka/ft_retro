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
	bool b = TRUE;
	Player p(12, 2);

	p.move_right();

	initscr(); /* Start curses mode */
	printw("Hello World !!!"); /* Print Hello World */
	refresh(); /* Print it on to the real screen */
	
	while (1)
	{
		// scr_init();
	char ch = getch(); /* Wait for user input */
 	printw ("You pressed %d=%c\n", ch,ch);
 	refresh(); /* Print it on to the real screen */
 	if (ch == 27)
 		break;
	}
	endwin(); /* End curses mode */
	p.shoot();
	return 0;
}
