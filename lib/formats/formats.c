/*
** formats.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib/formats
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 22:14:59 2014 Thibaud Auzou
** Last update Sun Nov 16 22:24:17 2014 Thibaud Auzou
*/

#include "my.h"

int		find_format_and_options(const char *str,
					t_format_options *f_op,
					va_list ap)
{
  int		i;

  i = 0;
  while (was_flag(str[i], f_op))
    i = i + 1;
  if (str[i] >= '0' && str[i] <= '9')
    f_op->width = my_getnbr(&(str[i]));
  else if (str[i] == '*')
    f_op->width = va_arg(ap, int);
  while ((str[i] >= '0' && str[i] <= '9') || (str[i] == '*'))
    i = i + 1;
  if (str[i] == '.')
    i = i + 1;
  if (str[i] >= '0' && str[i] <= '9')
    f_op->precision = my_getnbr(&(str[i]));
  else if (str[i] == '*')
    f_op->precision = va_arg(ap, int);
  else if (i != 0 && str[i - 1] == '.')
    f_op->precision = 0;
  while ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
    i = i + 1;
  while (was_len(str[i], f_op))
    i = i + 1;
  add_specifier(str[i], f_op);
  return (i);
}

int		was_flag(char c, t_format_options *f_op)
{
  int		i;
  char		*flags;

  i = 0;
  flags = FLAGS;
  while (flags[i])
    {
      if (flags[i] == c)
	{
	  f_op->flags[i] = f_op->flags[i] + 1;
	  return (1);
	}
      i = i + 1;
    }
  return (0);
}

int		was_len(char c, t_format_options *f_op)
{
  int		i;
  char		*len;

  i = 0;
  len = LEN;
  while (len[i])
    {
      if (len[i] == c)
	{
	  f_op->lenght[i] = f_op->lenght[i] + 1;
	  if (((i < 2) && (f_op->lenght[i] > 2)) || alrdy_len(f_op))
	    {
	      f_op->format_function = -2;
	      return (0);
	    }
	  else if (((i > 1) && (f_op->lenght[i] > 1)) || alrdy_len(f_op))
	    {
	      f_op->format_function = -2;
	      return (0);
	    }
	  return (1);
	}
      i = i + 1;
    }
  return (0);
}

int		alrdy_len(t_format_options *f_op)
{
  int		j;
  int		already;

  already = 0;
  j = 0;
  while (j < 6)
    {
      if (f_op->lenght[j] > 0 && already)
	{
	  return (1);
	}
      else if (f_op->lenght[j] > 0)
	already = 1;
      j = j + 1;
    }
  return (0);
}

int		add_specifier(char c, t_format_options *f_op)
{
  int		i;
  char		*formats;

  if (f_op->format_function == -2)
    {
      f_op->format_function = -1;
      return (1);
    }
  i = 0;
  formats = FORMATS;
  while (formats[i])
    {
      if (formats[i] == c && !(i > 9 && i < 16))
	{
	  f_op->format_function = i;
	  if (c == 'p')
	    f_op->flags[3] = 1;
	  return (0);
	}
      i = i + 1;
    }
  return (0);
}
