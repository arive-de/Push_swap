/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:42:03 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/07 18:06:37 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_r_rr(t_ps *env)
{
	t_list_ck *tmp;

	tmp = env->lst_a;
	while (tmp)
	{
		tmp->ra = 0;
		tmp->rra = 0;
		tmp->rb = 0;
		tmp->rrb = 0;
		tmp = tmp->next;
	}
}

void	init_move(t_ps *env)
{
	init_r_rr(env);
	position(env->lst_a);
	position(env->lst_b);
	distance_max(env);
	distance_min(env);
	nb_move(env);
}
