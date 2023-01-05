#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		if (verif_val(ac, av))
			ft_putstr("let's go !!!\n");
		else
			ft_putstr("Error\n");
	}
	if (ac == 2)
	{
		if (verif_arg(av[1]))
			ft_putstr("let's go !!!\n");
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
	return (0);
}
