# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: averheij <averheij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/05 13:54:09 by averheij      #+#    #+#                  #
#    Updated: 2020/06/05 14:18:56 by averheij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libasmtest
CFILES	=	main.c
OFILES	=	$(CFILES:%.c=%.o)
FLAGS	=	-g #-Werror -Wall -Wextra
LIBS	=	-L./.. -lasm
CCC		=	gcc $(FLAGS)

all: $(NAME)

$(NAME): $(OFILES)
	@echo "Creating Executable"
	$(CCC) -o $(NAME) $(OFILES) $(LIBS)

%.o: %.S
	@echo "Compiling: $<"
	$(CCC) -o $@ $<

clean:
	@echo "Cleaning: Objects"
	rm -f $(OFILES)
	rm -f $(OTEST)

fclean: clean
	@echo "Cleaning: Binary"
	rm -f $(NAME)

re: fclean all
