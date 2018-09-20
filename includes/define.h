/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:21:04 by wfoulon           #+#    #+#             */
/*   Updated: 2017/12/14 11:21:10 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

# define SIZE_X 1920
# define SIZE_Y 1080

# define FENE_X 1200
# define FENE_Y 900

# define HEIGHT_DRAW 800
# define WIDTH_DRAW 600

# define BACK_X 1024
# define BACK_Y 850

# define SUPP_X 1240
# define SUPP_Y 940

# define CTE 1
# define CTE1 0.5
# define CTE2 0.5

# define PI 3.14
# define COEFF_Z 1.2
# define COEFF_ZD 0.6
# define COEFF_ZOOM 1.2
# define COEFF_DEZOOM 1/1.2
# define THETA 10 * PI / 180

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define SCROLL_OTHER 6
# define SCROLL_BIS 7

# define TOUCH_ESC 53
# define ARROW_LEFT 123
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define TOUCH_O 31
# define TOUCH_PLUS 69
# define TOUCH_LESS 78
# define TOUCH_P 35
# define TOUCH_I 34
# define TOUCH_R 15
# define TOUCH_T 17
# define PAGE_DOWN 121
# define PAGE_UP 116

#endif
