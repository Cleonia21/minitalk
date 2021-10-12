#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*new_str;

	len = ft_strlen((char *)str);
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	while (*str)
		*new_str++ = *str++;
	*new_str = '\0';
	return (new_str - len);
}
