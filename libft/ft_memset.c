#include "libft.h"

void	*ft_memset(void *mas, int c, size_t len)
{
	char	*p;

	p = (char *)mas;
	while (len-- > 0)
		*p++ = c;
	return (mas);
}
