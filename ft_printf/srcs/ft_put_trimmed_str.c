#include "../printf.h"
 

int	ft_put_trimmed_str(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && len-- != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
