/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:53:27 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/08 11:47:45 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_rra(t_ps *env)
{
	t_list_ck	*tmp;
	t_list_ck	*tmp2;

	tmp = env->lst_a;
	tmp2 = NULL;
	if (env->lst_a && env->lst_a->next)
	{
		while (tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp->next = env->lst_a;
		env->lst_a = tmp;
		tmp2->next = NULL;
		if (env->last_mv != 11)
			ft_putendl("rra");
		env->nb_mv++;
		env->last_mv = 9;
	}
}

void	move_rrb(t_ps *env)
{
	t_list_ck	*tmp;
	t_list_ck	*tmp2;

	tmp = env->lst_b;
	tmp2 = NULL;
	if (env->lst_b && env->lst_b->next)
	{
		while (tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp->next = env->lst_b;
		env->lst_b = tmp;
		tmp2->next = NULL;
		if (env->last_mv != 9)
			ft_putendl("rrb");
		env->nb_mv++;
		env->last_mv = 10;
	}
}

void	move_rrr(t_ps *env)
{
	env->last_mv = 11;
	move_rra(env);
	move_rrb(env);
	ft_putendl("rrr");
	env->nb_mv--;
}
