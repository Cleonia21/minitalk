#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	strlen;

	if (s)
	{
		strlen = ft_strlen(s);
		write(fd, s, strlen);
	}
}
