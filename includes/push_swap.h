/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:56:13 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/08 15:40:27 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct			s_list_ck
{
	int					nb;
	int					rk;
	int					part;
	int					side;
	int					pos;
	int					dis;
	int					ra;
	int					rra;
	int					rb;
	int					rrb;
	int					res;
	struct s_list_ck	*next;
}						t_list_ck;

typedef struct			s_type
{
	char				*move;
	void				(*f_move)(void*);
}						t_type;

typedef struct			s_ps
{
	t_list_ck			*lst_a;
	t_list_ck			*lst_b;
	t_type				tab[12];
	char				*line;
	int					nbm;
	int					mid;
	int					last_mv;
	int					nb_mv;
}						t_ps;

t_list_ck				*find_max(t_list_ck *tmp, t_ps *env);
t_list_ck				*find_min(t_list_ck *tmp, t_ps *env);
t_list_ck				*find_minres(t_ps *env);
void					init_move(t_ps *env);
void					init_r_rr(t_ps *env);
t_type					*init_tab(t_ps *env);
void					brut_small(t_ps *env);
void					brut_4(t_ps *env);
void					brut_5(t_ps *env);
void					position(t_list_ck *lst);
void					distance_max(t_ps *env);
void					distance_min(t_ps *env);
void					nb_move(t_ps *env);
void					part(t_list_ck *lst);
int						side(t_ps *env);
int						is_max(t_list_ck *lst);
int						is_low(t_list_ck *lst);
t_list_ck				*last_a(t_ps *env);
t_list_ck				*last_b(t_ps *env);
int						is_sort(t_list_ck *lst);
void					freedom(t_ps *env);
int						is_sort_rev(t_list_ck *lst_a);
int						get_type(t_ps *env, char *str);
void					init(t_ps *env);
void					rank(t_ps *env);
t_list_ck				*create_maillon_ck(int nb, int rk, int part);
t_ps					*solver(t_ps *env);
void					move_sa();
void					move_sb();
void					move_ss();
void					move_pa();
void					move_pb();
void					move_ra();
void					move_rb();
void					move_rr();
void					move_rra();
void					move_rrb();
void					move_rrr();
void					lst_print(t_ps *env);
void					add_maillon_end(t_list_ck **begin_list,
														t_list_ck *data);
void					add_maillon_beg(t_list_ck **begin_list,
														t_list_ck *data);
t_list_ck				*maillon_del(t_list_ck *lst);
int						lst_count(t_list_ck *lst);
#endif
