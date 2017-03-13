/*
** my_putstr.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 21:59:46 2014 Thibaud Auzou
** Last update Sun Nov 16 22:00:46 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		my_putstr(char *str, t_format_options *f_op)
{
  int		i;
  char		buff[BUFF_SIZE];
  int		j;
  int		limit;

  if (str == NULL)
    return (0);
  i = 0;
  buff[BUFF_SIZE - 1] = '\0';
  (f_op->precision == -1) ? (limit = MAX_INT) : (limit = f_op->precision);
  while (str[i] != '\0' && i <= limit)
    i++;
  if (i == 0)
    return (print_item(buff, (j = BUFF_SIZE - 1), f_op));
  j = BUFF_SIZE - 1;
  while (i >= 0)
    {
      if ((str[i] < 32 || str[i] > 126) && str[i] != '\0')
	j = add_octal_char(buff, j, str[i], f_op);
      else if (str[i] != '\0' && j > 0)
	buff[--j] = str[i];
      i--;
    }
  return (print_item(buff, j, f_op));
}

int	add_octal_char(char *buff, int j, char c, t_format_options *f_op)
{
  char	nb;
  char	*base;
  int	tmp;

  tmp = 1;
  if (f_op->format_function != 1)
    {
      (j > 0) ? (buff[--j] = c) : (buff[j] = c);
      return (j);
    }
  nb = c;
  base = BASE_8;
  while (nb >= 8 && j > 0)
    {
      buff[--j] = base[nb % 8];
      nb = nb / 8;
      tmp++;
    }
  if (j > 0)
    buff[--j] = base[(int)nb];
  while (tmp++ < 3 && j > 0)
    buff[--j] = '0';
  if (j > 0)
    buff[--j] = '\\';
  return (j);
}
