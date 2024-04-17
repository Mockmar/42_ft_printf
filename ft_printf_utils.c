#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_put_pointeur(unsigned long long nbr, char *base, int nb_char)
{
	unsigned long long	sizeb;
	unsigned long long	nb;

	nb = nbr;
	sizeb = (unsigned long long)ft_strlen(base);
	if (nb < sizeb)
	{
		ft_putchar(base[nb]);
		nb_char++;
	}
	else
	{
		nb_char = ft_put_pointeur(nb / sizeb, base, nb_char);
		ft_putchar(base[nb % sizeb]);
		nb_char++;
	}
	return (nb_char);
}

int	ft_putnbr_base(long long nbr, char *base, int nb_char)
{
	int			sizeb;
	long long	nb;

	nb = nbr;
	sizeb = ft_strlen(base);
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		nb_char++;
	}
	if (nb < sizeb)
	{
		ft_putchar(base[nb]);
		nb_char++;
	}
	else
	{
		nb_char = ft_putnbr_base(nb / sizeb, base, nb_char);
		ft_putchar(base[nb % sizeb]);
		nb_char++;
	}
	return (nb_char);
}

int	ft_comptenbr_base(long long nbr, char *base, int nb_char)
{
	int			sizeb;
	long long	nb;

	nb = nbr;
	sizeb = ft_strlen(base);
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		nb_char++;
	}
	if (nb < sizeb)
	{
		nb_char++;
	}
	else
	{
		nb_char = ft_comptenbr_base(nb / sizeb, base, nb_char);
		nb_char++;
	}
	return (nb_char);
}
