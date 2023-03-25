#include <mlx.h>
#include "so_long.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

int window(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	return 1;
	
}