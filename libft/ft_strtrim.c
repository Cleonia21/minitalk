#include "libft.h"

static int	ft_compare(char c, char *set)
{
	int	i;

	i = 0;
	if (!set)
		return (i);
	while (*set)
		if (c == *set++)
			i++;
	return (i);
}

static int	ft_helpmepls(int i, const char *s1, const char *set)
{
	i--;
	while (s1[i] && ft_compare(s1[i], (char *)set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		start;
	char	*new_str;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && ft_compare(s1[i], (char *)set))
		i++;
	if (s1[i] == '\0')
		i = 0;
	start = i;
	while (s1[i])
		i++;
	i = ft_helpmepls(i, s1, set);
	new_str = (char *)malloc(i - start + 2);
	if (!new_str)
		return (NULL);
	while (start <= i)
		new_str[j++] = s1[start++];
	new_str[j] = '\0';
	return (new_str);
}
