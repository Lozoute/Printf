/*
** my.h for my_printf in /home/auzou_t/CPE_2014_my_printf/include
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Nov 16 21:36:29 2014 Thibaud Auzou
** Last update Sun Nov 16 22:17:12 2014 Thibaud Auzou
*/

#ifndef MY_H_
# define MY_H_

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ASCII_NB 48
# define IDENTIFIER '%'
# define NB_FORMAT_F 20
# define BASE_2 "01"
# define BASE_8 "01234567"
# define BASE_10 "0123456789"
# define BASE_16_UP "0123456789ABCDEF"
# define BASE_16_LOW "0123456789abcdef"
# define FORMATS "bSdiuoxXfFeEgGaAcspn%"
# define FLAGS "-+ #0"
# define LEN "hljztL"
# define BUFF_SIZE 50200

# include <stdarg.h>

typedef struct		s_format_options
{
  int			format_function;
  int			flags[6];
  int			width;
  int			precision;
  int			lenght[6];
  int			n;
}			t_format_options;

/*
** My_Printf
*/
int		my_printf(const char *format, ...);
int		parse_expr(const char *format,
			   va_list ap,
			   int (**formatf)(),
			   int *n);

/*
** Basic Lib
*/
int		my_putchar(const char c);
int		my_putstr(char *str, t_format_options *f_op);
int		my_strlen(const char *str);
int		my_put_nbr(int nb);
int		my_getnbr(const char *str);
int		my_putnbr_base(unsigned int nb,
			       char *base,
			       int neg,
			       t_format_options *f_op);
int		add_octal_char(char *buff,
			       int j,
			       char c,
			       t_format_options *f_op);

/*
** Formats And Options Initialisation
*/
int		init_formatf(int (**formatf)());
int		begin_format(const char *str,
			     va_list ap,
			     int (**formatf)(),
			     int *n);
int		find_format_and_options(const char *str,
					t_format_options *f_op,
					va_list ap);
int		was_flag(char c, t_format_options *f_op);
int		was_len(char c, t_format_options *f_op);
int		alrdy_len(t_format_options *f_op);
int		add_specifier(char c, t_format_options *f_op);

/*
** Formats
*/
int		format_b(va_list ap, t_format_options *f_op);
int		format_S(va_list ap, t_format_options *f_op);
int		format_d(va_list ap, t_format_options *f_op);
int		format_i(va_list ap, t_format_options *f_op);
int		format_u(va_list ap, t_format_options *f_op);
int		format_o(va_list ap, t_format_options *f_op);
int		format_x(va_list ap, t_format_options *f_op);
int		format_X(va_list ap, t_format_options *f_op);
int		format_f(va_list ap, t_format_options *f_op);
int		format_F(va_list ap, t_format_options *f_op);
int		format_c(va_list ap, t_format_options *f_op);
int		format_s(va_list ap, t_format_options *f_op);
int		format_p(va_list ap, t_format_options *f_op);
int		format_n(va_list ap, t_format_options *f_op);

/*
** Flags & Width Printing
*/
int		print_item(char *buff, int j, t_format_options *f_op);
int		add_flag_sign(char *buff,
			      int j,
			      t_format_options *f_op,
			      char c);
int		add_flag_sharp(char *buff, int j, t_format_options *f_op);
int		add_flag_sharp_float(char *buff, int j);
int		add_flag_padding(char *buff, int j, t_format_options *f_op);
int		add_flag_precision_integers(char *buff,
					    int j,
					    t_format_options *f_op);

/*
** Float To String Conversion
*/
int		my_putnbr_float(double nb, t_format_options *f_op);
int		convert_to_int(double nb, t_format_options *f_op);
int		add_to_buff(long int before,
			    long  int after,
			    t_format_options *f_op,
			    int neg);

#endif /* !MY_H_ */
