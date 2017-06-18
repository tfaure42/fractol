/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:29:25 by myernaux          #+#    #+#             */
/*   Updated: 2017/03/12 15:03:23 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_color(t_screen *fst, int n)
{
	if (n == 0)
		return (fst->colortable->color1 = 0x00FF0000);
	else if (n == 1)
		return (fst->colortable->color2 = 0x0000FF00);
	else if (n == 2)
		return (fst->colortable->color3 = 0x000000FF);
	else if (n == 3)
		return (fst->colortable->color4 = 0x00DDDDDD);
	return (0);
}

static void	ft_square(t_screen *fst, int px, int py, int color)
{
	int x;
	int y;

	y = -1;
	while (y++ < 100)
	{
		x = -1;
		while (x++ < 100)
		{
			if (fst->data2 != NULL)
				((unsigned int *)fst->data2)[(px + x) + (py + y) * 200] = color;
		}
	}
}

void		ft_init_color(t_screen *fst)
{
	int x;
	int y;
	int n;
	int color;

	n = 0;
	y = 0;
	fst->win2 = mlx_new_window(fst->mlx, 200, 200, "Chose your color");
	fst->img2 = mlx_new_image(fst->mlx, 200, 200);
	fst->data2 = mlx_get_data_addr(fst->img2, &fst->bpp, \
			&fst->sizeline, &fst->endian);
	while (y <= 100)
	{
		x = 0;
		while (x <= 100)
		{
			color = set_color(fst, n);
			ft_square(fst, x, y, color);
			x += 100;
			n++;
		}
		y += 100;
	}
	mlx_put_image_to_window(fst->mlx, fst->win2, fst->img2, 0, 0);
}

int			mouse_hook_color(int button, int x, int y, t_screen *fst)
{
	if (button == 1)
	{
		if ((x >= 0 && x <= 100) && (y >= 0 && y <= 100))
			fst->colortable->curcol = fst->colortable->color1;
		else if ((x >= 100 && x <= 200) && (y >= 0 && y <= 100))
			fst->colortable->curcol = fst->colortable->color2;
		else if ((x >= 0 && x <= 100) && (y >= 100 && y <= 200))
			fst->colortable->curcol = fst->colortable->color3;
		else if ((x >= 100 && x <= 200) && (y >= 100 && y <= 200))
			fst->colortable->curcol = fst->colortable->color4;
	}
	re_fract(fst, fst->beg);
	return (1);
}
