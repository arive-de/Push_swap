/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:17:54 by arive-de          #+#    #+#             */
/*   Updated: 2017/11/14 17:23:38 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	position(t_list_ck *lst)
{
	int			i;
	t_list_ck	*tmp;

	i = 0;
	part(lst);
	tmp = lst;
	while (tmp)
	{
		if (tmp->part == 1)
		{
			tmp->pos = i;
			tmp->ra = tmp->pos;
		}
		else
		{
			tmp->pos = lst_count(lst) - i;
			tmp->rra = tmp->pos;
		}
		i++;
		tmp = tmp->next;
	}
}

void	distance_max(t_ps *env)
{
	int			stock;
	t_list_ck	*cur;
	t_list_ck	*tmp;

	cur = env->lst_a;
	while (cur)
	{
		stock = 0;
		tmp = env->lst_b;
		while (tmp)
		{
			if (cur->rk > tmp->rk && stock < tmp->rk)
			{
				stock = tmp->rk;
				cur->dis = tmp->pos;
				if (tmp->part == 1)
					cur->rb = cur->dis;
				else
					cur->rrb = cur->dis;
			}
			tmp = tmp->next;
		}
		cur = cur->next;
	}
}

void	distance_min(t_ps *env)
{
	t_list_ck *tmp;
	t_list_ck *cur;

	tmp = find_min(env->lst_a, env);
	cur = env->lst_a;
	if (tmp && env->lst_b && tmp->rk < is_low(env->lst_b))
	{
		tmp->dis = find_max(env->lst_b, env)->pos;
		if (find_max(env->lst_b, env)->part == 1)
			tmp->rb = tmp->dis;
		else
			tmp->rrb = tmp->dis;
	}
	while (cur)
	{
		if (cur && env->lst_b && cur->rk < is_low(env->lst_b))
		{
			cur->dis = find_max(env->lst_b, env)->pos;
			if (find_max(env->lst_b, env)->part == 1)
				cur->rb = cur->dis;
			else
				cur->rrb = cur->dis;
		}
		cur = cur->next;
	}
}

void	nb_move(t_ps *env)
{
	t_list_ck *tmp;

	tmp = env->lst_a;
	while (tmp)
	{
		if (tmp->ra > 0 && tmp->rb > 0)
		{
			if (tmp->ra > tmp->rb)
				tmp->ra = tmp->ra - tmp->rb;
			else if (tmp->rb > tmp->ra)
				tmp->rb = tmp->rb - tmp->ra;
		}
		if (tmp->rra > 0 && tmp->rrb > 0)
		{
			if (tmp->rra > tmp->rrb)
				tmp->rra = tmp->rra - tmp->rrb;
			else if (tmp->rrb > tmp->rra)
				tmp->rrb = tmp->rrb - tmp->rra;
		}
		tmp->res = tmp->ra + tmp->rb + tmp->rra + tmp->rrb + 1;
		tmp = tmp->next;
	}
}
