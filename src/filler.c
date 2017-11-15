/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 14:23:49 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/14 17:58:29 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_maps(t_env *env)
{
	int	y;

	y = 0;
	while (y < env->map.len)
	{
		ft_strdel(&env->map.board[y]);
		free(env->heat_map[y]);
		y++;
	}
	y = 0;
	while (y < env->p.t_len)
	{
		ft_strdel(&env->p.piece[y]);
		y++;
	}
	free(env->map.board);
	free(env->heat_map);
	free(env->p.piece);
	env->map.board = NULL;
	env->heat_map = NULL;
	env->p.piece = NULL;
}

void	print_char(char **ary, int len)
{
	int	y;

	y = 0;
	while (y < len)
	{
		ft_printf("%s\n", ary[y]);
		y++;
	}
}

void	print_int(t_env *env, int len, int **array)
{
	int	y;
	int x;

	y = 0;
	while (y < len)
	{
		x = 0;
		while (x < env->map.width)
		{
			fprintf(stderr, " [%4d]", array[y][x]);
			x++;
		}
		fprintf(stderr, "\n\n");
		y++;
	}
}

int		main(void)
{
	t_env		*env;
	char		*line;

	fprintf(stderr, "1111\n");
	env = init_structs();
	if (read_player_input(env) < 0 || read_map_piece(env) < 0)
	{
		ft_printf("\033[31mInvalid File\033[0m\n");
		return (0);
	}
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (store_map(env, line) < 0)
			return (-1);
		heatmap_init(env);
		heatmap_check(env);
		read_piece(env);
		store_piece(env, line);
		env->p.piece = trim_piece(env);
		validate_piece(env);
		free_maps(env);
		init_piece(env);
	}
	free(env);
	return (0);
}
