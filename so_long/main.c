#include "so_long.h"

int	close_window(t_wins *win)
{
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit (0);
	return (0);
}

int event_manager(int keycode, t_wins *win)
{
	printf("keycode:%d\n",keycode);
	if(keycode == 65307)
		close_window(win);
	return (keycode);
}

int	main()
{
	t_wins	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 500, 500, "so_long");
	mlx_hook(window.win, 2, 1L<<0, event_manager, &window);
	mlx_hook(window.win, 17, 1L<<0, close_window, &window);
	mlx_loop(window.mlx);
	return (0);
}