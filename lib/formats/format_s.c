/*
** format_s.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib/formats
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 22:12:08 2014 Thibaud Auzou
** Last update Sun Nov 16 22:12:15 2014 Thibaud Auzou
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int		format_s(va_list ap, t_format_options *f_op)
{
  char		*elem;

  elem = va_arg(ap, char *);
  if (elem == NULL)
    {
      if (write(1, "(null)", 6) == -1)
	return (-42);
      return (6);
    }
  return (my_putstr(elem, f_op));
}
