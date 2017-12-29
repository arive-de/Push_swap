/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:17:54 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/08 18:05:43 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list_ck	*rb_rrb(t_ps *env, t_list_ck *tmp)
{
	while (tmp->dis > 0)
	{
		if (tmp->rb > 0)
			move_rb(env);
		else
			move_rrb(env);
		tmp->dis--;
	}
	return (tmp);
}

t_list_ck	*ra_rra(t_ps *env, t_list_ck *tmp)
{
	while (tmp->pos > 0)
	{
		if (tmp->ra > 0)
			move_ra(env);
		else
			move_rra(env);
		tmp->pos--;
	}
	return (tmp);
}

t_list_ck	*rr_rrr(t_ps *env, t_list_ck *tmp)
{
	while (tmp->dis > 0 && tmp->pos > 0)
	{
		if (tmp->ra > 0 && tmp->rb > 0)
			move_rr(env);
		else if (tmp->rra > 0 && tmp->rrb > 0)
			move_rrr(env);
		else if (tmp->ra > 0 && tmp->rrb > 0)
		{
			move_ra(env);
			move_rrb(env);
		}
		else if (tmp->rb > 0 && tmp->rra > 0)
		{
			move_rb(env);
			move_rra(env);
		}
		tmp->dis--;
		tmp->pos--;
	}
	return (tmp);
}

void		depil(t_ps *env)
{
	while (!is_sort_rev(env->lst_b))
		(find_max(env->lst_b, env)->part == 1 ? move_rb(env) : move_rrb(env));
	while (env->lst_b)
		move_pa(env);
}

t_ps		*solver(t_ps *env)
{
	t_list_ck	*tmp;

	move_pb(env);
	move_pb(env);
	if (env->lst_b->rk < env->lst_b->next->rk)
		move_sb(env);
	tmp = NULL;
	while (env->lst_a)
	{
		init_move(env);
		tmp = find_minres(env);
		if (!tmp->pos && tmp->dis)
			tmp = rb_rrb(env, tmp);
		else if (tmp->pos && !tmp->dis)
			tmp = ra_rra(env, tmp);
		if (tmp->pos && tmp->dis)
			tmp = rr_rrr(env, tmp);
		if (!tmp->pos && !tmp->dis)
			move_pb(env);
		else
			continue;
	}
	depil(env);
	return (env);
}
