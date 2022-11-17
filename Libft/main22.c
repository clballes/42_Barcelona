#include <stdio.h>
#include "libft.h"
char	*ft_itoa(int n);
int	main ()
{
	int	n = '1234';
	char *resultado;

 	resultado = ft_itoa(n);
	printf("%s\n", resultado);
}
