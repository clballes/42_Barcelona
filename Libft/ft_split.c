#include "libft.h"
int	ft_countword(char *s)
{
	int	i;	
	int 	n;

	i = 0;
	n = 0;
	if(!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i + 1] == 32)
		{	
			i++;
			n++;
		}	
		else
			i++;
	}
	n++;
	return (n);
	
}
char	*ft_searchword (char *s)
{
	int	j;
	int	i;
	char	*str;
	
	i = 0;	

	j = ft_strlen(s);
	str = ft_substr(s, 0, j + 1);
	if (!s)
		return (0);
	return (str);
}

char	**free_split(char const **tab)
{
	unsigned	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i])
		i ++;
	}
	tab(s);
	return (NULL);
}
