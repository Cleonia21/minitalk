#include "../printf.h"

int	ft_numlen(unsigned int num, unsigned int radix)
{
	int	i;

	i = 0;
	while (num > radix - 1)
	{
		i++;
		num /= radix;
	}
	return (i + 1);
}
