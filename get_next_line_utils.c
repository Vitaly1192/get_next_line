#include "get_next_line.h"

void	*ft_calloc(size_t number, size_t size)
{
	unsigned char	*point;
	size_t			k;
	size_t			range;

	range = number * size;
	k = 0;
	point = (unsigned char *)malloc(range);
	if (point != NULL)
		while (k != range)
			*(point + k++) = '\0';
	return (point);
}

size_t		ft_strlen(const char *str)
{
	char const *str_cpy;

	str_cpy = str;
	while (*str != '\0')
		str++;
	return (str - str_cpy);
}

char	*ft_strchr(char *str, int c)
{
	size_t	k;

	k = 0;
	while (str[k] != '\0')
	{
		if (str[k] == c)
			return ((str + k));
		k++;
	}
	if (str[k] == c)
		return ((str + k));
	return (NULL);
}

char	*ft_strrchr(const char *str, int c)
{
	size_t		k;
	char		ch;
	const char	*p_ch;

	p_ch = NULL;
	ch = (char)c;
	k = 0;
	while (*(str + k) != '\0')
	{
		if (*(str + k) == ch)
			p_ch = str + k;
		k++;
	}
	if (*(str + k) == ch)
		return ((char *)(str + k));
	return ((char *)p_ch);
}


char	*ft_strdup(const char *str)
{
	size_t	k;
	char	*dup;

	dup = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	k = 0;
	if (dup != NULL)
		while (str[k] != '\0')
		{
			dup[k] = str[k];
			k++;
		}
	return (dup);
}
