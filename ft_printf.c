#include "ft_printf.h"

int	print_u(va_list ap)
{
	int				nb_char;
	unsigned int	u;

	nb_char = 0;
	u = va_arg(ap, unsigned int);
	nb_char += ft_putnbr_base((long long)u, "0123456789", 0);
	return (nb_char);
}

int	print_x(va_list ap)
{
	int	nb_char;
	int	x;
	int	i;

	nb_char = 0;
	i = 0;
	x = va_arg(ap, long long);
	if (x >= 0)
		nb_char += ft_putnbr_base(x, "0123456789abcdef", 0);
	else
	{
		x = -x - 1;
		nb_char = ft_comptenbr_base(x, "0123456789abcdef", 0);
		while (i + nb_char < 8)
		{
			write(1, "f", 1);
			i++;
		}
		nb_char += ft_putnbr_base(x, "fedcba9876543210", 0);
		nb_char = 8;
	}
	return (nb_char);
}

int	print_up_x(va_list ap)
{
	int	nb_char;
	int	up_x;
	int	i;

	nb_char = 0;
	i = 0;
	up_x = va_arg(ap, long long);
	if (up_x >= 0)
		nb_char += ft_putnbr_base(up_x, "0123456789ABCDEF", 0);
	else
	{
		up_x = -up_x - 1;
		nb_char = ft_comptenbr_base(up_x, "0132456789ABCDEF", 0);
		while (i + nb_char < 8)
		{
			write(1, "F", 1);
			i++;
		}
		nb_char += ft_putnbr_base(up_x, "FEDCBA9876543210", 0);
		nb_char = 8;
	}
	return (nb_char);
}

int	filtre(char flag, va_list ap)
{
	if (flag == 'c')
		return (print_c(ap));
	else if (flag == 's')
		return (print_s(ap));
	else if (flag == 'p')
		return (print_p(ap));
	else if (flag == 'd')
		return (print_d(ap));
	else if (flag == 'i')
		return (print_i(ap));
	else if (flag == 'u')
		return (print_u(ap));
	else if (flag == 'x')
		return (print_x(ap));
	else if (flag == 'X')
		return (print_up_x(ap));
	else if (flag == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		nb_char;
	va_list	ap;

	i = 0;
	nb_char = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			nb_char += filtre(format[i + 1], ap);
			i += 2 ;
		}
		else if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			nb_char++;
		}
	}
	va_end(ap);
	return (nb_char);
}
