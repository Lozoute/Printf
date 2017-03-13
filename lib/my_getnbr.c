/*
** my_getnbr.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 21:41:07 2014 Thibaud Auzou
** Last update Sun Nov 16 21:41:33 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int	is_that_neg(int first, const char *str)
{
  if (first == 0)
    return (0);
  else if (str[first - 1] == '-')
    return (1);
  return (0);
}

int	get_first_last(int *p_first, int *p_last, const char *str)
{
  *p_first = 0;
  while (str[*p_first] < '1' || str[*p_first] > '9')
    {
      if (str[*p_first] == '\0')
	return (1);
      if (str[*p_first] != '+' || str[*p_first] != '-')
	return (1);
      (*p_first) = (*p_first) + 1;
    }
  *p_last = *p_first;
  while ((str[*p_last] >= '0' && str[*p_last] <= '9'))
    (*p_last) = (*p_last) + 1;
  (*p_last) = (*p_last) - 1;
  return (0);
}

int	is_out_of_range(int first, int last, int is_neg, const char *str)
{
  char	*max_int;
  int	i;

  if (last - first + 1 > 10)
    return (1);
  else if (last - first + 1 < 10)
    return (0);
  else
    {
      i = 0;
      max_int = "2147483647";
      if (is_neg)
	max_int = "2147483648";
      while (first <= last)
	{
	  if (str[first] > max_int[i])
	    return (1);
	  i = i + 1;
	  first = first + 1;
	}
    }
  return (0);
}

int	get_the_nb(int first, int last, int is_neg, const char *str)
{
  int	power;
  int	i;
  int	nb;

  nb = 0;
  i = first;
  power = 1;
  while (i < last)
    {
      power = power * 10;
      i = i + 1;
    }
  while (first <= last)
    {
      nb = nb + ((str[first] - ASCII_NB) * power);
      first = first + 1;
      power = power / 10;
    }
  if (is_neg)
    nb = nb * -1;
  return (nb);
}

int	my_getnbr(const char *str)
{
  int	first;
  int	last;
  int	*p_first;
  int	*p_last;
  int	is_neg;

  if (str == NULL)
    return (0);
  p_first = &first;
  p_last = &last;
  if (get_first_last(p_first, p_last, str))
    return (0);
  is_neg = is_that_neg(first, str);
  if (is_out_of_range(first, last, is_neg, str))
    return (0);
  return (get_the_nb(first, last, is_neg, str));
}
