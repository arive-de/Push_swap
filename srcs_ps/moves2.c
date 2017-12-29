/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:54:04 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/08 11:47:30 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_ra(t_ps *env)
{
	t_list_ck *tmp;
	t_list_ck *tmp2;

	tmp = env->lst_a;
	tmp2 = env->lst_a;
	if (env->lst_a && env->lst_a->next)
	{
		while (tmp2->next)
			tmp2 = tmp2->next;
		env->lst_a = env->lst_a->next;
		tmp2->next = tmp;
		tmp->next = NULL;
		if (env->last_mv != 8)
			ft_putendl("ra");
		env->nb_mv++;
		env->last_mv = 6;
	}
}

void	move_rb(t_ps *env)
{
	t_list_ck *tmp;
	t_list_ck *tmp2;

	tmp = env->lst_b;
	tmp2 = env->lst_b;
	if (env->lst_b && env->lst_b->next)
	{
		while (tmp2->next)
			tmp2 = tmp2->next;
		env->lst_b = env->lst_b->next;
		tmp2->next = tmp;
		tmp->next = NULL;
		if (env->last_mv != 6)
			ft_putendl("rb");
		env->nb_mv++;
		env->last_mv = 7;
	}
}

void	move_rr(t_ps *env)
{
	env->last_mv = 8;
	move_ra(env);
	move_rb(env);
	ft_putendl("rr");
	env->nb_mv--;
}
