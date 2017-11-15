/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 21:47:16 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/15 09:50:10 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		heatmap_init(t_env *env)
{
	int		y;
	int		x;

	y = 0;
	env->heat_map = (int**)malloc(sizeof(int*) * (env->map.len));
	while (y < env->map.len)
	{
		x = 0;
		env->heat_map[y] = (int*)malloc(sizeof(int) * (env->map.width));
		while (x < env->map.width)
		{
			if (env->map.board[y][x] == env->pl2)
				env->heat_map[y][x] = 5000;
			else
				env->heat_map[y][x] = 1;
			x++;
		}
		y++;
	}
}

void		heatmap_fill(t_env *env, int y, int x, int heat)
{
	if (env->heat_map[y][x + 1] > heat)
		env->heat_map[y][x] = heat;
	if (y > 0 && env->heat_map[y - 1][x + 1] > heat)
		env->heat_map[y][x] = heat;
	if (x > 0 && env->heat_map[y][x - 1] > heat)
		env->heat_map[y][x] = heat;
	if (y > 0 && env->heat_map[y - 1][x] > heat)
		env->heat_map[y][x] = heat;
	if (y > 0 && x > 0 && env->heat_map[y - 1][x - 1] > heat)
		env->heat_map[y][x] = heat;
	if (y + 1 < env->map.len)
	{
		if (x > 0 && env->heat_map[y + 1][x - 1] > heat)
			env->heat_map[y][x] = heat;
		if (env->heat_map[y + 1][x + 1] > heat)
			env->heat_map[y][x] = heat;
		if (env->heat_map[y + 1][x] > heat)
			env->heat_map[y][x] = heat;
	}
}

void		heatmap_check(t_env *env)
{
	float	heat;
	int		x;
	int		y;
	int		i;

	i = 0;
	heat = 4500;
	while (i < env->map.len + env->map.width)
	{
		y = 0;
		while (y < env->map.len)
		{
			x = 0;
			while (x < env->map.width)
			{
				if (env->heat_map[y][x] == 1)
					heatmap_fill(env, y, x, heat);
				x++;
			}
			y++;
		}
		i++;
		heat /= 1.1;
	}
}
