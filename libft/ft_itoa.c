#include "libft.h"

static int	ft_numlen(int n)
{
	int		i;

	i = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = -n;
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_makestr(char *str, int n, int sumbol_num)
{
	int		a;

	a = -1;
	if (n < 0)
	{
		str[0] = '-';
		a = 0;
		n = -n;
	}
	str[sumbol_num--] = '\0';
	while (sumbol_num > a)
	{
		str[sumbol_num--] = n % 10 + '0';
		n /= 10;
	}
}

static void	ft_intmin(char *str, int a)
{
	int		i;

	i = 10;
	str[0] = '-';
	str[11] = '\0';
	while (i > 0)
	{
		str[i--] = -(a % 10 - '0');
		a /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		sumbol_num;
	char	*str;

	sumbol_num = ft_numlen(n);
	if (n < 0)
		sumbol_num++;
	str = malloc(sumbol_num + 1);
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		ft_intmin(str, n);
		return (str);
	}
	ft_makestr(str, n, sumbol_num);
	return (str);
}
