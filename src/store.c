/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:37:39 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/15 10:37:39 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			skip_line(char *line)
{
	if (!ft_strncmp(line, "Plateau", 7))
	{
		ft_strdel(&line);
		if (get_next_line(0, &line) < 0)
			return (-1);
		ft_strdel(&line);
	}
	return (0);
}

char		*cap_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int			store_piece(t_env *env, char *line)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	env->p.piece = (char**)malloc(sizeof(char*) * (env->p.len));
	while (y < env->p.len)
	{
		if (get_next_line(0, &line) < 0)
			return (-1);
		env->p.piece[y] = (char*)malloc(sizeof(char) * env->p.width);
		ft_memcpy(env->p.piece[y], &line[x], ft_strlen(line));
		y++;
	}
	ft_strdel(&line);
	return (0);
}

int			store_map(t_env *env, char *line)
{
	char	*str;
	int		y;
	int		x;

	x = 4;
	skip_line(line);
	env->map.board = (char**)malloc(sizeof(char*) * (env->map.len));
	y = 0;
	while (y < env->map.len)
	{
		if (get_next_line(0, &line) < 0)
			return (-1);
		str = cap_str(line);
		env->map.board[y] = (char*)malloc(sizeof(char) * env->map.width);
		ft_memcpy(env->map.board[y], &str[x], ft_strlen(line));
		y++;
	}
	ft_strdel(&line);
	return (0);
}
