/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 09:54:33 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/15 10:47:39 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			trim_y_top(t_env *env)
{
	int		y;
	int		x;

	y = 0;
	while (y < env->p.len)
	{
		x = 0;
		while (x < env->p.width)
		{
			if (env->p.piece[y][x] == '*')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int			trim_y_bot(t_env *env)
{
	int		y;
	int		x;

	y = env->p.len - 1;
	while (y >= 0)
	{
		x = env->p.width - 1;
		while (x >= 0)
		{
			if (env->p.piece[y][x] == '*')
				return (y);
			x--;
		}
		y--;
	}
	return (0);
}

int			trim_x_left(t_env *env)
{
	int		y;
	int		x;

	x = 0;
	while (x < env->p.width)
	{
		y = 0;
		while (y < env->p.len)
		{
			if (env->p.piece[y][x] == '*')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

int			trim_x_right(t_env *env)
{
	int		y;
	int		x;

	x = env->p.width - 1;
	while (x >= 0)
	{
		y = env->p.len - 1;
		while (y >= 0)
		{
			if (env->p.piece[y][x] == '*')
				return (x);
			y--;
		}
		x--;
	}
	return (0);
}

char		**trim_piece(t_env *env)
{
	char	**arry;
	int		y;

	y = 0;
	env->p.y_top = trim_y_top(env);
	env->p.y_bot = trim_y_bot(env);
	env->p.x_l = trim_x_left(env);
	env->p.x_r = trim_x_right(env);
	env->p.t_len = (env->p.y_bot - env->p.y_top + 1);
	env->p.t_wid = (env->p.x_r - env->p.x_l + 1);
	if (env->p.t_len == env->p.len && env->p.t_wid == env->p.width)
		return (env->p.piece);
	else
	{
		arry = (char**)malloc(sizeof(char*) * env->p.t_len);
		while (y < env->p.t_len)
		{
			arry[y] = (char*)malloc(sizeof(char) * env->p.t_wid);
			ft_memcpy(arry[y],
			&env->p.piece[env->p.y_top + y][env->p.x_l], env->p.t_wid);
			arry[y][env->p.t_wid] = '\0';
			y++;
		}
	}
	return (arry);
}
