#include "libft.h"
int	ft_len_number(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return(i);
}

char	*ft_itoa(int n)
{
	char 	*str;
	int	i;
	int	len;

	i = 0;
	len = ft_len_number(n);	
	str = malloc(sizeof(char) * (len + 1));
	if (!str)	
		return (NULL);
	if (n == -2147483648)
		return(ft_strdup(str));
	if (n < 0)
	{
		str[0] = '-';
		n *= -n;
	}
	else 
	i = 0;	
	while (len-- > i)
	{ 
		if (n < 0) 
		{	
			str[len] = '0' + n % 10 * (-1);
			n = n / 10;	
		}
		else
		{
			str[len] = '0' + n % 10;
			n = n / 10;
		}
	}
	str[i] = '\0';
	return (ft_strdup(str));	
}
