/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:14:30 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/29 14:51:22 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		first_calc_iso(t_df *df, t_o_pt *prime, t_o_pt cor, int *i)
{
	prime[0].x = df->matrice.m1 * (cor.x - cor.y);
	prime[0].y = (df->matrice.m6 * (df->im.map[i[0]][i[1]] * df->zm.haut)) -
					(df->matrice.m4 * (cor.x + cor.y));
	df->opt.haut = df->im.map[i[0]][i[1]] * df->zm.haut;
	if (prime[0].y < 0)
		prime[0].y = -prime[0].y;
	else
		prime[0].y = -prime[0].y;
	df->opt = prime[0];
}

void		calc_iso(t_df *df, t_o_pt *prime, t_o_pt cor, int *i)
{
	prime[1].x = df->matrice.m1 * (cor.x - cor.y);
	prime[1].y = (df->matrice.m6 * (df->im.map[i[0]][i[1]] * df->zm.haut)) -
				(df->matrice.m4 * (cor.x + cor.y));
	df->opt.haut = df->im.map[i[0]][i[1]] * df->zm.haut;
	if (prime[1].y < 0)
		prime[1].y = -prime[1].y;
	else
		prime[1].y = -prime[1].y;
	df->apt = prime[1];
	put_line(df);
	prime[0].x = prime[1].x;
	prime[0].y = prime[1].y;
	df->opt = prime[0];
}

void		fdf_disp_hor(t_df *df)
{
	int		i[2];
	t_o_pt	prime[2];
	t_o_pt	cor;

	i[0] = 0;
	cor.x = df->mv.x;
	cor.y = df->mv.y;
	while (i[0] <= df->im.map_max_lon)
	{
		i[1] = 0;
		first_calc_iso(df, prime, cor, i);
		while (i[1] < df->im.map_max_la)
		{
			cor.x += df->zm.zoom;
			++i[1];
			calc_iso(df, prime, cor, i);
		}
		cor.x = df->mv.x;
		++i[0];
		cor.y += df->zm.zoom;
		i[1] = 0;
	}
}

void		fdf_disp_ver(t_df *df)
{
	int		i[2];
	t_o_pt	prime[2];
	t_o_pt	cor;

	i[1] = 0;
	cor.x = df->mv.x;
	cor.y = df->mv.y;
	while (i[1] <= df->im.map_max_la)
	{
		i[0] = 0;
		first_calc_iso(df, prime, cor, i);
		while (i[0] < df->im.map_max_lon)
		{
			cor.y += df->zm.zoom;
			++i[0];
			calc_iso(df, prime, cor, i);
		}
		cor.x += df->zm.zoom;
		cor.y = df->mv.y;
		++i[1];
		i[0] = 0;
	}
}

void		fdf_disp(t_df *df)
{
	fdf_disp_ver(df);
	fdf_disp_hor(df);
}
