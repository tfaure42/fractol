/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:46:15 by myernaux          #+#    #+#             */
/*   Updated: 2017/03/12 11:40:42 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

void	ft_fractol_available(void)
{
	ft_putendl("Mandelbrot");
	ft_putendl("Julia");
	ft_putendl("Burning ship");
}

int		main(int ac, char **av)
{
	t_data *beg;

	if (!(beg = (t_data *)malloc(sizeof(t_data))))
		return (0);
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Julia") == 0)
			ft_julia(beg);
		else if (ft_strcmp(av[1], "Mandelbrot") == 0)
			ft_mandel(beg);
		else if (ft_strcmp(av[1], "Burning ship") == 0)
			ft_burning_ship(beg);
		else
			ft_fractol_available();
	}
	else
		ft_error("./fractol [FILE]");
}
