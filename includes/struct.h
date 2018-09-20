/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:28:27 by wfoulon           #+#    #+#             */
/*   Updated: 2017/12/14 11:28:57 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_img;

typedef	struct		s_node
{
	int				x;
	int				y;
	int				z;
	int				color_num;
	float			rap;
}					t_node;

typedef	struct		s_mat
{
	int				x;
	int				y;
	int				z;
	int				c;
}					t_mat;

typedef	struct		s_coord
{
	int				z_min;
	int				z_max;
}					t_coord;

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_img			*back_img;
	t_img			*sup_img;
	t_node			**map;
	int				len_x;
	int				len_y;
	t_coord			*coord;
	int				x;
	int				y;
	float			zoom;
	int				trans_x;
	int				trans_y;
	float			moove_z;
	int				rot_x;
	int				rot_y;
	int				rot_z;
	int				proj;
	int				color_bool;
	char			*filename;
	t_mat			mat;
}					t_env;

#endif
