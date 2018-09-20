/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:10:42 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/11 16:10:44 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node			*new_coord(t_env *env, t_node *node)
{
	t_mat		mat;
	int			x_cen;
	int			y_cen;
	t_coord		*ext;

	ext = env->coord;
	x_cen = FENE_X / 2;
	y_cen = FENE_Y / 2;
	which_proj(env, &mat, node);
	mat.c = mat.x;
	mat.x = x_cen + (mat.x - x_cen) * cos(THETA * env->rot_z) - \
			(mat.y - y_cen) * sin(THETA * env->rot_z);
	mat.y = y_cen + (mat.c - x_cen) * sin(THETA * env->rot_z) +\
			(mat.y - y_cen) * cos(THETA * env->rot_z);
	mat.x = env->zoom * mat.x + 15 * env->trans_x;
	mat.y = env->zoom * mat.y + 15 * env->trans_y;
	mat.z = env->zoom * mat.z;
	return (init_node((int)mat.x, (int)mat.y, (int)mat.z, node->color_num));
}

void			get_transform(t_env *env, t_node **map)
{
	int			i;
	int			j;
	t_node		*new;
	t_node		*start;

	j = 0;
	start = new_coord(env, &map[0][0]);
	env->coord->z_min = start->z;
	env->coord->z_max = start->z;
	free(start);
	while (j < env->len_y)
	{
		i = 0;
		while (i < env->len_x)
		{
			new = new_coord(env, &map[j][i]);
			if (new->z > env->coord->z_max)
				env->coord->z_max = new->z;
			if (new->z < env->coord->z_min)
				env->coord->z_min = new->z;
			free(new);
			i++;
		}
		j++;
	}
}

void			draw_segment(t_env *env, t_node *node1, t_node *node2)
{
	if (node1->x == node2->x && node1->y != node2->y)
		draw_vertical(env, node1, node2);
	else if (node1->y == node2->y && node1->x != node2->x)
		draw_horizontal(env, node1, node2);
	else if (node1->x != node2->x && \
		abs((node2->y - node1->y) / (node2->x - node1->x)) < 1)
		draw_soft_rise(env, node1, node2);
	else if (node1->y != node2->y)
		draw_high_rise(env, node1, node2);
}

static	void	draw(t_env *env, t_node **map, int x, int y)
{
	t_node *new;
	t_node *new2;

	new = NULL;
	new = new_coord(env, &map[y][x]);
	if (x != env->len_x - 1)
	{
		new2 = new_coord(env, &map[y][x + 1]);
		draw_segment(env, new, new2);
		free(new2);
	}
	if (y != env->len_y - 1)
	{
		new2 = new_coord(env, &map[y + 1][x]);
		draw_segment(env, new, new2);
		free(new2);
	}
	mlx_put_pixel_to_image(env, new);
	free(new);
}

void			get_map(t_env *env, t_node **map)
{
	int		y;
	int		x;

	y = 0;
	get_transform(env, map);
	while (y < env->len_y)
	{
		x = 0;
		while (x < env->len_x)
		{
			draw(env, map, x, y);
			x++;
		}
		y++;
	}
}
