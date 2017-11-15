/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 14:23:51 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/14 17:06:28 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/megalibft.h"
# include <stdio.h>

typedef struct		s_p
{
	int				t_len;
	int				t_wid;
	int				len;
	int				width;
	char			**piece;
	int				y_top;
	int				y_bot;
	int				x_l;
	int				x_r;
	int				sum;
	int				x;
	int				y;
	int				touch;
}					t_p;

typedef struct		s_map
{
	int				len;
	int				width;
	char			**board;
}					t_map;

typedef struct		s_env
{
	t_p				p;
	t_map			map;
	int				len;
	int				width;
	char			*player_info;
	char			*map_size;
	int				**heat_map;
	char			pl;
	char			pl2;
	int				flag;
}					t_env;

/*
** ------------------------------- place.c ------------------------------------
*/
void				optimal_place(t_env *env, int y, int x);
void				validate_piece(t_env *env);
void				valid_place(t_env *env, int sum, int y, int x);
/*
** ------------------------------- store.c ------------------------------------
*/
int					store_map(t_env *env, char *line);
int					store_piece(t_env *env, char *line);
char				*cap_str(char *str);
int					skip_line(char *line);
/*
** ---------------------------- trim_piece.c ----------------------------------
*/
char				**trim_piece(t_env *env);
int					trim_y_top(t_env *env);
int					trim_y_bot(t_env *env);
int					trim_x_left(t_env *env);
int					trim_x_right(t_env *env);
/*
** ------------------------------- init.c -------------------------------------
*/
t_env				*init_structs(void);
void				init_map(t_env *env);
void				init_piece(t_env *env);
/*
** ------------------------------ heatmap.c -----------------------------------
*/
void				heatmap_init(t_env *env);
void				heatmap_fill(t_env *env, int y, int x, int heat);
void				heatmap_check(t_env *env);
/*
** ------------------------------ filler.c ------------------------------------
*/
void				print_char(char **ary, int len);
void				print_int(t_env *env, int len, int **array);
void				free_str(char **ary);
/*
** ----------------------------- readfile.c -----------------------------------
*/
int					read_piece(t_env *env);
int					read_player_input(t_env *env);
int					read_map_piece(t_env *env);
void				free_maps(t_env *env);
#endif
