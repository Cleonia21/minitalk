#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	char	*s2;

	s1 = (char *)s;
	s2 = NULL;
	if (c == 0)
		return (s1 + ft_strlen(s1));
	while (*s1)
	{
		s1 = ft_memchr(s1, c, ft_strlen(s1) + 1);
		if (s1 == NULL)
			return (s2);
		s2 = (char *)s1;
		s1++;
	}
	return (s2);
}
