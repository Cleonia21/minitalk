#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		strlen;
	char	*new_str;

	i = 0;
	if (!s)
		return (NULL);
	strlen = ft_strlen((char *)s);
	new_str = (char *)malloc(strlen + 1);
	if (!new_str)
		return (NULL);
	while (strlen-- > 0)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
