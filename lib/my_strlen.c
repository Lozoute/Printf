/*
** my_strlen.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 22:01:45 2014 Thibaud Auzou
** Last update Sun Nov 16 22:01:56 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "my.h"

int		my_strlen(const char *str)
{
  unsigned int	i;

  i = 0;
  while (str != NULL && str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
