/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 19:12:54 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/08 11:46:36 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	move_ss(t_ps *env)
{
	move_sa(env);
	move_sb(env);
}

void	move_sa(t_ps *env)
{
	int tmp;

	if (env->lst_a && env->lst_a->next)
	{
		tmp = env->lst_a->nb;
		env->lst_a->nb = env->lst_a->next->nb;
		env->lst_a->next->nb = tmp;
	}
}

void	move_sb(t_ps *env)
{
	int tmp;

	if (env->lst_b && env->lst_b->next)
	{
		tmp = env->lst_b->nb;
		env->lst_b->nb = env->lst_b->next->nb;
		env->lst_b->next->nb = tmp;
	}
}

void	move_pa(t_ps *env)
{
	t_list_ck *tmp;
	t_list_ck *tmp2;

	tmp2 = env->lst_a;
	if (env->lst_b)
	{
		tmp = env->lst_b;
		env->lst_b = tmp->next;
		env->lst_a = tmp;
		env->lst_a->next = tmp2;
	}
}

void	move_pb(t_ps *env)
{
	t_list_ck *tmp;
	t_list_ck *tmp2;

	tmp2 = env->lst_b;
	if (env->lst_a)
	{
		tmp = env->lst_a;
		env->lst_a = tmp->next;
		env->lst_b = tmp;
		env->lst_b->next = tmp2;
	}
}
