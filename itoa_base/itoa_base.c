#include <stdlib.h>
#include <unistd.h>

int	ft_size_base(int nbr, int base)
{
	int	i;

	i = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int	check_signe(int nbr, int base)
{
	if (base == 10 && nbr < 0)
		return (1);
	return (0);
}

void	ft_putnbr_str(int nbr, int base, char **str)
{
	char	set[] = "0123456789ABCDEF";

	if (nbr > base - 1)
	{
		ft_putnbr_str(nbr / base, base, str);
		ft_putnbr_str(nbr % base, base, str);
	}
	else
	{
		**str = set[nbr];
		(*str)++;
	}
}

char	*itoa_base(int nbr, int base)
{
	int	signe;
	char	*ret;
	char	**p_str;
	int	len;

	signe = 0;
	ret = NULL;
	if (base < 2 || base > 16)
		return (NULL);
	len = ft_size_base(nbr, base) + check_signe(nbr, base);
	ret = (char*)malloc(sizeof(*ret) * len + 1);
	ret[len] = '\0';
	p_str = &ret;
	if (signe)
	{
		**p_str = '-';
		(*p_str)++;
		ft_putnbr_str(nbr, base, p_str);
	}
	else
		ft_putnbr_str(nbr, base, p_str);
	return (ret);
}

int	main(void)
{
	char	*str = itoa_base(18, 16);

	while (str)
		write(1, str++, 1);	
	return (0);
}
