#include <stdio.h>
#include <unistd.h>

char	*ft_hexadecimal(int j);
int     ft_printf_hexad_upp(int i)
{
        int cont;
        char *str;
        
	str = ft_hexadecimal(i);
        cont = 0;
        while (str[cont] != '\0')
        {       
                if (str[cont] >= 97 && str[cont] <= 102)
                        str[cont] -= 32;        
        cont ++;
        }
        return(cont);
}
int main()
{
	int i;
	i = 590;

	char *str;
	str = ft_printf_hexad_upp(i);
	printf("%s",str);
}
