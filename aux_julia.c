/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 11:48:55 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/12 13:17:52 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_i(t_screen *fst, int x, int y)
{
	float	xlen;
	float	ylen;
	float	temp;
	t_data	*beg;

	beg = fst->beg;
	beg->flag = 2;
	temp = (-1 * (beg->minvalx - beg->maxvalx)) / 2;
	xlen = ft_map(x, LEN, beg->minvalx, beg->maxvalx);
	ylen = ft_map(y, HEIGHT, beg->minvaly, beg->maxvaly);
	beg->minvalx = xlen - temp;
	beg->maxvalx = xlen + temp;
	temp = (-1 * (beg->minvaly - beg->maxvaly)) / 2;
	beg->minvaly = ylen - temp;
	beg->maxvaly = ylen + temp;
	beg->zoom += 0.3;
	re_fract(fst, fst->beg);
}

void		motion_on_off(t_data *beg)
{
	if (beg->motion == 0)
		beg->motion = 1;
	else if (beg->motion == 1)
		beg->motion = 0;
}
