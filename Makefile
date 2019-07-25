# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cterblan <cterblan@student.wethinkcode>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 20:26:51 by cterblan          #+#    #+#              #
#    Updated: 2019/07/25 21:42:27 by cterblan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################

AUTHOR = cterblan
OUTPUT = nm.exe

################################################################################

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib

###############################################################################

SRC		:= nm.c
OBJ		:= $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

###############################################################################

PRINTF_DIR = $(LIB_DIR)/ft_printf

###############################################################################

CFLAGS	:= -Wall -Werror -Wextra -D_XOPEN_SOURCE=500
COMPILE	:= gcc $(CFLAGS)

###############################################################################

all: update $(OUTPUT)

$(OUTPUT): $(OBJ)
	make all -C $(PRINTF_DIR)
	gcc -o $(OUTPUT) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	#norminette $<
	mkdir -p $(OBJ_DIR)
	$(COMPILE) -I $(INC_DIR) -o $@ -c $<

update:
	git submodule update --init --recursive --remote

clean: libclean
	rm -rf $(OBJ_DIR)

libclean:
	make clean -C $(PRINTF_DIR)

fclean: clean libfclean
	rm -f $(OUTPUT)

libfclean:
	make fclean -C $(PRINTF_DIR)

re: fclean all

workspace:
	mkdir -p $(INC_DIR)
	mkdir -p $(SRC_DIR)
	mkdir -p $(LIB_DIR)
	touch author
	echo $(AUTHOR) > author

###############################################################################

.PHONEY := all clean fclean re workspace

.SILENT:

.PRECIOUS := author