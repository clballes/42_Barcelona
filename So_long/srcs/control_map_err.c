#include "../inc/so_long.h"
#include "../inc/get_next_line.h"
#include "libft.h"
static void	check_coll(char **map_arr, int rows, int cols);

void	check_map(char **map_arr, int rows, int cols) //no acaba dentrar els 1 i 0 com a char 
{
	int	i;

	i = 0;
	while (map_arr[0][i] == '1' && map_arr[rows][i] == '1' && i <= cols) //row primera i row ultima
	{
		if (map_arr[0][i] != '1' || map_arr[rows][i] != '1')
		{
			
			write_error();
		}
		else
			i++;
	}
	i = 0;
	while(map_arr[i][0] == '1' && map_arr[i][(cols - 2)] == '1')
	{
		if (map_arr[i][0] != '1' || map_arr[i][(cols - 2)] != '1')
			write_error();
		else
			i++;
	}
	check_coll(map_arr, rows, cols);
}

static void	check_coll(char **map_arr, int rows, int cols)
{
	int i;
	int j;
	int idx;

	idx = 0;
	i = 0;
	while(**map_arr && i <= rows)
	{
		j = 0;
		while(map_arr[i][j] && j <= cols)
		{
			if (map_arr[i][j] == 'C')
				idx++;
			else if (map_arr[i][j] == 'E')
				idx++;
			else if (map_arr[i][j] == 'P')
				idx++;
			j++;
			//else if (map_arr[i][j] != '0' || map_arr[i][j] != '1')
			// {
			// 	printf("el map es %c\n", map_arr[i][j]);
			// 	printf("el idx es %d\n", idx);
			// 	idx++;
			// }
		}	
		i++;
	}
	if (idx != 3)
		write_error();
}