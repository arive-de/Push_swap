/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 09:02:28 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/08 11:57:14 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		brut_small(t_ps *env)
{
	while (!is_sort(env->lst_a))
	{
		if (env->lst_a->rk == 2 && env->lst_a->next->rk == 3)
			move_rra(env);
		else if (env->lst_a->rk == 2 && env->lst_a->next->rk == 1)
			move_sa(env);
		else if (env->lst_a->rk == 3 && env->lst_a->next->rk == 1)
			move_ra(env);
		else if (env->lst_a->rk == 3 && env->lst_a->next->rk == 2)
		{
			move_sa(env);
			move_rra(env);
		}
		else if (env->lst_a->rk == 1 && env->lst_a->next->rk == 3)
		{
			move_rra(env);
			move_sa(env);
		}
	}
}

void		brut_4(t_ps *env)
{
	while (!is_sort(env->lst_a))
	{
		while (is_max(env->lst_a) != env->lst_a->rk)
			move_ra(env);
		move_pb(env);
		brut_small(env);
		move_pa(env);
		move_ra(env);
	}
}

t_list_ck	*find_low(t_list_ck *tmp, t_ps *env)
{
	t_list_ck *tmp2;

	tmp2 = env->lst_a->next;
	if (!tmp2)
		return (tmp);
	while (tmp)
	{
		if (tmp->rk < tmp2->rk)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	return (tmp2);
}

void		brut_5(t_ps *env)
{
	if (env->lst_a->rk == 3 && env->lst_a->next->rk == 2 &&
		env->lst_a->next->next->rk == 5 && env->lst_a->next->next->next->rk == 1
			&& env->lst_a->next->next->next->next->rk == 4)
		move_sa(env);
	if (env->lst_a->rk == 2 && env->lst_a->next->rk == 5 &&
		env->lst_a->next->next->rk == 1 && env->lst_a->next->next->next->rk == 4
			&& env->lst_a->next->next->next->next->rk == 3)
	{
		move_rra(env);
		move_sa(env);
	}
	while (!is_sort(env->lst_a))
	{
		part(env->lst_a);
		while (is_low(env->lst_a) != env->lst_a->rk)
			find_low(env->lst_a, env)->part == 1 ? move_ra(env) : move_rra(env);
		move_pb(env);
		if (env->lst_a->rk > env->lst_a->next->rk)
			move_sa(env);
	}
	while (env->lst_b)
		move_pa(env);
}
