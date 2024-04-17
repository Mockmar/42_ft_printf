#include "ft_printf.h"

int	print_c(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	print_s(va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_p(va_list ap)
{
	unsigned long long	p;
	int					nb_char;

	nb_char = 0;
	p = va_arg(ap, unsigned long long);
	write(1, "0x", 2);
	nb_char += 2;
	nb_char += ft_put_pointeur(p, "0123456789abcdef", 0);
	return (nb_char);
}

int	print_d(va_list ap)
{
	int	nb_char;
	int	d;

	nb_char = 0;
	d = va_arg(ap, int);
	nb_char += ft_putnbr_base((long long)d, "0123456789", 0);
	return (nb_char);
}

int	print_i(va_list ap)
{
	int	nb_char;
	int	i;

	nb_char = 0;
	i = va_arg(ap, int);
	nb_char += ft_putnbr_base((long long)i, "0123456789", 0);
	return (nb_char);
}
