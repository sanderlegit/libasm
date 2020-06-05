# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: averheij <averheij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/05 12:48:29 by averheij      #+#    #+#                  #
#    Updated: 2020/06/05 17:47:38 by averheij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a
SFILES	=	ft_strlen.S ft_strcpy.S ft_strcmp.S
OFILES	=	$(SFILES:%.S=%.o)
ASMCC	=	nasm -felf64
#ASMCC	=	nasm -fmacho64
T_DIR	=	test

all: $(NAME)

$(NAME): $(OFILES)
	@echo "Creating Library"
	ar rc $(NAME) $(OFILES)

%.o: %.S
	@echo "Compiling: $<"
	$(ASMCC) -o $@ $<

clean:
	@echo "Cleaning: Objects"
	rm -f $(OFILES)
	rm -f $(OTEST)

fclean: clean
	@echo "Cleaning: Library"
	rm -f $(NAME)
	@echo "//------Test------\\\\\\\\"
	make -C $(T_DIR) fclean
	@echo "--------------------"


re: fclean all
	@echo "//------Test------\\\\\\\\"
	make -C $(T_DIR) re
	@echo "--------------------"

test: all
	@echo "//------Test------\\\\\\\\"
	make -C $(T_DIR)
	@echo "--------------------"

run: test
	./$(T_DIR)/libasmtest
	

