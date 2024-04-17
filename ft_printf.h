#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		filtre(char flag, va_list ap);
int		print_c(va_list ap);
int		print_s(va_list ap);
int		print_p(va_list ap);
int		print_d(va_list ap);
int		print_i(va_list ap);
int		print_u(va_list ap);
int		print_x(va_list ap);
int		print_up_x(va_list ap);
int		ft_comptenbr_base(long long nbr, char *base, int nb_char);
int		ft_put_pointeur(unsigned long long nbr, char *base, int nb_char);
int		ft_putnbr_base(long long nbr, char *base, int nb_char);
void	ft_putchar(char c);
size_t	ft_strlen(char *str);

#endif
