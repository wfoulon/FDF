/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:57:44 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/11 17:57:46 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			which_proj(t_env *env, t_mat *mat, t_node *node)
{
	if (env->proj == 0)
	{
		mat->z = node->z * env->moove_z;
		mat->x = CTE1 * node->x - CTE2 * node->y;
		mat->y = -2 * mat->z + (CTE1 / 2) * node->x + (CTE2 / 2) * node->y;
		if (env->proj == 0)
		{
			mat->x += 540;
			mat->y += 140;
		}
	}
	else if (env->proj == 1)
	{
		mat->z = node->z * env->moove_z;
		mat->x = node->x - CTE * mat->z;
		mat->y = node->y + (CTE / 2) * mat->z;
	}
}

float			proportion_altitude(t_env *env, t_node *node)
{
	return ((node->z - env->coord->z_min)\
		/ (env->coord->z_max - env->coord->z_min));
}

int				altitude_color(t_env *env, t_node *node)
{
	float		delta;
	float		deltab;
	int			g;
	int			color;
	uintmax_t	ret;

	delta = (float)node->z - env->coord->z_min;
	deltab = (float)env->coord->z_max - env->coord->z_min;
	if (deltab <= 0.0)
		return (RGB(255, 255, 255));
	delta = (float)delta / deltab;
	g = 255;
	g = (255 + delta * g);
	color = 0xFF;
	ret = RGB(255, g, (int)(color + delta * (255)));
	return (ret);
}
