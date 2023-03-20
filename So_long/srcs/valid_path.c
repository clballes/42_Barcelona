#include <stdio.h>
#include "so_long.h"

static int is_valid(int row, int col, int num_rows, int num_cols);
static int is_move_valid(char **map, int row, int col);
static int is_exit(char **map, int row, int col);

// function to check if a given row and column are within the boundstatic s of the map
static int is_valid(int row, int col, int num_rows, int num_cols)
{
    return row >= 0 && row < num_rows && col >= 0 && col < num_cols;
}

// function to check if a given node is a valid move (i.e., not a wall)
static int is_move_valid(char **map, int row, int col)
{
    return map[row][col] != '1';
}

// function to check if a given node is the exit node
static int is_exit(char **map, int row, int col)
{
    return map[row][col] == 'E';
}

// function to perform backtracking on the map
int backtrack(char **map, int row, int col, int num_rows, int num_cols)
{
    // check if the current node is the exit node
    int delta_row[] = {-1, 0, 1, 0};
    int delta_col[] = {0, 1, 0, -1};
    int next_row = 0;
    int next_col = 0;
    int i = 0;

    if (is_exit(map, row, col))
        return 1;
    // mark the curren node as visited
    map[row][col] = 'V';
    // explore the neighbors of the current node
    while(i < 4)
    {
        next_row = row + delta_row[i];
        printf("next row %d\n", next_row);
        printf(" -------- deltaa row %d\n", delta_row[i]);
        printf("next col %d\n", next_col);

        next_col = col + delta_col[i];
        if (is_valid(next_row, next_col, num_rows, num_cols) && is_move_valid(map, next_row, next_col) && map[next_row][next_col] != 'V')
        {
            printf("le map es %c\n", map[next_row][next_col]);
            // recursively explore the next node
            if (backtrack(map, next_row, next_col, num_rows, num_cols))
            {
                return 1;
            }
        }
        i++;
    }
     // check if the next node is a valid move and not visited
    // mark the current node as unvisited
    map[row][col] = '0';
    return 0;
}

int has_valid_path(char **map_arr, t_map *map)     // Find the starting position
{
    int i;
    int j;
    int coll;
    int start;
    int end;

    coll = 0;
    i = 0;
    j = 0;
    start = 0;
    end = 0;
    while (**map_arr && i <= (map->rows - 1))
	{
    	j = 0;
		while (j <= map->cols)
		{
			if (map_arr[i][j] == 'P')
            {
                start = i;
                end = j;
            }
            if (map_arr[i][j] == 'C')
                coll++;
			j++;
		}
        i++;
    }
    printf("coll %d\n", coll);
    printf("start %d\n", start);
    printf("end %d\n", end);
    if (backtrack(map_arr, start, end, map->rows, map->cols))
        printf("Valid path exists!\n");
    else
        printf("No valid path exists!\n");
    return (0);
}