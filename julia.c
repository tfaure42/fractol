/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:56:17 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/12 14:41:46 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	zoom_julia(t_screen *fst, int button, int x, int y)
{
	t_data	*beg;

	beg = fst->beg;
	if (button == 4)
	{
		beg->flag = 2;
		beg->zoom -= 0.5;
		re_fract(fst, fst->beg);
	}
	if (button == 5)
	{
		zoom_i(fst, x, y);
	}
	return (1);
}

static int	mouse_hook(int button, int x, int y, t_screen *fst)
{
	t_data *beg;

	beg = fst->beg;
	if (!beg->flag2)
	{
		beg->flag = 1;
		beg->flag2 = button;
	}
	if (beg->flag2 != button)
	{
		beg->flag = 1;
		beg->flag2 = button;
	}
	if (button == 4 && beg->zoom > 0.6)
	{
		beg->flag -= 1;
		if ((beg->flag) == 0)
			return (zoom_julia(fst, button, x, y));
	}
	if (button == 5)
		if ((beg->flag--) == 0)
			return (zoom_julia(fst, button, x, y));
	if (button == 1)
		motion_on_off(beg);
	return (1);
}

static int	mouse_motion(int x, int y, t_screen *fst)
{
	if (fst->beg->motion == 0)
	{
		fst->beg->realnb = ft_map(x, LEN, -1, 1);
		fst->beg->imaginarynb = ft_map(y, HEIGHT, -1, 1);
		re_fract(fst, fst->beg);
	}
	return (1);
}

void		ft_julia(t_data *beg)
{
	t_screen fst;

	beg->motion = 0;
	beg->tfract = 2;
	beg->flag = 3;
	beg->zoom = 1;
	beg->minvalx = -2;
	beg->maxvalx = 2;
	beg->minvaly = -2;
	beg->maxvaly = 2;
	beg->realnb = 0;
	beg->imaginarynb = 0;
	fst.mlx = mlx_init();
	fst.img = mlx_new_image(fst.mlx, LEN, HEIGHT);
	fst.data = mlx_get_data_addr(fst.img, &fst.bpp, &fst.sizeline, &fst.endian);
	fst.beg = beg;
	ft_init_color(&fst);
	algo_julia(&fst, 0, fst.beg);
	fst.win = mlx_new_window(fst.mlx, LEN, HEIGHT, "Fratol 42");
	mlx_put_image_to_window(fst.mlx, fst.win, fst.img, 0, 0);
	mlx_hook(fst.win, 6, 3, mouse_motion, &fst);
	mlx_hook(fst.win, 4, 3, mouse_hook, &fst);
	mlx_hook(fst.win, 2, 3, my_key_func, &fst);
	mlx_hook(fst.win2, 4, 3, mouse_hook_color, &fst);
	mlx_loop(fst.mlx);
}
