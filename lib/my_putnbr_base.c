/*
** my_putnbr_base.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 21:54:30 2014 Thibaud Auzou
** Last update Sun Nov 16 21:57:18 2014 Thibaud Auzou
*/

#include <unistd.h>
#include "my.h"

int	add_flag_precision_integers(char *buff, int j, t_format_options *f_op)
{
  while (f_op->precision > BUFF_SIZE - j - 1 && j > 0)
    buff[--j] = '0';
  return (j);
}

int		my_putnbr_base(unsigned int nbr,
			      char *base,
			      int neg,
			      t_format_options *f_op)
{
  char		buff[BUFF_SIZE];
  int		j;
  unsigned int	nb_base;

  nb_base = my_strlen(base);
  j = BUFF_SIZE - 2;
  buff[BUFF_SIZE - 1] = '\0';
  while (nbr >= nb_base && j > 0)
    {
      buff[j] = base[nbr % nb_base];
      nbr = nbr / nb_base;
      j = j - 1;
    }
  if (j >= 0 && nbr < 128)
    buff[j] = base[nbr];
  if (f_op->precision == 0 && buff[j] == '0' && buff[j + 1] == '\0')
    return (0);
  if (f_op->precision > BUFF_SIZE - j - 1)
    j = add_flag_precision_integers(buff, j, f_op);
  if (neg && j > 0)
    buff[--j] = '-';
  return (print_item(buff, j, f_op));
}
