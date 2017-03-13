/*
** format_c.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib/formats
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 22:14:13 2014 Thibaud Auzou
** Last update Sun Nov 16 22:14:17 2014 Thibaud Auzou
*/

#include <unistd.h>
#include "my.h"

int		format_c(va_list ap, t_format_options *f_op)
{
  char		elem;
  char		tab[2];

  if (f_op->format_function == 20)
    {
      elem = IDENTIFIER;
      f_op->width = -1;
    }
  else
    elem = va_arg(ap, int);
  tab[0] = elem;
  tab[1] = '\0';
  f_op->precision = -1;
  return (my_putstr(tab, f_op));
}
