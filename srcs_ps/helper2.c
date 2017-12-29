/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:40:33 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/08 10:19:58 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			lst_count(t_list_ck *lst)
{
	t_list_ck	*tmp;
	int			i;

	i = 0;
	tmp = lst;
	if (!tmp)
		return (0);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void		part(t_list_ck *lst)
{
	int			i;
	int			mid;
	t_list_ck	*tmp;

	i = 0;
	tmp = lst;
	mid = lst_count(lst) / 2;
	while (tmp)
	{
		if (i <= mid)
			tmp->part = 1;
		else
			tmp->part = 2;
		i++;
		tmp = tmp->next;
	}
}

void		rank(t_ps *env)
{
	t_list_ck	*tmp;
	t_list_ck	*tmp2;
	int			i;

	i = 0;
	while (++i <= lst_count(env->lst_a))
	{
		tmp = env->lst_a;
		tmp2 = env->lst_a->next;
		while (tmp && tmp2)
		{
			if (tmp->rk)
				tmp = tmp->next;
			if (tmp2->rk)
				tmp2 = tmp2->next;
			else if (tmp->nb < tmp2->nb)
				tmp2 = tmp2->next;
			else
			{
				tmp = tmp2;
				tmp2 = tmp2->next;
			}
		}
		tmp->rk = i;
	}
}

t_list_ck	*find_max(t_list_ck *tmp, t_ps *env)
{
	t_list_ck *tmp2;

	tmp2 = env->lst_b->next;
	if (!tmp2)
		return (tmp);
	while (tmp)
	{
		if (tmp->rk > tmp2->rk)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	return (tmp2);
}

t_list_ck	*find_min(t_list_ck *tmp, t_ps *env)
{
	t_list_ck *tmp2;

	tmp2 = env->lst_b->next;
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
