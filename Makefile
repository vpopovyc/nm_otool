# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 16:17:58 by vpopovyc          #+#    #+#              #
#    Updated: 2018/04/09 16:18:00 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM_BIN = ft_nm

NM_SRC = nm/main.c

NM_OBJ = $(NM_SRC:.c=.o)

NM_INC = -I. -Inm

nm/%.o: nm/%.c
	$(CC) $(CCFLAGS) $(LIBSINC) $(NM_INC) -o $@ -c $<

# **************************************************************************** #

OTOOL_BIN = ft_otool

OTOOL_SRC = otool/main.c

OTOOL_OBJ = $(OTOOL_SRC:.c=.o)

OTOOL_INC = -I. -Iotool

otool/%.o: otool/%.c
	$(CC) $(CCFLAGS) $(LIBSINC) $(OTOOL_INC) -o $@ -c $<

# **************************************************************************** #

LIBFTBIN = libft/libft.a

LIBFTINC = libft/includes

LIBFT = libft

# **************************************************************************** #

LIBS = -lft

LIBSDIR = -L$(LIBFT)

LIBSINC = -I$(LIBFTINC)

CCFLAGS = -Wall -Wextra -Werror

CC = clang

# **************************************************************************** #

all: $(LIBFTBIN) $(NM_BIN) $(OTOOL_BIN)

$(NM_BIN): $(NM_OBJ)
	$(CC) $(CCFLAGS) $(LIBSDIR) $(LIBS) $(NM_INC) $(NM_OBJ) -o $(NM_BIN)

$(OTOOL_BIN): $(OTOOL_OBJ)
	$(CC) $(CCFLAGS) $(LIBSDIR) $(LIBS) $(OTOOL_INC) $(OTOOL_OBJ) -o $(OTOOL_BIN)

clean:
	@rm -rf $(NM_OBJ) $(OTOOL_OBJ)

fclean: clean
	@rm -rf $(NM_BIN) $(OTOOL_BIN)

re: fclean all

# **************************************************************************** #

$(LIBFTBIN): libft.all

libft.all:
	@make -C libft/ all

libft.clean:
	@make -C libft/ clean

libft.fclean:
	@make -C libft/ fclean

libft.re:
	@make -C libft/ re
