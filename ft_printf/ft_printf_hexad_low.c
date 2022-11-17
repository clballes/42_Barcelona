#include <stdio.h>
#include <unistd.h>
char	*ft_hexadecimal(int j);
int	ft_printf_hexad_low(int i)
{
	int cont;
	char *str;
	str = ft_hexadecimal(i);
	cont = 0;
	while (str[cont] != '\0')
	{
		if (str[cont] >= 65 && str[cont] <= 70)
			str[cont] += 32; 
	cont ++;
	}
	return(cont);
}
