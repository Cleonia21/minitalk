#include "libft.h"

#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[13];
	int		i;

	if (n == 0)
		ft_putstr_fd("0", fd);
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		i = ft_numlen(n);
		if (n < 0)
		{
			str[0] = '-';
			n = -n;
			i++;
		}
		str[i] = '\0';
		i--;
		while (n > 0)
		{
			str[i--] = n % 10 + '0';
			n /= 10;
		}
		ft_putstr_fd(str, fd);
	}
}
