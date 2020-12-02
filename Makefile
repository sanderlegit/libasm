# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: averheij <averheij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/05 12:48:29 by averheij      #+#    #+#                  #
#    Updated: 2020/12/02 14:37:55 by averheij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a
SFILES	=	ft_strlen.S ft_strcpy.S ft_strcmp.S ft_write.S ft_read.S ft_strdup.S
OFILES	=	$(SFILES:%.S=%.o)
#ASMCC	=	nasm -felf64
ASMCC	=	nasm -fmacho64
T_DIR	=	test

all: $(NAME)

$(NAME): $(OFILES)
	ar -rc $(NAME) $(OFILES)

%.o: %.S
	$(ASMCC) -o $@ $<

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)


re: fclean all
