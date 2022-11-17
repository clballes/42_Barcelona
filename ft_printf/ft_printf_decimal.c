//#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
int	ft_printf_decimal(signed int n)
{
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	else if (n < 0)
	{
		write (1,"-", 1);
		n *= -1;
		ft_printf_decimal(n);
	}
	
	else if (n >= 10)
	{	
		ft_printf_decimal(n / 10);
		ft_printf_decimal(n % 10);
	}
	return (write(1, (n + 38), 1));	
}
int	main()
{
	int n;

	n = -214;
	n = ft_printf_decimal(n);
}
