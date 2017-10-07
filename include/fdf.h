/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 20:33:00 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/29 14:58:04 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_info_fct_mlx
{
	int				*img;
	void			*id;
	void			*win;
	void			*img_id;
}					t_ifm;

typedef struct		s_arrive_point
{
	float			x;
	float			y;
}					t_a_pt;

typedef struct		s_zoom
{
	int				zoom;
	float			haut;
}					t_zoom;

typedef struct		s_moove
{
	int				x;
	int				y;
}					t_moove;

typedef struct		s_matrice_du_futur
{
	float			m1;
	float			m2;
	float			m3;
	float			m4;
	float			m5;
	float			m6;
}					t_matrice;

typedef struct		s_origine_point
{
	float			x;
	int				haut;
	float			y;
}					t_o_pt;

typedef struct		s_info_map
{
	float			**map;
	int				map_max_la;
	int				map_max_lon;
}					t_im;

typedef struct		s_tools_for_img
{
	int				bpp;
	int				size_line;
	int				lobe;
}					t_tfi;

typedef union		u_color
{
	unsigned char	clr_o[4];
	unsigned int	color;
}					t_clr;

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_data_fdf
{
	t_res			res;
	t_clr			color;
	t_tfi			tfi;
	t_moove			mv;
	t_zoom			zm;
	t_im			im;
	t_ifm			ifm;
	t_o_pt			opt;
	t_matrice		matrice;
	t_o_pt			apt;
}					t_df;

int					init_win(t_df *data);
int					get_data(int ac, char **av, t_df *data);
int					check_arg(int ac, char **av, int *nb_line);
int					pars_map(char *map_char);
void				disp_img(t_df *df);
int					load_img(t_df *df);
void				set_color(unsigned char r, unsigned char g, unsigned char b,
						t_clr *clr);
void				put_pixel_to_img(int pos_y, int pos_x, t_df *df);
void				put_line(t_df *data);
void				fdf_disp(t_df *df);
void				init_matrice(t_matrice *matrice);
void				init_pos_start(t_df *data);

#endif
