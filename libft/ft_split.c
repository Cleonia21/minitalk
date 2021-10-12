#include "libft.h"

static char	*ft_make_str(char *s, char *str, int len)
{
	char	*s_new;

	s_new = s + len;
	while (len-- > 0)
		*str++ = *s++;
	*str = '\0';
	return (s_new);
}

static int	ft_str(char *s, char c)
{
	int	i;

	i = 0;
	while ((*s != c) && (*s++))
		i++;
	return (i);
}

static int	ft_strlen_sumbol(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s++ == c)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_search(char *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (*s)
	{
		i = ft_str(s, c);
		if (i > 0)
		{
			s += i;
			num++;
		}
		s++;
	}
	return (num);
}

char	**ft_split(char const *s, char c)
{
	char	**mas;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	mas = (char **)malloc(sizeof(char *) * (ft_search((char *)s, c) + 1));
	if (!mas)
		return (NULL);
	while (*s)
	{
		len = ft_strlen_sumbol((char *)s, c);
		if (len > 0)
		{
			mas[i] = (char *)malloc(len + 1);
			if (mas[i] == NULL)
				return (NULL);
			s = ft_make_str((char *)s, mas[i++], len);
		}
		else
			s++;
	}
	mas[i] = NULL;
	return (mas);
}
