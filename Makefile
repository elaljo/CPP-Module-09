# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 15:09:35 by moelalj           #+#    #+#              #
#    Updated: 2025/01/15 15:15:38 by moelalj          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

g++ = c++

RM = rm -rf

SRC = main.cpp\
		BitcoinExchange.cpp

OBJS := $(SRC:.cpp=.o)

all: $(NAME)

%.o:%.cpp BitcoinExchange.hpp
	$(g++) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(g++) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all