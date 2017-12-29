/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:30:45 by arive-de          #+#    #+#             */
/*   Updated: 2017/12/14 11:03:13 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			is_sort(t_list_ck *lst)
{
	t_list_ck	*tmp;
	int			current;

	tmp = lst;
	if (!lst)
		return (0);
	current = lst->rk;
	tmp = tmp->next;
	if (lst && !lst->next)
		return (1);
	else if (lst && lst->next)
	{
		while (tmp)
		{
			if (current > tmp->rk)
				return (0);
			current = tmp->rk;
			tmp = tmp->next;
		}
	}
	return (1);
}

int			is_sort_rev(t_list_ck *lst)
{
	t_list_ck	*tmp;
	int			current;

	tmp = lst;
	if (!lst)
		return (0);
	current = lst->rk;
	tmp = tmp->next;
	if (lst && !lst->next)
		return (1);
	else if (lst && lst->next)
	{
		while (tmp)
		{
			if (current < tmp->rk)
				return (0);
			current = tmp->rk;
			tmp = tmp->next;
		}
	}
	return (1);
}

int			is_max(t_list_ck *lst)
{
	int			max;
	t_list_ck	*tmp;

	tmp = lst;
	max = tmp->rk;
	while (tmp && tmp->next)
	{
		if (max < tmp->next->rk)
			max = tmp->next->rk;
		tmp = tmp->next;
	}
	return (max);
}

int			is_low(t_list_ck *lst)
{
	int			low;
	t_list_ck	*tmp;

	tmp = lst;
	low = tmp->rk;
	while (tmp && tmp->next)
	{
		if (low > tmp->next->rk)
			low = tmp->next->rk;
		tmp = tmp->next;
	}
	return (low);
}

t_list_ck	*find_minres(t_ps *env)
{
	t_list_ck *tmp;
	t_list_ck *tmp2;

	tmp = env->lst_a;
	tmp2 = env->lst_a->next;
	if (!tmp2)
		return (tmp);
	while (tmp)
	{
		if (tmp->res < tmp2->res)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	return (tmp2);
}
