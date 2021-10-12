#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	s_len;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen((char *)s);
	if (start >= s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	while (i < len)
	{
		new_str[i] = s[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}
