/*
** my_printf.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 21:41:51 2014 Thibaud Auzou
** Last update Sun Nov 16 22:23:53 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		(*formatf[NB_FORMAT_F])();
  int		n;

  va_start(ap, format);
  init_formatf(formatf);
  n = 0;
  if (parse_expr(format, ap, formatf, &n) == -42)
    n = -42;
  va_end(ap);
  return (n);
}

int		parse_expr(const char *format,
			   va_list ap,
			   int (**formatf)(),
			   int *n)
{
  int		i;
  int		size;
  int		tmp;

  i = 0;
  size = my_strlen(format);
  while (format != NULL && i < size && format[i])
    {
      if (format[i] == IDENTIFIER)
	{
	  tmp = begin_format(&(format[i + 1]), ap, formatf, n) + 2;
	  if (tmp == -42)
	      return (-42);
	  i = i + tmp;
	}
      else if (write(1, &(format[i]), 1) == -1)
	return (-42);
      else
	{
	  i++;
	  (*n)++;
	}
    }
  return (0);
}

int		init_formatf(int (**formatf)())
{
  formatf[0] = format_b;
  formatf[1] = format_s;
  formatf[2] = format_d;
  formatf[3] = format_i;
  formatf[4] = format_u;
  formatf[5] = format_o;
  formatf[6] = format_x;
  formatf[7] = format_X;
  formatf[8] = format_f;
  formatf[9] = format_F;
  formatf[10] = NULL;
  formatf[11] = NULL;
  formatf[12] = NULL;
  formatf[13] = NULL;
  formatf[14] = NULL;
  formatf[15] = NULL;
  formatf[16] = format_c;
  formatf[17] = format_s;
  formatf[18] = format_p;
  formatf[19] = format_n;
  formatf[20] = format_c;
  return (0);
}

int			begin_format(const char *str,
				     va_list ap,
				     int (**formatf)(),
				     int *n)
{
  t_format_options	f_op;
  int			i;
  int			tmp;

  tmp = *n;
  f_op.format_function = -1;
  f_op.width = -1;
  f_op.precision = -1;
  f_op.n = *n;
  i = 0;
  while (i < 6)
    {
      f_op.flags[i] = 0;
      f_op.lenght[i] = 0;
      i = i + 1;
    }
  i = find_format_and_options(str, &f_op, ap);
  if (f_op.format_function == -1)
    {
      *n = *n + 1;
      return ((my_putchar(IDENTIFIER)) ? -42 : -1);
    }
  *n = *n + formatf[f_op.format_function](ap, &f_op);
  return ((tmp > *n) ? (-42) : (i));
}
