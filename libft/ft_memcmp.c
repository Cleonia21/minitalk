#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char *) s1;
	m2 = (unsigned char *) s2;
	while (n-- > 0)
	{
		if (*m1 - *m2 != 0)
			return (*m1 - *m2);
		m1++;
		m2++;
	}
	return (0);
}
