/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:11:48 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/15 10:50:01 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			read_player_input(t_env *env)
{
	char	*line;

	if (get_next_line(0, &line) < 0)
		return (-1);
	env->pl = (line[10] == '1') ? 'O' : 'X';
	env->pl2 = (line[10] == '1') ? 'X' : 'O';
	ft_strdel(&line);
	return (0);
}

int			read_map_piece(t_env *env)
{
	int		y;
	char	*line;

	y = 0;
	if (get_next_line(0, &line) < 0)
		return (-1);
	while (!ft_isdigit(line[y]))
		y++;
	env->map.len = ft_atoi(&line[y]);
	while (ft_isdigit(line[y]))
		y++;
	while (!ft_isdigit(line[y]))
		y++;
	env->map.width = ft_atoi(&line[y]);
	ft_strdel(&line);
	return (0);
}

int			read_piece(t_env *env)
{
	int		y;
	char	*line;

	y = 0;
	if (get_next_line(0, &line) < 0)
		return (-1);
	while (!ft_isdigit(line[y]))
		y++;
	env->p.len = ft_atoi(&line[y]);
	while (ft_isdigit(line[y]))
		y++;
	while (!ft_isdigit(line[y]))
		y++;
	env->p.width = ft_atoi(&line[y]);
	ft_strdel(&line);
	return (0);
}
