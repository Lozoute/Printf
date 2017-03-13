##
## Makefile for my_printf in /home/auzou_t/CPE_2014_my_printf
## 
## Made by Thibaud Auzou
## Login   <auzou_t@epitech.net>
## 
## Started on  Sun Nov 16 21:33:42 2014 Thibaud Auzou
## Last update Sun Nov 16 22:17:29 2014 Thibaud Auzou
##

CC		= gcc

AR		= ar rc

NAME		= lib/libmy.a

CFLAGS		+= -Wextra -Wall -Werror -Wno-unused-parameter
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -I./include/ -D_BSD_SOURCE

LDFLAGS	=

SRC		= lib/my_putchar.c \
		  lib/my_putstr.c \
		  lib/my_strlen.c \
		  lib/my_getnbr.c \
		  lib/my_putnbr_base.c \
		  lib/my_putnbr_float.c \
		  lib/my_printf.c \
		  lib/formats/formats.c \
		  lib/formats/format_b.c \
		  lib/formats/format_S.c \
		  lib/formats/format_d.c \
		  lib/formats/format_i.c \
		  lib/formats/format_u.c \
		  lib/formats/format_o.c \
		  lib/formats/format_x.c \
		  lib/formats/format_X.c \
		  lib/formats/format_f.c \
		  lib/formats/format_F.c \
		  lib/formats/format_c.c \
		  lib/formats/format_s.c \
		  lib/formats/format_p.c \
		  lib/formats/format_n.c \
		  lib/print/print.c

OBJS		= $(SRC:.c=.o)

RM		= rm -f


all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
