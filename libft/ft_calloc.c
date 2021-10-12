#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*object;

	object = malloc(count * size);
	if (object == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		object[i] = 0;
		i++;
	}
	return (object);
}
