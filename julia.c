/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacrois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 21:07:28 by alacrois          #+#    #+#             */
/*   Updated: 2017/12/11 22:58:55 by alacrois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		get_j_divergence(t_complex c, t_complex j_arg, int iterations)
{
	int			i;
	t_complex	z;
	double		tmp;

	i = -1;
	z.real = c.real;
	z.im = c.im;
	while (++i < iterations)
	{
		tmp = (z.real * z.real) - (z.im * z.im) + j_arg.real;
		z.im = (2 * (z.real * z.im)) + j_arg.im;
		z.real = tmp;
		if (((z.real * z.real) + (z.im * z.im)) > 4)
			return (i);
	}
	return (i);
}

void			julia(t_hook_arg *harg, t_point pix, t_point origin, \
				double limit)
{
	t_complex	c;
	t_rgb		color;
	int			divergence;
	t_fractal	*f;

	f = (t_fractal *)harg->data;
	color.r = 0;
	color.g = (char)255;
	color.b = 0;
	color.trans = 0;
	c.real = ((double)pix.x / limit) / f->zoom;
	c.im = ((double)pix.y / limit) / f->zoom;
	c.real = c.real + f->center.x;
	c.im = c.im + f->center.y;
	divergence = get_j_divergence(c, f->julia_arg, f->max_iterations);
	color = fractal_color(harg, divergence);
	ftx_img_pixel_put(harg->i, origin.x + pix.x, origin.y + pix.y, color);
}
