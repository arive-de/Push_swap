/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 19:12:54 by arive-de          #+#    #+#             */
/*   Updated: 2017/12/22 19:31:49 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_ss(t_ps *env)
{
	move_sa(env);
	move_sb(env);
	ft_putendl("ss");
	env->nb_mv--;
	env->last_mv = 3;
}

void	move_sa(t_ps *env)
{
	int tmp;
	int tmp2;
	int tmp3;

	if (env->lst_a && env->lst_a->next)
	{
		tmp = env->lst_a->nb;
		tmp2 = env->lst_a->rk;
		tmp3 = env->lst_a->part;
		env->lst_a->nb = env->lst_a->next->nb;
		env->lst_a->rk = env->lst_a->next->rk;
		env->lst_a->part = env->lst_a->next->part;
		env->lst_a->next->nb = tmp;
		env->lst_a->next->rk = tmp2;
		env->lst_a->next->part = tmp3;
		ft_putendl("sa");
		env->nb_mv++;
		env->last_mv = 1;
	}
}

void	move_sb(t_ps *env)
{
	int tmp;
	int tmp2;
	int	tmp3;

	if (env->lst_b && env->lst_b->next)
	{
		tmp = env->lst_b->nb;
		tmp2 = env->lst_b->rk;
		tmp3 = env->lst_b->part;
		env->lst_b->nb = env->lst_b->next->nb;
		env->lst_b->rk = env->lst_b->next->rk;
		env->lst_b->part = env->lst_b->next->part;
		env->lst_b->next->nb = tmp;
		env->lst_b->next->rk = tmp2;
		env->lst_b->next->part = tmp3;
		ft_putendl("sb");
		env->nb_mv++;
		env->last_mv = 2;
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
		ft_putendl("pa");
		env->nb_mv++;
		env->last_mv = 4;
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
		ft_putendl("pb");
		env->nb_mv++;
		env->last_mv = 5;
	}
}
