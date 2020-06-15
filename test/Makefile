# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: averheij <averheij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/05 13:54:09 by averheij      #+#    #+#                  #
#    Updated: 2020/06/15 15:02:44 by averheij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libasmtest
CFILES	=	main.c strlentest.c strcpytest.c strcmptest.c writetest.c readtest.c
OFILES	=	$(CFILES:%.c=%.o)
FLAGS	=	-g -no-pie #-Werror -Wall -Wextra
LIBS	=	-L./.. -lasm
CCC		=	gcc $(FLAGS)

all: $(NAME)

$(NAME): $(OFILES)
	$(CCC) -o $(NAME) $(OFILES) $(LIBS)

%.o: %.S
	$(CCC) -o $@ $<

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
