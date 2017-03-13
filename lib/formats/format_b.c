/*
** format_b.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib/formats
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 22:14:32 2014 Thibaud Auzou
** Last update Sun Nov 16 22:14:43 2014 Thibaud Auzou
*/

#include "my.h"

int		format_b(va_list ap, t_format_options *f_op)
{
  unsigned int	elem;

  elem = va_arg(ap, unsigned int);
  return (my_putnbr_base(elem, BASE_2, 0, f_op));
}
