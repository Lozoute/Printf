/*
** format_f.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib/formats
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 22:13:31 2014 Thibaud Auzou
** Last update Sun Nov 16 22:13:32 2014 Thibaud Auzou
*/

#include "my.h"

int		format_f(va_list ap, t_format_options *f_op)
{
  double	elem;

  elem = va_arg(ap, double);
  return (my_putnbr_float(elem, f_op));
}
