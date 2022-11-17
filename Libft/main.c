#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <libft.h>

int	main()
{
	begin = NULL;
    ft_lstadd_back(&begin, elem);
    ft_lstadd_back(&begin, elem2);
    ft_lstadd_back(&begin, elem3);
    ft_lstadd_back(&begin, elem4);
    while (begin)
    {
        ft_print_result(begin);
        begin = begin->next;
    }


}
