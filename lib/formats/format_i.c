/*
** format_i.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib/formats
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 22:12:59 2014 Thibaud Auzou
** Last update Sun Nov 16 22:13:06 2014 Thibaud Auzou
*/

#include "my.h"

int		format_i(va_list ap, t_format_options *f_op)
{
  int		elem;
  int		neg;
  unsigned int	tmp;

  neg = 0;
  elem = va_arg(ap, int);
  if (elem == -2147483648)
    {
      tmp = 2147483648;
      neg = 1;
    }
  else if (elem < 0)
    {
      tmp = elem * -1;
      neg = 1;
    }
  else
    tmp = elem;
  return (my_putnbr_base(tmp, BASE_10, neg, f_op));
}
