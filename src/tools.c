/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:31:50 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/25 17:33:07 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"

void			disp_img(t_df *df)
{
	mlx_put_image_to_window(df->ifm.id, df->ifm.win, df->ifm.img_id, 0, 0);
	mlx_destroy_image(df->ifm.id, df->ifm.img_id);
}

int				load_img(t_df *df)
{
	if ((df->ifm.img_id = mlx_new_image(df->ifm.id, df->res.x,
										df->res.y)) == NULL)
		return (-1);
	df->ifm.img = (int *)mlx_get_data_addr(df->ifm.img_id, &(df->tfi.bpp),
										&(df->tfi.size_line), &(df->tfi.lobe));
	return (0);
}

void			set_color(unsigned char r, unsigned char g,
						unsigned char b, t_clr *clr)
{
	clr->clr_o[0] = b;
	clr->clr_o[1] = g;
	clr->clr_o[2] = r;
	clr->clr_o[3] = 0;
}

void			put_pixel_to_img(int pos_y, int pos_x, t_df *df)
{
	if (pos_y >= df->res.y || pos_x >= df->res.x)
		return ;
	if (pos_y <= 0 || pos_x <= 0)
		return ;
	if (df->opt.haut < 1)
		set_color(0, 0, 255, &(df->color));
	if (df->opt.haut > 1 && df->opt.haut < 8)
		set_color(0, 255, 0, &(df->color));
	if (df->opt.haut > 7 && df->opt.haut < 25)
		set_color(102, 51, 0, &(df->color));
	if (df->opt.haut >= 25)
		set_color(255, 255, 255, &(df->color));
	df->ifm.img[pos_y * df->res.x + pos_x] = df->color.color;
}
