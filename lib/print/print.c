/*
** print.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib/print
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 22:03:31 2014 Thibaud Auzou
** Last update Sun Nov 16 22:04:46 2014 Thibaud Auzou
*/

#include <unistd.h>
#include "my.h"

int	print_item(char *buff, int j, t_format_options *f_op)
{
  if (f_op->flags[1] > 0)
    j = add_flag_sign(buff, j, f_op, '+');
  else if (f_op->flags[2] > 0)
    j = add_flag_sign(buff, j, f_op, ' ');
  if (f_op->flags[3] > 0)
    j = add_flag_sharp(buff, j, f_op);
  if (f_op->width > BUFF_SIZE - j - 1)
    j = add_flag_padding(buff, j, f_op);
  if (write(1, &(buff[j]), BUFF_SIZE - j - 1) == -1)
    return (-42);
  return (BUFF_SIZE - j - 1);
}

int	add_flag_sign(char *buff, int j, t_format_options *f_op, char c)
{
  int	tmp;

  tmp = f_op->format_function;
  if (tmp == 2 || tmp == 3 || (tmp > 7 && tmp < 16))
    {
      if (buff[j] != '-' && j > 0)
	{
	  j--;
	  buff[j] = c;
	}
    }
  return (j);
}

int	add_flag_sharp(char *buff, int j, t_format_options *f_op)
{
  int	tmp;

  tmp = f_op->format_function;
  if (tmp == 5 && j > 0)
    buff[--j] = '0';
  else if (tmp == 0 || tmp == 6 || tmp == 7 || tmp == 18)
    {
      if (tmp == 0 && j > 0)
	buff[--j] = 'b';
      else if ((tmp == 6 || tmp == 18) && j > 0)
	buff[--j] = 'x';
      else if (j > 0)
	buff[--j] = 'X';
      if (j > 0)
	buff[--j] = '0';
    }
  else if (tmp > 7 && tmp < 16)
    j = add_flag_sharp_float(buff, j);
  return (j);
}

int	add_flag_sharp_float(char *buff, int j)
{
  int	i;

  i = j;
  while (buff[i])
    {
      if (buff[i] == '.')
	return (j);
      i++;
    }
  i = j;
  while (buff[i] && i > 0)
    {
      buff[i - 1] = buff[i];
      i++;
    }
  if (i > 0)
    buff[i - 1] = '.';
  j--;
  return (j);
}

int	add_flag_padding(char *buff, int j, t_format_options *f_op)
{
  char	padd;
  int	i;

  (f_op->flags[4] > 0 && f_op->flags[0] == 0) ? (padd = '0') : (padd = ' ');
  if (f_op->flags[0] == 0)
    {
      while (f_op->width > BUFF_SIZE - j - 1 && j > 0)
	buff[--j] = padd;
    }
  else
    {
      while (f_op->width > BUFF_SIZE - j -1)
	{
	  i = j;
	  while (buff[i] && i > 0)
	    {
	      buff[i - 1] = buff[i];
	      i++;
	    }
	  if (i > 0)
	    buff[i - 1] = padd;
	  j--;
	}
    }
  return (j);
}
