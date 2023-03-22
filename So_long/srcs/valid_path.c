#include <stdio.h>
#include "so_long.h"

static int is_valid(int row, int col, t_map *map);
static int is_move_valid(char **map_arr, int row, int col);
static int backtrack(char **map_arr, int row, int col, t_map *map);

// function to check if a given row and column are within the boundstatic s of the map_arr
static int is_valid(int row, int col, t_map *map)
{
    return row >= 0 && row < map->rows && col >= 0 && col < map->colscols;
}
// function to check if a given node is a valid move (i.e., not a wall)
static int is_move_valid(char **map_arr, int row, int col)
{
    return map_arr[row][col] != '1';
}

// function to perform backtracking on the map_arr
static int backtrack(char **map_arr, int row, int col, t_map *map)
{
    int next_row;
    int next_col;
    int i;

    next_row = 0;
    next_col = 0;
    i = 0;
    if (map_arr[row][col] == 'E')
        return 1;
    if (map_arr[row][col] == 'C')
        map->coll--;
    map_arr[row][col] = 'V';
    while(i < 4)
    {
        next_row = row + map->delta_row[i];
        next_col = col + map->delta_col[i];
        if (is_valid(next_row, next_col, map) && 
            is_move_valid(map_arr, next_row, next_col) && map_arr[next_row][next_col] != 'V')
        {
            if (backtrack(map_arr, next_row, next_col, map))
                return 1;
        }
        i++;
    }
    map_arr[row][col] = '0';
    return 0;
}

void check_startpos(char **map_arr, t_map *map, int i, int j)// Find the starting position
{
    int coll;
    int start;
    int end;

    coll = 0;
    start = 0;
    end = 0;
    while (**map_arr && i <= (map->rows - 1))
	{
    	j = 0;
		while (j <= map->cols)
		{
			if (map_arr[i][j] == 'P')
            {
                map->start = i;
                map->end = j;
            }
            if (map_arr[i][j] == 'C')
                coll++;
			j++;
		}
        i++;
    }
    map->coll = coll;
}

void    has_valid_path(t_map *map, char **map_arr)
{
    int i;
    int j;

    j = 0;
    i = 0;
    check_startpos(char **map_arr, t_map *map, int i, int j)
    //create a copy of the map
    if (backtrack(map_arr, map->start, map->end, map) && map->coll == '0')
        printf("Valid path exists!\n");
    else
        printf("No valid path exists!\n");
    return (0);

}