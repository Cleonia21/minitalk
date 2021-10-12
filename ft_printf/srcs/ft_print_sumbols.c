#include "../printf.h"
 

int	ft_print_sumbols(char c, int num)
{
	int	i;

	i = num;
	if (num < 0)
		return (0);
	while (i-- > 0)
		write(1, &c, 1);
	return (num);
}
