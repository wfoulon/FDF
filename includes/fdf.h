/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 13:50:08 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/04 13:50:10 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "define.h"
# include "struct.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
** convertion.c
*/
char		*ft_intermediate(int i, char *str, int fact, int k);
char		*ft_itohex(int i);

/*
** draw_line.c
*/
void		draw_vertical(t_env *env, t_node *node1, t_node *node2);
void		draw_horizontal(t_env *env, t_node *node1, t_node *node2);
void		draw_soft_rise(t_env *env, t_node *node1, t_node *node2);
void		draw_high_rise(t_env *env, t_node *node1, t_node *node2);

/*
** draw_line2.c
*/
t_node		*new_coord(t_env *env, t_node *node);
void		get_transform(t_env *env, t_node **map);
void		draw_segment(t_env *env, t_node *node1, t_node *node2);
void		get_map(t_env *env, t_node **map);

/*
** error.c
*/
void		error_conform(void);
void		error_file(void);
void		error_image(void);
t_env		*ft_error(int argc, char **argv);

/*
** function_event.c
*/
int			mouse_funct(int button, int x, int y, t_env *env);
void		key_funct_2(int keycode, t_env *env);
int			key_funct(int keycode, t_env *env);

/*
** init_env.c
*/
void		new_1(t_env *env);
void		new_2(t_env *env);
t_env		*new_env(void);
t_env		*init_env(int fd, char *av1);

/*
** init_img.c
*/
t_img		*init_img(t_env *env, int height, int width);
void		mlx_put_pixel_to_image(t_env *env, t_node *node);
int			fill_img(t_env *env);

/*
** init_map.c
*/
int			get_color(char *str);
int			temporaire(int fd, char *line, t_env *env, t_node **map);
t_node		**convert_map(char **split, t_node **map, int *color_bool);
t_node		**fill_map(int fd, t_env *env);

/*
** init_node.c
*/
t_node		*new_node(void);
t_node		*init_node(int x0, int y0, int z0, int color0);
void		display_map(t_node **map, t_env *env);

/*
** main.c
*/
char		*get_file_name(char *av1);
void		rescale(t_env *env, t_node **map);
void		ft_hook(t_env *env);

/*
** print_image.c
*/
void		print_image(t_env *env);
int			print_menu(t_env *env);
int			print_title(t_env *env);

/*
** print_image2.c
*/
void		print_image_back(t_env *env);
void		print_image_supp(t_env *env);
void		print_image_graph(t_env *env);
void		print_coords(int x, int y, t_env *env);

/*
** reinitialise.c
*/
int			ft_free(char **split, t_node **map, int *bo, char *line);
void		ft_fill_len(t_env *env, int len, int count);
void		reinitialise(t_env *env);
void		refresh(t_env *env);
void		to_other(t_env *env, int i);

/*
** rt.c
*/
void		translation(t_env *env, int nb);
void		rotation(t_env *env, int i);
void		moove_z(t_env *env, int i);
void		zoom(t_env *env);
void		dezoom(t_env *env);

/*
** tools.c
*/
void		which_proj(t_env *env, t_mat *mat, t_node *node);
float		proportion_altitude(t_env *env, t_node *node);
int			altitude_color(t_env *env, t_node *node);

#endif
