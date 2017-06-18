/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:31:38 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/12 15:53:26 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			my_key_func(int keycode, t_screen *fst)
{
	if (keycode == 53)
	{
		free(fst->beg);
		exit(0);
	}
	re_fract(fst, fst->beg);
	return (1);
}

void		re_fract(t_screen *fst, t_data *beg)
{
	mlx_destroy_image(fst->mlx, fst->img);
	fst->img = mlx_new_image(fst->mlx, LEN, HEIGHT);
	if (beg->tfract == 1)
		algo_mandel(fst, 0, beg);
	else if (beg->tfract == 2)
		algo_julia(fst, 0, beg);
	else if (beg->tfract == 3)
		algo_burning_ship(fst, 0, beg);
	mlx_put_image_to_window(fst->mlx, fst->win, fst->img, 0, 0);
}
