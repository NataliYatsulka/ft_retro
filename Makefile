#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/04 17:34:37 by nyatsulk          #+#    #+#              #
#    Updated: 2017/11/04 17:34:37 by nyatsulk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro

SOURCE = main.cpp\
		Unit.cpp\
		Player.cpp\
		Enemy.cpp\
		Game.cpp
		# Window.cpp

OBJECTS = $(SOURCE:%.cpp=%.o)

CC = clang++
FLAG = -Wall -Wextra -Werror

NCURS = -lncurses
.PHONY: all fast clean fclean

all: main

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAG) $(NCURS)

main: $(OBJECTS)
	@$(CC) -o $(NAME) $(FLAG) $(OBJECTS)

fast: $(OBJECTS)
	@$(CC) $(FLAG) -o $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(OBJECTS) $(NAME)

re: fclean all
