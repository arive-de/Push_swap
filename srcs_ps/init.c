/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:16:52 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/08 18:04:43 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		exit(0);
	}
	return (index);
}
