/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:04:58 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/25 19:55:26 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_line_bg(t_o_pt *opt, t_o_pt *apt, t_df *data)
{
	float	err;
	float	err1;

	err1 = 0;
	while (opt->y < apt->y)
	{
		if (opt->x - apt->x > apt->y - opt->y)
			err = (opt->y - apt->y) / (apt->x - opt->x);
		else
			err = (apt->x - opt->x) / (opt->y - apt->y);
		put_pixel_to_img(opt->y, opt->x, data);
		if ((err1 = err + err1) >= 0.5)
		{
			if (opt->x - apt->x > apt->y - opt->y)
				opt->y += 1;
			else
				opt->x -= 1;
			err1 += -1;
		}
		if (opt->x - apt->x > apt->y - opt->y)
			opt->x -= 1;
		else
			opt->y += 1;
	}
}

void		put_line_bd(t_o_pt *opt, t_o_pt *apt, t_df *data)
{
	float	err;
	float	err1;

	err1 = 0;
	while (opt->y < apt->y)
	{
		if (apt->x - opt->x < apt->y - opt->y)
			err = (apt->x - opt->x) / (apt->y - opt->y);
		else
			err = (apt->y - opt->y) / (apt->x - opt->x);
		put_pixel_to_img(opt->y, opt->x, data);
		if ((err1 = err1 + err) >= 0.5)
		{
			if (apt->x - opt->x < apt->y - opt->y)
				opt->x += 1;
			else
				opt->y += 1;
			err1 += -1;
		}
		if (apt->x - opt->x < apt->y - opt->y)
			opt->y += 1;
		else
			opt->x += 1;
	}
}

void		put_line_hor(t_df *data)
{
	if (data->opt.y <= data->apt.y)
		while (data->opt.y <= data->apt.y)
		{
			put_pixel_to_img(data->opt.y, data->opt.x, data);
			++data->opt.y;
		}
	else
		while (data->opt.y >= data->apt.y)
		{
			put_pixel_to_img(data->opt.y, data->opt.x, data);
			--data->opt.y;
		}
}

void		put_line_ver(t_df *data)
{
	if (data->opt.x <= data->apt.x)
		while (data->opt.x <= data->apt.x)
		{
			put_pixel_to_img(data->opt.y, data->opt.x, data);
			++data->opt.x;
		}
	else
		while (data->opt.x >= data->apt.x)
		{
			put_pixel_to_img(data->opt.y, data->opt.x, data);
			--data->opt.x;
		}
}

void		put_line(t_df *data)
{
	if (data->opt.y < data->apt.y && data->opt.x < data->apt.x)
		put_line_bd((&data->opt), (&data->apt), data);
	else if (data->opt.y > data->apt.y && data->opt.x > data->apt.x)
		put_line_bd((&data->apt), (&data->opt), data);
	else if (data->opt.y == data->apt.y)
		put_line_ver(data);
	else if (data->opt.x == data->apt.x)
		put_line_hor(data);
	if (data->opt.y < data->apt.y && data->opt.x > data->apt.x)
		put_line_bg((&data->opt), (&data->apt), data);
	else if (data->opt.y > data->apt.y && data->opt.x < data->apt.x)
		put_line_bg((&data->apt), (&data->opt), data);
}
