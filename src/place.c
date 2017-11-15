/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:40:28 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/15 09:52:55 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define SUM 0
#define YA 1
#define XA 2
#define Y 3
#define X 4

int			blah_norm(t_env *env, int *t)
{
	t[SUM] = 0;
	while (t[YA] < env->p.t_len)
	{
		t[XA] = 0;
		while (t[XA] < env->p.t_wid)
		{
			if (env->p.piece[t[YA]][t[XA]] == '*')
			{
				if ((t[YA] + t[Y] < env->map.len) &&
					(t[XA] + t[X] < env->map.width))
				{
					if (env->map.board[t[Y] + t[YA]][t[X] + t[XA]] == env->pl)
						env->p.touch++;
					if (env->map.board[t[Y] + t[YA]][t[X] + t[XA]] == env->pl2)
						return (-1);
					t[SUM] += (env->heat_map[t[Y] + t[YA]][t[X] + t[XA]]);
				}
			}
			t[XA]++;
		}
		t[YA]++;
	}
	if (env->p.touch != 1)
		return (-1);
	return (t[SUM]);
}

void		valid_place(t_env *env, int sum, int y, int x)
{
	if (sum >= env->p.sum)
	{
		env->p.sum = sum;
		env->p.x = x - env->p.x_l;
		env->p.y = y - env->p.y_top;
	}
}

void		optimal_place(t_env *env, int y, int x)
{
	int		t[5];

	t[SUM] = 0;
	t[YA] = 0;
	t[XA] = 0;
	t[Y] = y;
	t[X] = x;
	env->p.touch = 0;
	if (y + env->p.t_len > env->map.len || x + env->p.t_wid > env->map.width)
		return ;
	valid_place(env, blah_norm(env, t), y, x);
}

void		validate_piece(t_env *env)
{
	int		y;
	int		x;

	y = 0;
	while (y < env->map.len)
	{
		x = 0;
		while (x < env->map.width)
		{
			optimal_place(env, y, x);
			x++;
		}
		y++;
	}
	ft_printf("%d %d\n", (env->p.y), (env->p.x));
}
