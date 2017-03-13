/*
** my_putnbr_float.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 21:58:08 2014 Thibaud Auzou
** Last update Sun Nov 16 21:59:09 2014 Thibaud Auzou
*/

#include "my.h"

int		my_putnbr_float(double nb, t_format_options *f_op)
{
  long int	before;
  long int	after;
  int		neg;

  neg = 0;
  if (nb < 0.0)
    {
      nb = nb * -1.0;
      neg = 1;
    }
  if (f_op->precision > 9)
    f_op->precision = 9;
  before = (int)(nb);
  nb = nb - (double)(before);
  after = convert_to_int(nb, f_op);
  return (add_to_buff(before, after, f_op, neg));
}

int		convert_to_int(double nb, t_format_options *f_op)
{
  int		limit;
  int		i;
  double	tmp;

  (f_op->precision == -1) ? (limit = 6) : (limit = f_op->precision);
  i = 0;
  while (i < limit)
    {
      nb = nb * 10.0;
      i++;
    }
  tmp = nb;
  nb = (long int)(nb);
  tmp = tmp - nb;
  tmp = tmp * 10.0;
  tmp = (int)(tmp);
  return ((tmp <= 5) ? (nb) : (nb + 1));
}

int	add_to_buff(long int before,
		    long int after,
		    t_format_options *f_op,
		    int neg)
{
  char	buff[BUFF_SIZE];
  int	j;
  int	limit;

  (f_op->precision == -1) ? (limit = 6) : (limit = f_op->precision);
  buff[BUFF_SIZE - 1] = '\0';
  j = BUFF_SIZE - 2;
  while (limit > 0 && j >= 0)
    {
      buff[j--] = after % 10 + '0';
      after = after / 10;
      limit--;
    }
  buff[j--] = '.';
  while (before >= 10 && j >= 0)
    {
      buff[j--] = before % 10 + '0';
      before = before / 10;
    }
  if (before > 0 || buff[j + 1] == '.')
    buff[j] = before + '0';
  if (neg && j > 0)
    buff[--j] = '-';
  return (print_item(buff, j, f_op));
}
