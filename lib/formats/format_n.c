/*
** format_n.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib/formats
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 22:09:44 2014 Thibaud Auzou
** Last update Sun Nov 16 22:09:53 2014 Thibaud Auzou
*/

#include "my.h"

int		format_n(va_list ap, t_format_options *f_op)
{
  int		*elem;

  elem = va_arg(ap, int *);
  *elem = f_op->n;
  return (0);
}
