/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:12:41 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/05 15:06:07 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_type	*fill_tab(t_type *tab, char *move, void (*f)(void*))
{
	tab->move = ft_strdup(move);
	tab->f_move = f;
	return (tab);
}

t_type	*init_tab(t_ps *env)
{
	fill_tab(env->tab, "sa", &move_sa);
	fill_tab(env->tab + 1, "sb", &move_sb);
	fill_tab(env->tab + 2, "ss", &move_ss);
	fill_tab(env->tab + 3, "pa", &move_pa);
	fill_tab(env->tab + 4, "pb", &move_pb);
	fill_tab(env->tab + 5, "ra", &move_ra);
	fill_tab(env->tab + 6, "rb", &move_rb);
	fill_tab(env->tab + 7, "rr", &move_rr);
	fill_tab(env->tab + 8, "rra", &move_rra);
	fill_tab(env->tab + 9, "rrb", &move_rrb);
	fill_tab(env->tab + 10, "rrr", &move_rrr);
	return (env->tab);
}

int		get_type(t_ps *env, char *str)
{
	int index;

	index = 0;
	while (index < 11 && ft_strcmp(env->tab[index].move, str) != 0)
		index++;
	if (index == 11)
	{
		ft_putendl_fd("Error", 2);
		freedom(env);
		exit(1);
	}
	return (index);
}

int		is_sort(t_list_ck *lst_a)
{
	t_list_ck	*tmp;
	int			current;

	tmp = lst_a;
	if (!lst_a)
		return (0);
	else if (lst_a && !lst_a->next)
		return (1);
	else if (lst_a && lst_a->next)
	{
		current = lst_a->nb;
		tmp = tmp->next;
		while (tmp)
		{
			if (current > tmp->nb)
				return (0);
			current = tmp->nb;
			tmp = tmp->next;
		}
	}
	return (1);
}

void	solver(t_ps *env)
{
	int i;

	i = 0;
	init_tab(env);
	if (env->visu)
		lst_print(env->lst_a, env->lst_b);
	while (get_next_line(0, &env->line) > 0)
	{
		env->tab[get_type(env, env->line)].f_move(env);
		if (env->visu)
			lst_print(env->lst_a, env->lst_b);
		ft_strdel(&env->line);
	}
	(is_sort(env->lst_a) && !env->lst_b ? ft_putendl("OK") : ft_putendl("KO"));
	freedom(env);
}
