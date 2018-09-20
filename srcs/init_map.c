/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:21:25 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/11 14:21:27 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					get_color(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'x')
			return (ft_atoi_base(&str[i + 1], 16));
		i++;
	}
	return (-1);
}

int					temporaire(int fd, char *line, t_env *env, t_node **map)
{
	int				lenght;
	char			**split;

	split = NULL;
	if (fd < 0)
		return (0);
	if (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		free(line);
		lenght = ft_split_len(split);
		if (!(map = convert_map(split, map, &env->color_bool)))
		{
			ft_free_tab(split);
			return (0);
		}
	}
	else
		return (0);
	ft_free_tab(split);
	return (lenght);
}

static	t_node		*init_map(char **split, int x, int y, int *color_bool)
{
	char			**st;
	t_node			*new;

	if (ft_strchr(split[x], ',') == NULL)
	{
		if (ft_is_number(split[x]) == 0)
			return (NULL);
		new = init_node(x, y, ft_atoi(split[x]), get_color("0xFF0000"));
	}
	else
	{
		*color_bool = 1;
		st = ft_strsplit(split[x], ',');
		if (ft_is_number(st[0]) == 0)
		{
			ft_free_tab(st);
			return (NULL);
		}
		else if (get_color(st[1]) == -1)
			new = init_node(x, y, ft_atoi(st[0]), get_color("0xFF0000"));
		else
			new = init_node(x, y, ft_atoi(st[0]), get_color(st[1]));
		ft_free_tab(st);
	}
	return (new);
}

t_node				**convert_map(char **split, t_node **map, int *color_bool)
{
	int				len;
	static int		y;
	int				x;
	t_node			*new;

	len = ft_split_len(split);
	map[y] = ft_memalloc(sizeof(t_node) * (len + 1));
	map[y + 1] = NULL;
	x = 0;
	if (!(map[y]))
	{
		free(map);
		return (NULL);
	}
	while (x < len)
	{
		new = init_map(split, x, y, color_bool);
		map[y][x] = *new;
		free(new);
		x++;
	}
	y++;
	return (map);
}

t_node				**fill_map(int fd, t_env *env)
{
	char			*line;
	int				lenght;
	char			**split;
	t_node			**map;
	int				count;

	line = NULL;
	count = 1;
	if (!(map = ft_memalloc(sizeof(t_node*) * count)))
		return (NULL);
	if ((lenght = temporaire(fd, line, env, map)) == 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		map = (t_node**)ft_realloc((void*)map, sizeof(t_node*) \
				* (count + 1), sizeof(t_node*) * count);
		split = ft_strsplit(line, ' ');
		if (ft_free(split, map, &env->color_bool, line) == 0)
			return (NULL);
		count++;
	}
	free(line);
	ft_fill_len(env, lenght, count);
	return (map);
}
