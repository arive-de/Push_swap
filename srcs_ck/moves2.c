/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:54:04 by arive-de          #+#    #+#             */
/*   Updated: 2017/05/11 12:36:56 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
	}
}

void	move_rr(t_ps *env)
{
	move_ra(env);
	move_rb(env);
}
