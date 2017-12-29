/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:51:46 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/08 10:45:07 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"

typedef struct			s_list_ck
{
	int					nb;
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
	int					visu;
	char				*line;
}						t_ps;

void					freedom(t_ps *env);
t_list_ck				*create_maillon_ck(int nb);
void					solver(t_ps *env);
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
void					lst_print(t_list_ck *lst_a, t_list_ck *lst_b);
void					add_maillon_end(t_list_ck **begin_list,
														t_list_ck *data);
void					add_maillon_beg(t_list_ck **begin_list,
														t_list_ck *data);
t_list_ck				*maillon_del(t_list_ck *lst);

#endif
