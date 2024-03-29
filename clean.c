/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:41:39 by tfaure            #+#    #+#             */
/*   Updated: 2017/06/21 18:47:30 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		clean(t_screen *fst)
{
	int y;
	int x;
	int color;

	color = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < LEN)
		{
			if (fst->data != NULL)
				((unsigned int *)fst->data)[x + y * LEN] = color;
			x++;
		}
		y++;
	}
	return (1);
}
