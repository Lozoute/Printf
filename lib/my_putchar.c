/*
** my_putchar.c for my_printf in /home/auzou_t/CPE_2014_my_printf/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 21:44:08 2014 Thibaud Auzou
** Last update Sun Nov 16 21:44:41 2014 Thibaud Auzou
*/

#include <unistd.h>

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (1);
  return (0);
}
