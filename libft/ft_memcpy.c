#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*take;
	char	*give;

	if (dst == NULL && src == NULL)
		return (NULL);
	take = (char *)dst;
	give = (char *)src;
	while (n-- > 0)
		*take++ = *give++;
	return (dst);
}
