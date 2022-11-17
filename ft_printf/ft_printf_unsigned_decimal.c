//#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
//no permet cap negatiu el unsigned
int     ft_printf_unsigned_decimal(unsigned int n)
{
        if (n == 2147483648)
                return (write (1, "2147483648", 10));
        else if (n >= 10)
        {
                ft_printf_unsigned_decimal(n / 10);
                ft_printf_unsigned_decimal(n % 10);
        }
        //return (write(1, (n + 38), 1));
	return(0);
}
int     main()
{
        int n;

        n = -214;
        n = ft_printf_unsigned_decimal(n);
}

