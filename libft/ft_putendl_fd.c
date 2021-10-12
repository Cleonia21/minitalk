#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	strlen;

	if (s)
	{
		strlen = ft_strlen(s);
		write(fd, s, strlen);
		write(fd, "\n", 1);
	}
}
