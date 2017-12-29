/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:53:27 by arive-de          #+#    #+#             */
/*   Updated: 2017/05/11 11:58:34 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
	}
}

void	move_rrr(t_ps *env)
{
	move_rra(env);
	move_rrb(env);
}
