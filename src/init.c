/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:26:29 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/14 17:06:20 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_env		*init_structs(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	init_piece(env);
	init_map(env);
	env->len = 0;
	env->width = 0;
	env->map_size = NULL;
	env->player_info = NULL;
	env->flag = 0;
	env->pl = '\0';
	env->pl2 = '\0';
	env->heat_map = NULL;
	return (env);
}

void		init_piece(t_env *env)
{
	env->p.t_len = 0;
	env->p.t_wid = 0;
	env->p.len = 0;
	env->p.width = 0;
	env->p.piece = NULL;
	env->p.y_top = 0;
	env->p.y_bot = 0;
	env->p.x_l = 0;
	env->p.x_r = 0;
	env->p.sum = 0;
	env->p.x = 0;
	env->p.y = 0;
	env->p.touch = 0;
	env->p.sum = 0;
}

void		init_map(t_env *env)
{
	env->map.len = 0;
	env->map.width = 0;
	env->map.board = NULL;
}
