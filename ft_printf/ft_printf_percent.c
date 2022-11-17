#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
int	ft_printf_percent(char c)
{
	c = '%';
	return (write(1, &c, 1));
}
