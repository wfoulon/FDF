/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:26:12 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/10 14:26:26 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node		*new_node(void)
{
	t_node	*node;

	if (!(node = (t_node*)ft_memalloc(sizeof(t_node))))
		return (NULL);
	node->x = 0;
	node->y = 0;
	node->z = 0;
	node->color_num = 0;
	node->rap = 0.0;
	return (node);
}

t_node		*init_node(int x0, int y0, int z0, int color_num0)
{
	t_node *node;

	if (!(node = new_node()))
		return (NULL);
	node->x = x0;
	node->y = y0;
	node->z = z0;
	node->color_num = color_num0;
	return (node);
}

void		display_map(t_node **map, t_env *env)
{
	int x;
	int y;

	y = 0;
	if (!map)
		ft_putstr("Erreur de map");
	while (y < env->len_y)
	{
		x = 0;
		while (x < env->len_x)
		{
			ft_putnbr(map[y][x].z);
			ft_putchar(',');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
