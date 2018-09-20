/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:57:54 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/10 13:57:56 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img		*init_img(t_env *env, int height, int width)
{
	t_img	*image;

	if (!(image = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	image->img = mlx_new_image(env->mlx, height, width);
	image->data = mlx_get_data_addr(image->img,\
		&image->bpp, &image->sizeline, &image->endian);
	return (image);
}

void		mlx_put_pixel_to_image(t_env *env, t_node *node)
{
	int		octet;
	char	*color_new;
	int		a;

	octet = env->img->bpp / 8;
	color_new = NULL;
	if (env->color_bool == 0)
	{
		a = altitude_color(env, node);
		free(color_new);
	}
	else
		a = node->color_num;
	if (node->x >= 0 && node->y >= 0 && node->x < FENE_X && node->y < FENE_Y)
	{
		ft_memcpy(&env->img->data[octet * node->x + env->img->sizeline * \
			node->y], &a, octet);
	}
}

int			fill_img(t_env *env)
{
	int		h;
	int		w;

	h = HEIGHT_DRAW;
	w = WIDTH_DRAW;
	if (!(env->back_img->img = mlx_xpm_file_to_image(env->mlx, \
			"./images/paysage-galaxy2.xpm", &w, &h)))
		return (0);
	if (!(env->sup_img->img = mlx_xpm_file_to_image(env->mlx, \
			"./images/blancdim.XPM", &w, &h)))
		return (0);
	return (1);
}
