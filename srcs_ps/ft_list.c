/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:19:13 by arive-de          #+#    #+#             */
/*   Updated: 2017/11/14 17:23:39 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list_ck	*create_maillon_ck(int nb, int rk, int part)
{
	t_list_ck *maillon;

	maillon = (t_list_ck*)ft_memalloc(sizeof(t_list_ck));
	if (!maillon)
		return (NULL);
	maillon->nb = nb;
	maillon->rk = rk;
	maillon->part = part;
	maillon->next = NULL;
	return (maillon);
}

void		add_maillon_end(t_list_ck **begin_list, t_list_ck *data)
{
	t_list_ck *tmp;
	t_list_ck *tmp2;

	tmp = *begin_list;
	tmp2 = NULL;
	if (!(*begin_list))
		*begin_list = data;
	else
	{
		while (tmp)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		if (!tmp)
			tmp2->next = data;
		else
		{
			tmp2->next = data;
			data->next = tmp;
		}
	}
}

t_list_ck	*maillon_del(t_list_ck *lst)
{
	t_list_ck *tmp;

	if (lst)
	{
		tmp = lst->next;
		free(lst);
		return (tmp);
	}
	else
		return (NULL);
}

void		add_maillon_beg(t_list_ck **begin_list, t_list_ck *data)
{
	t_list_ck *tmp;

	if (!(*begin_list))
		*begin_list = data;
	else
	{
		tmp = data;
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
}
