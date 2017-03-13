##
## Makefile for my_printf in /home/auzou_t/CPE_2014_my_printf/lib
## 
## Made by Thibaud Auzou
## Login   <auzou_t@epitech.net>
## 
## Started on  Sun Nov 16 21:39:31 2014 Thibaud Auzou
## Last update Sun Nov 16 21:54:13 2014 Thibaud Auzou
##

CC		= gcc

AR		= ar rc

NAME		= libmy.a

CFLAGS		+= -Wextra -Wall -Werror -Wno-unused-parameter
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -I../include/ -D_BSD_SOURCE

LDFLAGS	=

SRC		= my_putchar.c \
		  my_putstr.c \
		  my_strlen.c \
		  my_getnbr.c \
		  my_putnbr_base.c \
		  my_putnbr_float.c \
		  my_printf.c \
		  formats/formats.c \
		  formats/format_b.c \
		  formats/format_S.c \
		  formats/format_d.c \
		  formats/format_i.c \
		  formats/format_u.c \
		  formats/format_o.c \
		  formats/format_x.c \
		  formats/format_X.c \
		  formats/format_f.c \
		  formats/format_F.c \
		  formats/format_c.c \
		  formats/format_s.c \
		  formats/format_p.c \
		  formats/format_n.c \
		  print/print.c

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
